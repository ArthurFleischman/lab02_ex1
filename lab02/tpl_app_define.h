/**
 * @file tpl_app_define.h
 *
 * @section desc File description
 *
 * Header of the automatic generated defines usable
 * by the application test
 * Automatically generated by goil on Wed Nov 15 23:01:33 2023
 * from root OIL file lab02.oil
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2010
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_APP_DEFINE_H
#define TPL_APP_DEFINE_H



#include "tpl_config_def.h"

/*=============================================================================
 * Configuration flags
 */
#define TARGET_ARCH                      "avr"
#define TARGET_CHIP                      "arduino"
#define TARGET_BOARD                     "uno"
#define NUMBER_OF_CORES                  1
#define WITH_OS_EXTENDED                 NO
#define WITH_ORTI                        NO
#define WITH_PAINT_STACK                 NO
#define WITH_PAINT_REGISTERS             NO
#define WITH_STARTUP_HOOK                NO
#define WITH_SHUTDOWN_HOOK               NO
#define WITH_ERROR_HOOK                  NO
#define WITH_PRE_TASK_HOOK               NO
#define WITH_POST_TASK_HOOK              NO
#define WITH_ANY_HOOK                    NO
#define WITH_PANIC_HOOK                  NO
#define WITH_USEGETSERVICEID             NO
#define WITH_USEPARAMETERACCESS          NO
#define WITH_USERESSCHEDULER             YES
#define WITH_SYSTEM_CALL                 YES
#define WITH_MEMORY_PROTECTION           NO
#define WITH_MEMMAP                      NO
#define WITH_COMPILER_SETTINGS           NO
#define WITH_AUTOSAR                     NO
#define WITH_PROTECTION_HOOK             NO
#define WITH_STACK_MONITORING            NO
#define WITH_AUTOSAR_TIMING_PROTECTION   NO
#define AUTOSAR_SC                       0
#define WITH_OSAPPLICATION               NO
#define WITH_OSAPPLICATION_STARTUP_HOOK  NO
#define WITH_OSAPPLICATION_SHUTDOWN_HOOK NO
#define WITH_TRACE                       NO
#define WITH_ID                          NO
#define WITH_IT_TABLE                    NO
#define WITH_COM                         YES
#define TPL_COMTIMEBASE                  0.001
#define WITH_COM_ERROR_HOOK              NO
#define WITH_COM_USEGETSERVICEID         NO
#define WITH_COM_USEPARAMETERACCESS      NO
#define WITH_COM_STARTCOMEXTENSION       NO
#define WITH_COM_EXTENDED                NO
#define WITH_IOC                         NO
#define WITH_MODULES_INIT                NO
#define WITH_INIT_BOARD                  NO
#define WITH_ISR2_PRIORITY_MASKING       NO

/*=============================================================================
 * Defines related to the key part of a ready list entry.
 * The key part has in the most significant bits the priority of the job and
 * in the least significant bits the rank of the job. So:
 * - PRIORITY_SHIFT is the number of bit the key has to be shifted to the
 *   right) to get the priority only aligned to the right;
 * - PRIORITY_MASK is the mask to get the priority only (not aligned to the
 *   right with the rank set to 0;
 * - RANK_MASK is the mask to get only the rank.
 */
#define PRIORITY_SHIFT                   2
#define PRIORITY_MASK                    12
#define RANK_MASK                        3

/*=============================================================================
 * Number of objects used by the application
 * These informations are used by Trampoline to avoid to
 * alloc structures when some os objects are not present.
 */

/*-----------------------------------------------------------------------------
 * Number of priority levels
 */
#define PRIO_LEVEL_COUNT       3

/*-----------------------------------------------------------------------------
 * Number of tasks
 */
#define TASK_COUNT             3

/*-----------------------------------------------------------------------------
 * Number of spinlocks
 */
#define SPINLOCK_COUNT         0

/*-----------------------------------------------------------------------------
 * Number of extended tasks
 */
#define EXTENDED_TASK_COUNT    0

/*-----------------------------------------------------------------------------
 * Number of ISR2
 */
#define ISR_COUNT              0

/*-----------------------------------------------------------------------------
 * Number of alarms
 */
#define ALARM_COUNT            3

/*-----------------------------------------------------------------------------
 * Number of regular resources (standard and linked) plus RES_SCHEDULER if used 
 */
#define RESOURCE_COUNT         1 

/*-----------------------------------------------------------------------------
 * Number of events
 */
#define EVENT_COUNT            0

/*-----------------------------------------------------------------------------
 * Number of messages
 */
#define MESSAGE_COUNT          4

/*-----------------------------------------------------------------------------
 * Number of send messages
 */
#define SEND_MESSAGE_COUNT     2

/*-----------------------------------------------------------------------------
 * Number of receive messages
 */
#define RECEIVE_MESSAGE_COUNT  2

/*-----------------------------------------------------------------------------
 * Number of counters
 */
#define COUNTER_COUNT          1

/*-----------------------------------------------------------------------------
 * Number of schedule tables
 */
#define SCHEDTABLE_COUNT       0

/*-----------------------------------------------------------------------------
 * Number of OS Applications
 */
#define APP_COUNT              0

/*-----------------------------------------------------------------------------
 * Number of trusted functions
 */
#define TRUSTED_FCT_COUNT      0

/*-----------------------------------------------------------------------------
 * Number of IOC
 */
#define IOC_COUNT 0
#define IOC_QUEUED_COUNT 0
#define IOC_UNQUEUED_COUNT 0


/*-----------------------------------------------------------------------------
 * Priority of RES_SCHEDULER
 */
#define RES_SCHEDULER_PRIORITY 3

#define IDLE_TASK_ID    TASK_COUNT + ISR_COUNT

/*-----------------------------------------------------------------------------
 * To fasten the SPINLOCK_IS_SUCCESSOR macro
 */
#define SPINLOCK_SUCCESSOR_BITFIELD_SHIFT 4
#define SPINLOCK_SUCCESSOR_BITFIELD_MASK  7

/*-----------------------------------------------------------------------------
 * Spinlocks max possessed spinlocks per core.
 * This definition is used to maximize the size of possessed spinlocks.
 * In OSExtended mode, as we're checking nesting spinlocks, we can set the max
 * size of the LIFOS to the longest chain in the spinlocks graph.
 * In OSStandard mode, we set the maximum to the number of spinlocks (a
 * spinlock can only be taken once).
 */
#define MAX_POSSESSED_SPINLOCKS 0

/*-----------------------------------------------------------------------------
 * Debugging
 */
#define WITH_DEBUG             NO

#include "tpl_config_check.h"

#endif

/*-----------------------------------------------------------------------------
 * Configuration STM Flags
 */
#define NUMBER_OF_OBJECTS                 0
#define NUMBER_OF_TRANSACTIONS            0

/*-----------------------------------------------------------------------------
 *  Tick optimization
 */
#define TPL_OPTIMIZE_TICKS NO

/* End of file TPL_APP_DEFINE_H */

