#include "button.h"

/*
 * Doc nut nhan (active-low: nhan = 0, nha = 1), PA3/PA4/PA5
 *
 * - Ngat EXTI canh xuong: bat cu nhan ngay lap tuc, ke ca nhan rat ngan,
 *   khong can doc chan lien tuc (giam tai cho Proteus).
 * - getKeyInput() goi moi 10ms trong ngat TIM2:
 *     + du phong: neu EXTI bi lo thi van bat duoc nut dang nhan
 *     + chong doi: nut phai nha on dinh >= 20ms moi nhan lan tiep theo
 *     + giu nut 1s -> tu dong lap lai
 */

#define RELEASE_STABLE_TICKS	2		/* 2 x 10ms = 20ms */
#define LONG_PRESS_TICKS		100		/* 100 x 10ms = 1s */

static GPIO_TypeDef * const BTN_PORT[3] = {BTN1_GPIO_Port, BTN2_GPIO_Port, BTN3_GPIO_Port};
static const uint16_t       BTN_PIN[3]  = {BTN1_Pin,       BTN2_Pin,       BTN3_Pin};

static volatile int releaseTicks[3] = {RELEASE_STABLE_TICKS, RELEASE_STABLE_TICKS, RELEASE_STABLE_TICKS};
static volatile int holdTicks[3]    = {0, 0, 0};
static volatile int isHeld[3]       = {0, 0, 0};

volatile int button1_flag = 0;
volatile int button2_flag = 0;
volatile int button3_flag = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

static void subKeyProcess(int i){
	if(i == 0)      button1_flag = 1;
	else if(i == 1) button2_flag = 1;
	else if(i == 2) button3_flag = 1;
}

/* Ghi nhan 1 lan nhan moi (goi trong ngat EXTI hoac TIM2, cung muc uu tien) */
static void registerPress(int i){
	if(!isHeld[i] && releaseTicks[i] >= RELEASE_STABLE_TICKS){
		isHeld[i] = 1;
		holdTicks[i] = 0;
		releaseTicks[i] = 0;
		subKeyProcess(i);
	}
}

/* Cau hinh PA3/PA4/PA5: input pull-up + ngat canh xuong */
void buttonInit(){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	__HAL_RCC_AFIO_CLK_ENABLE();
	GPIO_InitStruct.Pin  = BTN1_Pin | BTN2_Pin | BTN3_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(BTN1_GPIO_Port, &GPIO_InitStruct);

	/* Cung muc uu tien voi TIM2 (0) -> khong ngat long nhau */
	HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI3_IRQn);
	HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void EXTI3_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(BTN1_Pin);
}
void EXTI4_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(BTN2_Pin);
}
void EXTI9_5_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(BTN3_Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	for(int i = 0; i < 3; i++){
		if(GPIO_Pin == BTN_PIN[i]){
			registerPress(i);
		}
	}
}

/* Goi moi 10ms trong ngat TIM2 */
void getKeyInput(){
	for(int i = 0; i < 3; i++){
		if(HAL_GPIO_ReadPin(BTN_PORT[i], BTN_PIN[i]) == PRESSED_STATE){
			if(!isHeld[i]){
				registerPress(i);		/* du phong neu EXTI bi lo */
			}else{
				releaseTicks[i] = 0;
				holdTicks[i]++;
				if(holdTicks[i] >= LONG_PRESS_TICKS){	/* giu 1s -> lap lai */
					holdTicks[i] = 0;
					subKeyProcess(i);
				}
			}
		}else{
			if(releaseTicks[i] < RELEASE_STABLE_TICKS){
				releaseTicks[i]++;
			}
			if(releaseTicks[i] >= RELEASE_STABLE_TICKS){
				isHeld[i] = 0;
				holdTicks[i] = 0;
			}
		}
	}
}
