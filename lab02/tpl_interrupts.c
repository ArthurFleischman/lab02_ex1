/**
 * @file tpl_interrupts.c
 *
 * @section desc File description
 *
 * External interrupts init and acknowledge functions for test
 * Automatically generated by goil on Wed Nov 15 23:01:33 2023
 * from root OIL file lab02.oil
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) LS2N 2005-2017
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence v2
 *
 ***
 *
 * External Interrupts initialization for the AVR-Arduino Microcontroller
 *
 * Inits are done according to the source(s) pin(s) selected for an interrupt
 * vector corresponding to an or a set of interrupt(s) line(s)
 *
 */
#include "tpl_machine.h"
#include "Arduino.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"


FUNC(void, OS_CODE) tpl_init_external_interrupts()
{
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_interrupts.c */

