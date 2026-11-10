#include"global.h"

int count=0;
int mode=1;
int countdown1 = 0;
int countdown2 = 0;
int status1 = INIT;
int status2 = INIT;
int timer_red = 5000;
int timer_yellow = 2000;
int timer_green = 3000;
int led_buf[2] = {0};


void start()
{
	pinWrite(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
	pinWrite(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
	pinWrite(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
	pinWrite(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	pinWrite(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
	pinWrite(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
}

/* Chi ghi khi trang thai chan thuc su thay doi: tranh tao hang ngan su kien
   GPIO/giay khien Proteus phai giai lai mach analog (LED, transistor) */
void pinWrite(GPIO_TypeDef *port, uint16_t pin, int state)
{
	int current = ((port->ODR & pin) != 0);
	int target  = (state != 0);
	if(current != target){
		HAL_GPIO_WritePin(port, pin, target ? GPIO_PIN_SET : GPIO_PIN_RESET);
	}
}
