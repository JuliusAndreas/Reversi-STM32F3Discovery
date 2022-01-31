/*
 * Author: Soroosh Faal
 *
 * This is the implementation file for functions used in application.
 */


#include "OthelloLib.h"

void enable_7_seg(int num){
	switch (num){
		case 1:
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0);
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0);
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 1);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0);
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 1);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0);
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 1);
			break;
	}
}

void show_number(int number){
	if(number == 0){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6 | GPIO_PIN_8 | GPIO_PIN_7 | GPIO_PIN_9, 0);

	}else if(number == 1){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_9, 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);

	}else if(number == 2){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8 | GPIO_PIN_7 | GPIO_PIN_9, 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);

	}else if(number == 3){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7 | GPIO_PIN_9, 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6 | GPIO_PIN_8, 1);

	}else if(number == 4){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8 | GPIO_PIN_6 | GPIO_PIN_9, 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);

	}else if(number == 5){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6 | GPIO_PIN_9, 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8 | GPIO_PIN_7, 1);

	}else if(number == 6){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8 | GPIO_PIN_9, 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6 | GPIO_PIN_7, 1);

	}else if(number == 7){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8, 1);

	}else if(number == 8){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8 | GPIO_PIN_7 | GPIO_PIN_6 , 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);

	}else if(number == 9){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6 | GPIO_PIN_7, 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9 | GPIO_PIN_8, 1);
	}

}

void init_map(int board[8][8]){

	setCursor(7, 0);
	print("        ");
	setCursor(7, 1);
	print("   ");
	write(6);
	write(2);
	print("   ");
	setCursor(7, 2);
	print("   ");
	write(1);
	write(5);
	print("   ");
	setCursor(7, 3);
	print("        ");
	setCursor(4, 3);
	print("D4");
	setCursor(1, 0);
	print("B");
}

int isValid(int row, int col, int turn){
	int capturables = 0;
	int i;
	if(board[row][col] != 0){
		return 0;
	}

	if(turn==1){
		//horizontally checking

		i = 1;
		while(((col-i)>=0) && (board[row][col-i]==2)){
			i++;
		}
		if(((col-i)>=0) && (board[row][col-i]==1)){
			capturables += i-1;
		}
		i = 1;
		while(((col+i)<8) && (board[row][col+i]==2)){
			i++;
		}
		if(((col+i)<8) && (board[row][col+i]==1)){
			capturables += i-1;
		}
		//vertically checking

		i = 1;
		while(((row-i)>=0) && (board[row-i][col]==2)){
			i++;
		}
		if(((row-i)>=0) && (board[row-i][col]==1)){
			capturables += i-1;
		}
		i = 1;
		while(((row+i)<8) && (board[row+i][col]==2)){
			i++;
		}
		if(((row+i)<8) && (board[row+i][col]==1)){
			capturables += i-1;
		}
		//diagonally checking

		i = 1;
		while(((row-i)>=0) && ((col-i)>=0) && (board[row-i][col-i]==2)){
			i++;
		}
		if(((row-i)>=0) && ((col-i)>=0) && (board[row-i][col-i]==1)){
			capturables += i-1;
		}

		i = 1;
		while(((row+i)<8) && ((col+i)<8) && (board[row+i][col+i]==2)){
			i++;
		}
		if(((row+i)<8) && ((col+i)<8) && (board[row+i][col+i]==1)){
			capturables += i-1;
		}

		i = 1;
		while(((row-i)>=0) && ((col+i)<8) && (board[row-i][col+i]==2)){
			i++;
		}
		if(((row-i)>=0) && ((col+i)<8) && (board[row-i][col+i]==1)){
			capturables += i-1;
		}

		i = 1;
		while(((row+i)<8) && ((col-i)>=0) && (board[row+i][col-i]==2)){
			i++;
		}
		if(((row+i)<8) && ((col-i)>=0) && (board[row+i][col-i]==1)){
			capturables += i-1;
		}

		if(capturables==0){
			return 0;
		}else{
			return 1;
		}

	}else if(turn==2){

		//horizontally checking

		i = 1;
		while(((col-i)>=0) && (board[row][col-i]==1)){
			i++;
		}
		if(((col-i)>=0) && (board[row][col-i]==2)){
			capturables += i-1;
		}
		i = 1;
		while(((col+i)<8) && (board[row][col+i]==1)){
			i++;
		}
		if(((col+i)<8) && (board[row][col+i]==2)){
			capturables += i-1;
		}
		//vertically checking

		i = 1;
		while(((row-i)>=0) && (board[row-i][col]==1)){
			i++;
		}
		if(((row-i)>=0) && (board[row-i][col]==2)){
			capturables += i-1;
		}
		i = 1;
		while(((row+i)<8) && (board[row+i][col]==1)){
			i++;
		}
		if(((row+i)<8) && (board[row+i][col]==2)){
			capturables += i-1;
		}
		//diagonally checking

		i = 1;
		while(((row-i)>=0) && ((col-i)>=0) && (board[row-i][col-i]==1)){
			i++;
		}
		if(((row-i)>=0) && ((col-i)>=0) && (board[row-i][col-i]==2)){
			capturables += i-1;
		}

		i = 1;
		while(((row+i)<8) && ((col+i)<8) && (board[row+i][col+i]==1)){
			i++;
		}
		if(((row+i)<8) && ((col+i)<8) && (board[row+i][col+i]==2)){
			capturables += i-1;
		}

		i = 1;
		while(((row-i)>=0) && ((col+i)<8) && (board[row-i][col+i]==1)){
			i++;
		}
		if(((row-i)>=0) && ((col+i)<8) && (board[row-i][col+i]==2)){
			capturables += i-1;
		}

		i = 1;
		while(((row+i)<8) && ((col-i)>=0) && (board[row+i][col-i]==1)){
			i++;
		}
		if(((row+i)<8) && ((col-i)>=0) && (board[row+i][col-i]==2)){
			capturables += i-1;
		}

		if(capturables==0){
			return 0;
		}else{
			return 1;
		}

	}

}

void PWM_Change_Tone(uint16_t pwm_freq, uint16_t volume) // pwm_freq (1 - 20000), volume (0 - 1000)
{

  TIM_HandleTypeDef *pwm_timer = &htim1;
  if (pwm_freq == 0 || pwm_freq > 20000)
  {
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
  }
  else
  {
    const uint32_t internal_clock_freq = HAL_RCC_GetSysClockFreq();
    const uint16_t prescaler = 99;
    const uint32_t timer_clock = internal_clock_freq / prescaler;
    const uint32_t period_cycles = timer_clock / pwm_freq;
    const uint32_t pulse_width = volume * period_cycles / 1000 / 2;

    pwm_timer->Instance->PSC = prescaler - 1;
    pwm_timer->Instance->ARR = period_cycles - 1;
    pwm_timer->Instance->EGR = TIM_EGR_UG;
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, pulse_width); // pwm_timer->Instance->CCR2 = pulse_width;
  }
}

void turn_on_all_LEDS(){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, 1);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, 1);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, 1);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, 1);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, 1);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, 1);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, 1);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, 1);
}

void turn_off_all_LEDS(){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, 0);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, 0);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, 0);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, 0);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, 0);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, 0);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, 0);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, 0);
}

void illegal_move_alert(){
	turn_on_all_LEDS();
	HAL_Delay(300);
	turn_off_all_LEDS();
	HAL_Delay(300);
	turn_on_all_LEDS();
	HAL_Delay(300);
	turn_off_all_LEDS();
	HAL_Delay(300);
	turn_on_all_LEDS();
	HAL_Delay(300);
	turn_off_all_LEDS();
}

char col_num_to_letter(int num){
	switch(num){
		case 0:
			return 'A';
		case 1:
			return 'B';
		case 2:
			return 'C';
		case 3:
			return 'D';
		case 4:
			return 'E';
		case 5:
			return 'F';
		case 6:
			return 'G';
		case 7:
			return 'H';
	}
}

char row_num_to_char(int num){
	switch(num){
			case 0:
				return '1';
			case 1:
				return '2';
			case 2:
				return '3';
			case 3:
				return '4';
			case 4:
				return '5';
			case 5:
				return '6';
			case 6:
				return '7';
			case 7:
				return '8';
		}
}

void capture(int row, int col, int turn){

	int capturables = 0;
	int i;

	if(turn==1){
		//horizontally checking

		i = 1;
		while(((col-i)>=0) && (board[row][col-i]==2)){
			i++;
		}
		if(((col-i)>=0) && (board[row][col-i]==1)){
			board[row][col] = 1;
			for(int j=1;j<i;j++){
				board[row][col-j] = 1;
			}
		}
		i = 1;
		while(((col+i)<8) && (board[row][col+i]==2)){
			i++;
		}
		if(((col+i)<8) && (board[row][col+i]==1)){
			board[row][col] = 1;
			for(int j=1;j<i;j++){
				board[row][col+j] = 1;
			}
		}
		//vertically checking

		i = 1;
		while(((row-i)>=0) && (board[row-i][col]==2)){
			i++;
		}
		if(((row-i)>=0) && (board[row-i][col]==1)){
			board[row][col] = 1;
			for(int j=1;j<i;j++){
				board[row-j][col] = 1;
			}
		}
		i = 1;
		while(((row+i)<8) && (board[row+i][col]==2)){
			i++;
		}
		if(((row+i)<8) && (board[row+i][col]==1)){
			board[row][col] = 1;
			for(int j=1;j<i;j++){
				board[row+j][col] = 1;
			}
		}
		//diagonally checking

		i = 1;
		while(((row-i)>=0) && ((col-i)>=0) && (board[row-i][col-i]==2)){
			i++;
		}
		if(((row-i)>=0) && ((col-i)>=0) && (board[row-i][col-i]==1)){
			board[row][col] = 1;
			for(int j=1;j<i;j++){
				board[row-j][col-j] = 1;
			}
		}

		i = 1;
		while(((row+i)<8) && ((col+i)<8) && (board[row+i][col+i]==2)){
			i++;
		}
		if(((row+i)<8) && ((col+i)<8) && (board[row+i][col+i]==1)){
			board[row][col] = 1;
			for(int j=1;j<i;j++){
				board[row+j][col+j] = 1;
			}
		}

		i = 1;
		while(((row-i)>=0) && ((col+i)<8) && (board[row-i][col+i]==2)){
			i++;
		}
		if(((row-i)>=0) && ((col+i)<8) && (board[row-i][col+i]==1)){
			board[row][col] = 1;
			for(int j=1;j<i;j++){
				board[row-j][col+j] = 1;
			}
		}

		i = 1;
		while(((row+i)<8) && ((col-i)>=0) && (board[row+i][col-i]==2)){
			i++;
		}
		if(((row+i)<8) && ((col-i)>=0) && (board[row+i][col-i]==1)){
			board[row][col] = 1;
			for(int j=1;j<i;j++){
				board[row+j][col-j] = 1;
			}
		}


	}else if(turn==2){

		//horizontally checking

		i = 1;
		while(((col-i)>=0) && (board[row][col-i]==1)){
			i++;
		}
		if(((col-i)>=0) && (board[row][col-i]==2)){
			board[row][col] = 2;
			for(int j=1;j<i;j++){
				board[row][col-j] = 2;
			}
		}
		i = 1;
		while(((col+i)<8) && (board[row][col+i]==1)){
			i++;
		}
		if(((col+i)<8) && (board[row][col+i]==2)){
			board[row][col] = 2;
			for(int j=1;j<i;j++){
				board[row][col+j] = 2;
			}
		}
		//vertically checking

		i = 1;
		while(((row-i)>=0) && (board[row-i][col]==1)){
			i++;
		}
		if(((row-i)>=0) && (board[row-i][col]==2)){
			board[row][col] = 2;
			for(int j=1;j<i;j++){
				board[row-j][col] = 2;
			}
		}
		i = 1;
		while(((row+i)<8) && (board[row+i][col]==1)){
			i++;
		}
		if(((row+i)<8) && (board[row+i][col]==2)){
			board[row][col] = 2;
			for(int j=1;j<i;j++){
				board[row+j][col] = 2;
			}
		}
		//diagonally checking

		i = 1;
		while(((row-i)>=0) && ((col-i)>=0) && (board[row-i][col-i]==1)){
			i++;
		}
		if(((row-i)>=0) && ((col-i)>=0) && (board[row-i][col-i]==2)){
			board[row][col] = 2;
			for(int j=1;j<i;j++){
				board[row-j][col-j] = 2;
			}
		}

		i = 1;
		while(((row+i)<8) && ((col+i)<8) && (board[row+i][col+i]==1)){
			i++;
		}
		if(((row+i)<8) && ((col+i)<8) && (board[row+i][col+i]==2)){
			board[row][col] = 2;
			for(int j=1;j<i;j++){
				board[row+j][col+j] = 2;
			}
		}

		i = 1;
		while(((row-i)>=0) && ((col+i)<8) && (board[row-i][col+i]==1)){
			i++;
		}
		if(((row-i)>=0) && ((col+i)<8) && (board[row-i][col+i]==2)){
			board[row][col] = 2;
			for(int j=1;j<i;j++){
				board[row-j][col+j] = 2;
			}
		}

		i = 1;
		while(((row+i)<8) && ((col-i)>=0) && (board[row+i][col-i]==1)){
			i++;
		}
		if(((row+i)<8) && ((col-i)>=0) && (board[row+i][col-i]==2)){
			board[row][col] = 2;
			for(int j=1;j<i;j++){
				board[row+j][col-j] = 2;
			}
		}

	}

}

int canCapture(int turn){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(isValid(i, j, turn)){
				return 1;
			}
		}
	}
	return 0;

}

void print_board(){
	int row = 0;
	int col = 0;
	for(row=0;row<8;row+=2){
		for(col=0;col<8;col++){
			setCursor(col+7, row/2);
			if((board[row][col]==0) && (board[row+1][col]==0)){
				print(" ");
			}
			if((board[row][col]==0) && (board[row+1][col]==1)){
				write(6);
			}
			if((board[row][col]==1) && (board[row+1][col]==0)){
				write(5);
			}
			if((board[row][col]==1) && (board[row+1][col]==1)){
				write(7);
			}
			if((board[row][col]==2) && (board[row+1][col]==0)){
				write(1);
			}
			if((board[row][col]==0) && (board[row+1][col]==2)){
				write(2);
			}
			if((board[row][col]==2) && (board[row+1][col]==2)){
				write(0);
			}
			if((board[row][col]==1) && (board[row+1][col]==2)){
				write(3);
			}
			if((board[row][col]==2) && (board[row+1][col]==1)){
				write(4);
			}
		}
	}
}

void show_scores(){
	int black_score = 0;
	int white_score = 0;
	char b_score[5];
	char w_score[5];
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(board[i][j]==2){
				black_score++;
			}else if(board[i][j]==1){
				white_score++;
			}
		}
	}
	setCursor(1, 1);
	sprintf(b_score, "%d",black_score);
	print(b_score);
	setCursor(18, 1);
	sprintf(w_score, "%d",white_score);
	print(w_score);
}

void switch_turns(){
	if(turn==2){
		if(canCapture(1)){
			turn =1;
			setCursor(1, 0);
			print("W");
		}
	}else{
		if(canCapture(2)){
			turn =2;
			setCursor(1, 0);
			print("B");
		}
	}
}

int col_letter_to_num(char letter){

}

int row_char_to_num(char row_num_char){
	switch(row_num_char){
		case '1':
			return 0;
		case '2':
			return 1;
		case '3':
			return 2;
		case '4':
			return 3;
		case '5':
			return 4;
		case '6':
			return 5;
		case '7':
			return 6;
		case '8':
			return 7;
	}
}
