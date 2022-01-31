/*
 * OthelloLib.h
 *
 *  Created on: Jan 31, 2022
 *      Author: Julius Andreas
 */

/* include files */
#include "main.h"
#include "LiquidCrystal.h"

#ifndef INC_OTHELLOLIB_H_
#define INC_OTHELLOLIB_H_

/* externs */

extern TIM_HandleTypeDef htim1;
extern int board[8][8];
extern int turn;

/* prototypes */

void enable_7_seg(int num);
void show_number(int number);
void init_map(int board[8][8]);
int isValid(int row, int col, int turn);
void PWM_Change_Tone(uint16_t pwm_freq, uint16_t volume);
void turn_on_all_LEDS();
void turn_off_all_LEDS();
void illegal_move_alert();
char col_num_to_letter(int num);
char row_num_to_char(int num);
void capture(int row, int col, int turn);
int canCapture(int turn);
void print_board();
void show_scores();
void switch_turns();
int col_letter_to_num(char letter);
int row_char_to_num(char row_num_char);

#endif /* INC_OTHELLOLIB_H_ */
