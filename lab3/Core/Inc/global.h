#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include"software_timer.h"
#include"button.h"
#include"main.h"
#include"display.h"
#include"fsm_automatic.h"
#include"fsm_manual.h"
#define INIT			1
#define AUTO_RED 		2
#define AUTO_GREEN 		3
#define AUTO_YELLOW 	4

extern int status1 ;
extern int status2;
extern int mode;
extern int timer_red;
extern int timer_yellow;
extern int timer_green;
extern int led_buf[2];


extern int count;

extern int countdown1;
extern int countdown2;
void start();
/* Ghi chan GPIO chi khi gia tri thay doi (giam tai mo phong Proteus) */
void pinWrite(GPIO_TypeDef *port, uint16_t pin, int state);
#endif /* INC_GLOBAL_H_ */
