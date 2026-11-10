#include "fsm_manual.h"
uint8_t least_green_time, least_red_time, least_yellow_time;

/* Xoa co cua cac nut con sot lai (nhan o mode truoc) */
static void clearButtonFlags(void){
	button1_flag = 0;
	button2_flag = 0;
	button3_flag = 0;
}

void fsm_manual_run(){
	switch(mode)
		  {
		  case 1:
			  fsm_automatic_run();
			  display_7SEG_automatic();
			  if(isButton1Pressed()==1){
				clearButtonFlags();
				setTimer2(500);
				mode = 2;
				count = timer_red / 1000;      // bat dau tu gia tri hien tai (giay)
				start();
				setTimer3(SCAN_TIME);
			  }
			  break;
		  case 2:
			  if(timer2_flag == 1){
				  setTimer2(500);
				  HAL_GPIO_TogglePin(R1_GPIO_Port,R1_Pin);
				  HAL_GPIO_TogglePin(R2_GPIO_Port,R2_Pin);
			  }
			  if(isButton2Pressed() == 1){
				  count++;
				  if (count > 99) { count = 1; }
			  }
			  if(isButton3Pressed() == 1){
				  timer_red = count * 1000;
			  }
			  led_buf[0] = count % 10;
			  led_buf[1] = count / 10;
			  display_7SEG_manual();
			  if(isButton1Pressed()==1){
				  clearButtonFlags();
				  setTimer2(500);
				  mode = 3;
				  count = timer_yellow / 1000;
				  pinWrite(R1_GPIO_Port,R1_Pin,1);
				  pinWrite(R2_GPIO_Port,R2_Pin,1);
			  }
			  break;
		  case 3:
			  if(timer2_flag == 1){
				  setTimer2(500);
				  HAL_GPIO_TogglePin(Y1_GPIO_Port,Y1_Pin);
				  HAL_GPIO_TogglePin(Y2_GPIO_Port,Y2_Pin);
			  }
			  if(isButton2Pressed() == 1){
				  count++;
				  if (count > 99) { count = 1; }
			  }
			  if(isButton3Pressed() == 1){
				  timer_yellow = count * 1000;
			  }
			  led_buf[0] = count % 10;
			  led_buf[1] = count / 10;
			  display_7SEG_manual();
			  if(isButton1Pressed() == 1){
				  clearButtonFlags();
				  setTimer2(500);
				  mode = 4;
				  count = timer_green / 1000;
				  pinWrite(Y1_GPIO_Port,Y1_Pin,1);
				  pinWrite(Y2_GPIO_Port,Y2_Pin,1);
			  }
			  break;
		  case 4:
			  if(timer2_flag == 1){
				  setTimer2(500);
				  HAL_GPIO_TogglePin(G1_GPIO_Port,G1_Pin);
				  HAL_GPIO_TogglePin(G2_GPIO_Port,G2_Pin);
			  }
			  if(isButton2Pressed() == 1){
				  count++;
				  if (count > 99) { count = 1; }
			  }
			  if(isButton3Pressed() == 1){
				  timer_green = count * 1000;
			  }
			  led_buf[0] = count % 10;
			  led_buf[1] = count / 10;
			  display_7SEG_manual();
			  if(isButton1Pressed() == 1){
				  clearButtonFlags();
				  /* Dam bao chu ky hop le: do = xanh + vang */
				  if(timer_red != timer_green + timer_yellow){
					  timer_red = timer_green + timer_yellow;
				  }
				  mode = 1;
				  status1 = INIT;
				  status2 = INIT;
				  pinWrite(G1_GPIO_Port,G1_Pin,1);
				  pinWrite(G2_GPIO_Port,G2_Pin,1);
			  }
			  break;
		  default:
			  mode = 1;
			  break;
		  }
}
