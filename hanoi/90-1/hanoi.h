/* 2150248 –≈18 “¶ÃÏ¡¡ */
#pragma once
#include"cmd_console_tools.h"
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<cstdio>
#include"cmd_console_tools.h"

char hanoi_menu();
void inputbox();
int f(char x);
void speed(int t);
void print_hengxiang();
void print_zongxiang(int y1, int y2, int y3);
void menu5();
void print_pan();
void move_pan(int p, char x, char y, int j, int k, int t);
void move(int i, char x, char y, int bushu, int xianshineibushuzu, int t, int m);
void hanoi(int n, char A, char B, char C, int bushu, int xianshineibushuzu, int t, int m);
void menu1();
void menu2();
void menu3();
void menu4(int m);
void menu6();
void menu7();
void menu8();
void menu9();