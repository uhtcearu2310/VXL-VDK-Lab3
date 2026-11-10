#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern volatile int timer1_flag;
extern volatile int timer2_flag ;
extern volatile int timer3_flag ;
extern volatile int timer4_flag ;
extern volatile int timer5_flag ;
extern volatile int timer6_flag ;
extern int TICK;
void setTimer1(int );
void setTimer2(int );
void setTimer3(int );
void setTimer4(int );
void setTimer5(int );
void setTimer6(int );
void timerRun();
#endif /* INC_SOFTWARE_TIMER_H_ */
