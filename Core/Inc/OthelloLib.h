/*
 * OthelloLib.h
 *
 *  Created on: Jan 31, 2022
 *      Author: Julius Andreas
 */

/* include files */
#include "main.h"
#include "LiquidCrystal.h"
#include "stm32f3xx_it.h"

#ifndef INC_OTHELLOLIB_H_
#define INC_OTHELLOLIB_H_

/* externs */

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern int board[8][8];
extern int turn;
extern int remaining_time;
extern int time_limit;
extern UART_HandleTypeDef huart3;
extern int frequency;

/* global variables */

const unsigned char black_win_message[23];
const unsigned char white_win_message[23];
const unsigned char tie_message[16];

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
int switch_turns();
int col_letter_to_num(char letter);
int row_char_to_num(char row_num_char);
void game_over();
int board_is_full();
void forced_game_over(int turn);

#endif /* INC_OTHELLOLIB_H_ */
