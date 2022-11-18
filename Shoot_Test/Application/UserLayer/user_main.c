#include "stm32f4xx_hal.h"
#include "tim.h"

#include "user_main.h"
#include "launcher.h"

/*	
	��������
*/
int16_t send_buff[4];
float tar;



/**
 *	@brief	�û�Ӧ�ò�
 */
 void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
 {
	 if (htim->Instance == TIM4)
	 {
		 static uint16_t i = 0;
		 
		 if (++i == 60000)
		 {
			 i = 0;
		 }
		 
		//��������������ж��Ƿ�ʧ��
		motor[FRIC_R].heartbeat(&motor[FRIC_R]);
		motor[FRIC_L].heartbeat(&motor[FRIC_L]);
		motor[DIAL].heartbeat(&motor[DIAL]);
		rc_sensor.heart_beat(&rc_sensor);
		 
		if (launcher.info->rc_work_state == DEV_ONLINE)
		{
			launcher.ctrl();
		}
		else
		{
			launcher.self_protect();
		}
	 }
 }

//void StartControlTask(void const * argument)
//{
//	
//	//�����ʼ��
//	motor[GIMB_Y].init(&motor[GIMB_Y]);
//	//����ٶ�pid��ʼ��
//	motor[GIMB_Y].pid_init(&motor[GIMB_Y].pid.speed,gimb_y_speed_pid_param);
//	
//  for(;;)
//  {
//		//��������������ж��Ƿ�ʧ��
//		motor[GIMB_Y].heartbeat(&motor[GIMB_Y]);

////		//pid����
//		send_buff[motor[GIMB_Y].id.buff_p] = motor[GIMB_Y].c_speed(&motor[GIMB_Y],tar);


////		//�������ݵķ���
//		CAN1_Send_With_int16_to_uint8(motor[GIMB_Y].id.tx_id,send_buff);
////		
////		
//		
//		
//    osDelay(1);
//  }

//}



