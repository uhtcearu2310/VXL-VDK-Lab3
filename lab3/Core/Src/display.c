#include"display.h"
int enabled_7SEG = EN0;

void display7SEG1(int num)
{
	if(num < 0 || num > 9) return;
	if(num == 1 || num == 4) pinWrite(T0_GPIO_Port, T0_Pin, GPIO_PIN_SET);
	else pinWrite(T0_GPIO_Port, T0_Pin, GPIO_PIN_RESET);
	if(num == 5 || num == 6) pinWrite(T1_GPIO_Port, T1_Pin, GPIO_PIN_SET);
	else pinWrite(T1_GPIO_Port, T1_Pin, GPIO_PIN_RESET);
	if(num == 2) pinWrite(T2_GPIO_Port, T2_Pin, GPIO_PIN_SET);
	else pinWrite(T2_GPIO_Port, T2_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 4 || num == 7) pinWrite(T3_GPIO_Port, T3_Pin, GPIO_PIN_SET);
	else pinWrite(T3_GPIO_Port, T3_Pin, GPIO_PIN_RESET);
	if(num % 2 == 1 || num == 4) pinWrite(T4_GPIO_Port, T4_Pin, GPIO_PIN_SET);
	else pinWrite(T4_GPIO_Port, T4_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 2 || num == 3 || num == 7) pinWrite(T5_GPIO_Port, T5_Pin, GPIO_PIN_SET);
	else pinWrite(T5_GPIO_Port, T5_Pin, GPIO_PIN_RESET);
	if(num == 0 || num == 1 || num == 7) pinWrite(T6_GPIO_Port, T6_Pin, GPIO_PIN_SET);
	else pinWrite(T6_GPIO_Port, T6_Pin, GPIO_PIN_RESET);
}

void display7SEG2(int num)
{
	if(num < 0 || num > 9) return;
	if(num == 1 || num == 4) pinWrite(P0_GPIO_Port, P0_Pin, GPIO_PIN_SET);
	else pinWrite(P0_GPIO_Port, P0_Pin, GPIO_PIN_RESET);
	if(num == 5 || num == 6) pinWrite(P1_GPIO_Port, P1_Pin, GPIO_PIN_SET);
	else pinWrite(P1_GPIO_Port, P1_Pin, GPIO_PIN_RESET);
	if(num == 2) pinWrite(P2_GPIO_Port, P2_Pin, GPIO_PIN_SET);
	else pinWrite(P2_GPIO_Port, P2_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 4 || num == 7) pinWrite(P3_GPIO_Port, P3_Pin, GPIO_PIN_SET);
	else pinWrite(P3_GPIO_Port, P3_Pin, GPIO_PIN_RESET);
	if(num % 2 == 1 || num == 4) pinWrite(P4_GPIO_Port, P4_Pin, GPIO_PIN_SET);
	else pinWrite(P4_GPIO_Port, P4_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 2 || num == 3 || num == 7) pinWrite(P5_GPIO_Port, P5_Pin, GPIO_PIN_SET);
	else pinWrite(P5_GPIO_Port, P5_Pin, GPIO_PIN_RESET);
	if(num == 0 || num == 1 || num == 7) pinWrite(P6_GPIO_Port, P6_Pin, GPIO_PIN_SET);
	else pinWrite(P6_GPIO_Port, P6_Pin, GPIO_PIN_RESET);
}

void display_7SEG_automatic()
{
	switch(enabled_7SEG)
	{
	case EN0:
		pinWrite(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		pinWrite(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		display7SEG1(countdown1 / 10);
		display7SEG2(countdown1 % 10);
		if(timer3_flag == 1)
		{
			setTimer3(SCAN_TIME);
			enabled_7SEG = EN1;

		}
		break;
	case EN1:

		pinWrite(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		pinWrite(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		display7SEG1(countdown2 / 10);
		display7SEG2(countdown2 % 10);
		if(timer3_flag == 1)
		{
			setTimer3(SCAN_TIME);
			enabled_7SEG = EN0;
		}
		break;
	default:
		break;
	}
}
void display_7SEG_manual()
{
	switch(enabled_7SEG)
	{
	case EN0:
		pinWrite(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		pinWrite(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		display7SEG1(0);
		display7SEG2(mode);
		if(timer3_flag == 1)
		{
			setTimer3(SCAN_TIME);
			enabled_7SEG = EN1;
		}
		break;
	case EN1:
		pinWrite(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		pinWrite(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);

		display7SEG1(led_buf[1]);
		display7SEG2(led_buf[0]);
		if(timer3_flag == 1)
		{
			setTimer3(SCAN_TIME);
			enabled_7SEG = EN0;
		}
		break;

	}
}


