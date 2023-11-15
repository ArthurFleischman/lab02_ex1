// see blink.oil head of file for information about the compilation process.

#include "tpl_os.h"
#include "Arduino.h"
#include "math.h"
#define BTN_TIME 10
enum LED_MSG{ALL_OFF, BLINK_FAST, BLINK_SLOW, ALL_ON};

int concatNumbers(int num1, int num2) {
    return (num1 << 11) | (num2 << 0);

}
int decodeDigitalState(int code) {
    /*
       shifts right all the number until only the digital state remains
       */
    return (code >> 11);
}
int decodeAnalogState(int code){
    /*
       use the inverted state of the eleventh bit in a bitwise and operation
       to eliminate the value of digital signal from the code
       */
    return code &= (~(decodeDigitalState(code)) << 11);
}

void setup()
{
    Serial.begin(9600);
    Serial.print("ok\n");
    pinMode(13, OUTPUT);
    pinMode(12, INPUT_PULLUP);
}

TASK(Task_M)
{

    int msg = ALL_ON;
    static int analogRefValue= 0;
    static bool has_ref = false;
    if(ReceiveMessage(M_receive, &msg) == E_OK){
        Serial.print("message received\n");
        int analogValue = decodeAnalogState(msg);
        int digitalValue = decodeDigitalState(msg);
        if(digitalValue){
            has_ref = true;
            analogRefValue = analogValue;
        }
        if(!has_ref){
            msg = ALL_ON;
        }
        else{
            int diff = abs(analogValue - analogRefValue);
            if(diff < 100)
                msg = ALL_OFF;
            else if(diff >= 100 && diff < 200)
                msg = BLINK_SLOW;
            else if(diff >= 200)
                msg = BLINK_FAST;
        }
        SendMessage(msgfrom_M, &msg);
    }
    TerminateTask();
}
TASK(Task_V)
{

    static int counter = 0;
    static bool led_state = false;
    int msg = BLINK_SLOW;
    ReceiveMessage(V_receive, &msg);
    switch(msg){
        case ALL_OFF:
            digitalWrite(13, LOW);
            break;
            // 1 state change per second, counter == 4 -> led change state`
        case BLINK_FAST:
            led_state = !led_state;
            digitalWrite(13, led_state);
            break;
            // 1 state change every 1/4 seconds, counter == 1 -> led change state;
        case BLINK_SLOW:
            if(counter >= 4){
                led_state = !led_state;
                digitalWrite(13, led_state);
                counter = 0;
            }
            break;
        case ALL_ON:
            digitalWrite(13, HIGH);
            break;
    }

    Serial.print("counter from V: ");
    Serial.println(counter);
    counter++;
    TerminateTask();
}

TASK(Periodic_Task_C)
{
    static int btn_counter = 0;
    int concatResult = 0;
    int analogValue = analogRead(0);
    int digitalValue = !digitalRead(12);
    if(digitalValue){
        btn_counter++;
        if(btn_counter >= BTN_TIME){
            concatResult = concatNumbers(digitalValue, analogValue);
            btn_counter = 0;
        }
    }
    else{
        btn_counter = 0;
        concatResult = concatNumbers(0, analogValue);
    }
    SendMessage(msgfrom_C, &concatResult);
    TerminateTask();
}

