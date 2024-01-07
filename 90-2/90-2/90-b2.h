/* 2150248 信18 姚天亮*/
#pragma once

//90-b2-tools
int findmax(int larry[][10], int row, int column);
int rand_int(int max);
void neighbour_get_N(int larry[][10], int row, int column, int larry_get[][10], int x, int y, int neighbour);
void neighbour_get_Y(int larry[][10], int row, int column, int larry_get[][10], int x, int y, int neighbour);
int show_neighbour(int larry[][10], int row, int column, int larry_get[][10], int x, int y);
int judge_show(int larry[][10], int row, int column);
int judge_neighbour(int larry[][10], int row, int column, int x, int y);
int score(int neighbour, int sum);
void down(int larry[][10], int row, int column);
void set(int larry[][10], int row, int column);
void setmax(int larry[][10], int row, int column);
void game_ending(int column);

//90-b2-base
void print_larry(int larry[][10], int row, int column);
int put_together_and_show_score(int larry[][10], int row, int column, int larry_get[][10], int x, int y, int res, int target, int score_sum);
void print_removeZero(int larry[][10], int row, int column, int larry_get[][10]);
void print_result(int larry[][10], int row, int column, int larry_get[][10], int flag);
void chushihua(char sel);

//90-b2-console //需要大改
void initial_picture(char sel);
void print_blank(int card_y, int card_x, int value, bool Border, int bgcolor = -1, int fgcolor = -1);
void print_border(int row, int column, bool border);
void set_botton_line(bool set = false, int flag = 0);
void get_picture_size(int row, int column, bool haveBorder, int& width, int& heigh);
void card_fall_smooth(int card_x, int card_y, int value);
void move(int larry[][10], int larry_get[][10], int row, int column);

//网络版，准备摆
void print();