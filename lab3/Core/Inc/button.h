#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
extern volatile int button1_flag;
extern volatile int button2_flag;
extern volatile int button3_flag;
void getKeyInput();
void buttonInit();
int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

#endif /* INC_BUTTON_H_ */
