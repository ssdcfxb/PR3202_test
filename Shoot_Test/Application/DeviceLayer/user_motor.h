/**
 * @file        user_motor.c/.h
 * @author      SSDCFXB
 * @Version     V1.0
 * @date        18-November-2022
 * @brief       User Motor Devives
 * @update
 */

#ifndef __USER_MOTOR_H
#define __USER_MOTOR_H

/* Includes ------------------------------------------------------------------*/
#include "motor.h"

/* Exported macro ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef enum
{
	FRIC_R = 0,
	FRIC_L,
	DIAL,
	
	MOTOR_LIST,
}motor_list_e;

extern motor_t motor[MOTOR_LIST];

/* Exported functions --------------------------------------------------------*/
void motor_all_init(void);


#endif

