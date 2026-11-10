#include "fsm_automatic.h"


	void fsm_automatic_run(){
		switch(status1){
		case INIT:
			pinWrite(R1_GPIO_Port,R1_Pin,1);
			pinWrite(Y1_GPIO_Port,Y1_Pin,1);
			pinWrite(G1_GPIO_Port,G1_Pin,1);
			status1 = AUTO_RED;
			countdown1=timer_red/1000;
			setTimer5(1000);
			break;
		case AUTO_RED:
			if(timer5_flag==1)
			{
				countdown1--;
				setTimer5(1000);
				if(countdown1 ==0)
				{
					status1 = AUTO_GREEN;
					countdown1=timer_green/1000;
				}
			}
			pinWrite(R1_GPIO_Port,R1_Pin,0);
			pinWrite(Y1_GPIO_Port,Y1_Pin,1);
			pinWrite(G1_GPIO_Port,G1_Pin,1);

			break;

		case AUTO_GREEN:
			if(timer5_flag==1)
			{
				countdown1--;
				setTimer5(1000);
				if(countdown1 ==0)
				{
					status1 = AUTO_YELLOW;
					countdown1=timer_yellow/1000;
				}
			}
			pinWrite(R1_GPIO_Port,R1_Pin,1);
			pinWrite(Y1_GPIO_Port,Y1_Pin,1);
			pinWrite(G1_GPIO_Port,G1_Pin,0);
			break;
		case AUTO_YELLOW:
			if(timer5_flag==1)
			{
				countdown1--;
				setTimer5(1000);
				if(countdown1 ==0)
				{
					status1 = AUTO_RED;
					countdown1=timer_red/1000;
				}
			}
			pinWrite(R1_GPIO_Port,R1_Pin,1);
			pinWrite(Y1_GPIO_Port,Y1_Pin,0);
			pinWrite(G1_GPIO_Port,G1_Pin,1);
			break;
		default:
			break;
		}
		switch(status2){
		case INIT:
			pinWrite(R2_GPIO_Port,R2_Pin,1);
			pinWrite(Y2_GPIO_Port,Y2_Pin,1);
			pinWrite(G2_GPIO_Port,G2_Pin,1);
			status2 = AUTO_GREEN;
			countdown2=timer_green/1000;
			setTimer6(1000);
			break;
		case AUTO_GREEN:
			if(timer6_flag==1)
			{
				countdown2--;
				setTimer6(1000);
				if(countdown2 ==0)
				{
					status2 = AUTO_YELLOW;
					countdown2=timer_yellow/1000;
				}
			}
			pinWrite(R2_GPIO_Port,R2_Pin,1);
			pinWrite(Y2_GPIO_Port,Y2_Pin,1);
			pinWrite(G2_GPIO_Port,G2_Pin,0);
			break;
		case AUTO_YELLOW:
			if(timer6_flag==1)
			{
				countdown2--;
				setTimer6(1000);
				if(countdown2 ==0)
				{
					status2 = AUTO_RED;
					countdown2=timer_red/1000;
				}
			}
			pinWrite(R2_GPIO_Port,R2_Pin,1);
			pinWrite(Y2_GPIO_Port,Y2_Pin,0);
			pinWrite(G2_GPIO_Port,G2_Pin,1);
			break;
		case AUTO_RED:
			if(timer6_flag==1)
			{
				countdown2--;
				setTimer6(1000);
				if(countdown2 ==0)
				{
					status2 = AUTO_GREEN;
					countdown2=timer_green/1000;
				}
			}
			pinWrite(R2_GPIO_Port,R2_Pin,0);
			pinWrite(Y2_GPIO_Port,Y2_Pin,1);
			pinWrite(G2_GPIO_Port,G2_Pin,1);
			break;
		default:
			break;
		}
	}

