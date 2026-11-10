#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_
#include"global.h"
#define EN0	0
#define EN1	1
/* Thoi gian quet moi nhom LED 7 doan (ms) - phai la boi so cua TICK (10ms) */
#define SCAN_TIME	50



void display7SEG1();
void display7SEG2();
void display_7SEG_automatic();
void display_7SEG_manual();
#endif /* INC_DISPLAY_H_ */
