/*2150248 信18 姚天亮*/
#define MAX_LAYER 10
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<cstdio>
#include"cmd_console_tools.h"
using namespace std;

int sum = 0;//步数
int plate;//盘子数量
int larry[3][10]; //三个塔i：记数用全局变量
char start_col, end_col, tmp_col;
const int X = 10;
const int Y = 12;

//三个字母对应好三个塔的一个转换函数
int f(char x)
{
	if (x == 'A')
		return 0;
	else if (x == 'B')
		return 1;
	else
		return 2;
}

//1/2/3/4/6/7/8共用的输入函数
void inputbox()     
{
	int f(char x);
	while (1) {
		cout << "请输入层数" << endl;
		cin >> plate;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (plate >= 1 && plate <= 10)
			break;
	}

	while (1) {
		cout << "请输入起始柱(A-C): " << endl;
		cin >> start_col;   //不管本次输入多少字符；只取第一个，后面清楚;
		if (start_col >= 'a' && start_col <= 'c')
			start_col -= 32;    //小写转大写
		if (start_col >= 'A' && start_col <= 'C')
			break;
	}

	while (1) {
		cout << "请输入目标柱(A-C): " << endl;
		cin >> end_col;
		if (end_col >= 'a' && end_col <= 'c')
			end_col -= 32;
		if (end_col == start_col) {
			cout << "目标柱("<<start_col<<")不能与起始柱("<<start_col<<")相同" << endl;
			continue;
		}

		if (end_col >= 'A' && end_col <= 'C')
			break;
	}

	if (f(end_col) + f(start_col) == 1)//通过输入的起始柱和结束柱，判断中间柱 用了函数数值的方法，简单了一点
		tmp_col = 'C';
	else if (f(end_col) + f(start_col) == 2)
		tmp_col = 'B';
	else
		tmp_col = 'A';

}

//设定速度
void speed(int t)   
{
	if (t == 0)
		getchar();
	if (t == 1)
		Sleep(50);
	if (t == 2)
		Sleep(20);
	if (t == 3)
		Sleep(15);
	if (t == 4)
		Sleep(10);
	if (t == 5)
		Sleep(1);
}

//横向打印数组值
//优化，查到了'\t'来使得调格式更加方便
void print_hengxiang()   
{
	cout << setw(7) << "A: ";
	for (int k = 0; k < 10; k++) {
		if (larry[0][k] > 0)
			cout << larry[0][k] << " ";
		else
			cout << "  ";
	}
	cout << '\t' << "  B: ";
	for (int k = 0; k < 10; k++) {
		if (larry[1][k] > 0)
			cout << larry[1][k] << " ";
		else
			cout << "  ";
	}
	cout << '\t' << "C: ";
	for (int k = 0; k < 10; k++) {
		if (larry[2][k] > 0)
			cout << larry[2][k] << " ";
		else
			cout << "  ";
	}
	cout << endl;
}

//纵向打印数组值
//打印两个空格（比如说10出现，就可以一次盖掉两个
void print_zongxiang(int y1, int y2, int y3)  
{
	for (int k = 0; k < 10; k++) {
		--y1;
		cct_gotoxy(X + 1, y1);
		if (larry[0][k] > 0)
			cout << larry[0][k];
		else
			cout << "  ";
	}

	for (int k = 0; k < 10; k++) {
		--y2;
		cct_gotoxy(X + 15, y2);
		if (larry[1][k] > 0)
			cout << larry[1][k];
		else
			cout << "  ";
	}

	for (int k = 0; k < 10; k++) {
		--y3;
		cct_gotoxy(X + 30, y3);
		if (larry[2][k] > 0)
			cout << larry[2][k];
		else
			cout << "  ";
	}

	cout << endl;
}

//之前做的纵向塔的打印
void print_zongxiangta(int m)          
{
	if (m)
		cct_gotoxy(X, Y + 14);
	else
		cct_gotoxy(X, Y);

	cout << "=================================" << endl;

	if (m)
		cct_gotoxy(X + 1, Y + 15);
	else
		cct_gotoxy(X, Y + 1);

	cout << " A" << setw(14) << " B" << setw(14) << " C" << endl;
	cout << endl;
	cct_gotoxy(0, Y + 8);

	if (m)
		cct_gotoxy(0, Y + 19);

	cout << "起始：";
	print_hengxiang();

}

//画三根柱子
//直接就是菜单第五项，改名menu5
void menu5()
{
	cct_setconsoleborder(120, 45);
	int X = 5;

	for (int i = 0; i < 3; ++i) {
		cct_showch(X + i * 30, 15, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 22);
		Sleep(50);
	}

	for (int j = 15; j > 2; --j) {
		cct_showch(X + 10, j, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
		Sleep(50);
		cct_showch(X + 40, j, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
		Sleep(50);
		cct_showch(X + 70, j, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
		Sleep(50);
	}

	cct_showch(0, 28, ' ', 0, 7, 1);
}

//在起始位置打印盘子
void print_pan()
{
	for (int j = 14, p = plate; p > 0; --j, --p) {
		cct_showch((15 + 30 * f(start_col) - p), j, ' ', p, p, 2 * p + 1);
		Sleep(50);
	}
	cct_showch( 0, 33, ' ', 0, 7, 1);
}   

//画出移动盘子的函数
//和塔对应
void move_pan(int p, char x, char y, int j, int k, int t)
{
	//盘子上移
	for (int s = 15 - j; s > 2; --s) {
		cct_showch(15 + 30 * f(x) - p, s - 1, ' ', p, p, p * 2 + 1);
		if (s < 15 - j) {
			cct_showch(15 + 30 * f(x), s, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
			cct_showch(15 + 30 * f(x) - p, s, ' ', 0, 7, p);
			cct_showch(15 + 30 * f(x) + 1, s, ' ', 0, 7, p);
		}
		if (t == 0)
			Sleep(25);
		else
			speed(t);
	}

	int m = ((f(x) > f(y)) ? (-1) : 1);
	//左移t = -1, 右移是t = 1

	//把盘子移到另一个塔
	//起始：盘子的初始位置，判断：是否移动完毕？步长：左or右移

	//盘子左右的移动
	for (int i = 15 + 30 * f(x) - p; i != 15 + 30 * f(y) - p; i += m) {   
		cct_showch( i + m, 2, ' ', p, p, p * 2 + 1);
		if (m == 1)
			cct_showch(i, 2, ' ', 0, 7, 1);
		else
			cct_showch(i + 2 * p, 2, ' ', 0, 7, p * 2 + 1); 
		if (t == 0)
			Sleep(25);
		else
			speed(t);
	}

	//这里是和上面对应，让盘子下去
	for (int w = 3; w < 14 - k; w++) {
		cct_showch(15 + 30 * f(y) - p, w, ' ', p, p, p * 2 + 1);
		if (w > 3)
			cct_showch(15 + 30 * f(y), w - 1, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
		else
			cct_showch(15 + 30 * f(y), w - 1, ' ', 0, 7, 1);
		cct_showch(15 + 30 * f(y) - p, w - 1, ' ', 0, 7, p);
		cct_showch(15 + 30 * f(y) + 1, w - 1, ' ', 0, 7, p);
		if (t == 0)
			Sleep(25);
		else
			speed(t);
	}
	
	cct_showch(0, 28, ' ', 0, 7, 1);
}

//移动过程
//picture值是否要移动图形
//bushu指是否打印步数   
//shuzuxianshi指内部数组随步骤的显示，
//t指是否需要延时，以及打印竖式

void move(int i, char x, char y, int bushu, int shuzuxianshi, int t, int picture)
{

	if (t >= 0)
		speed(t);
	++sum;

	if (bushu) {
		if (t >= 0)
			cct_gotoxy(0, Y + 8);
		if (picture)
			cct_gotoxy(0, Y + 19);
		cout << "第" << setw(4) << sum << "步 " << '(' << setw(2) << i << "):" << x << "-->" << y;
		if (!shuzuxianshi)
			cout << endl;
	}
	else
		cout << i << '#' << ':' << x << "-->" << y << endl;

	//打印内部数组也在这里处理了
	if (shuzuxianshi) {
		int j = 0, k = 0;
		while (larry[f(x)][j] != -1 && j < plate)
			++j;
		while (larry[f(y)][k] != -1 && k < plate)
			++k;
		larry[f(y)][k] = larry[f(x)][j - 1];
		larry[f(x)][j - 1] = -1;

		print_hengxiang();

		if (t >= 0) {
			if (picture) {
				print_zongxiang(Y + 14, Y + 14, Y + 14);
				move_pan(i, x, y, j - 1, k - 1, t);   //可恶啊
			}
			else
				print_zongxiang(Y, Y, Y);
		}
		else
			;
	}
}

//bushu指是否打印步数 
//shuzuxianshi指内部数组随步骤的显示，
// t指是否需要延时，以及打印竖式
//picture指的是图形打印
void hanoi(int j, char A, char B, char C, int bushu, int shuzuxianshi, int t, int picture)	
{                                                 
	if (j == 1) 
		move(j, A, C, bushu, shuzuxianshi, t, picture);
	else {
		hanoi(j - 1, A, C, B, bushu, shuzuxianshi, t, picture);
		move(j, A, C, bushu, shuzuxianshi, t, picture);
		hanoi(j - 1, B, A, C, bushu, shuzuxianshi, t, picture);
	}
}

//第一项菜单功能
void menu1()
{
	inputbox();
	hanoi(plate, start_col, tmp_col, end_col, 0, 0, -1, 0);
	cout << endl;
	cout << "按回车键继续...";
	while (_getch() != '\r');
}

//第二项菜单功能
void menu2()
{
	sum = 0;
	inputbox();
	hanoi(plate, start_col, tmp_col, end_col, 1, 0, -1, 0);
	cout << endl;
	cout << "按回车键继续...";
	while (_getch() != '\r');
}

//第三项菜单功能
void menu3()
{
	sum = 0;
	inputbox();
	for (int i = 0; i < 10; i++) {           //数组，即各柱子盘子数赋初值
		larry[f(start_col)][i] = plate - i;
		larry[f(tmp_col)][i] = -1;
		larry[f(end_col)][i] = -1;
	}
	cct_cls();
	cout << "起   始：          ";
	print_hengxiang();
	hanoi(plate, start_col, tmp_col, end_col, 1, 1, -1, 0);
	cout << endl;
	cout << "按回车键继续...";
	while (_getch() != '\r');

}

//第四项菜单功能
void menu4(int m)
{
	sum = 0;
	int t;
	inputbox();

	while (1) {
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		cin >> t;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (t >= 0 && t <= 5)
			break;
	}

	for (int i = 0; i < 10; i++) {    //为数组，即各柱子盘子数赋初值
		larry[f(start_col)][i] = plate - i;
		larry[f(tmp_col)][i] = -1;
		larry[f(end_col)][i] = -1;
	}

	cct_cls();
	cct_gotoxy(0, 0);
	cout << "从" << start_col << "移动到" << end_col << ",共" << plate << "层，延时设置为" << t << endl;
	print_zongxiangta(m);
	speed(t);
	print_zongxiang(Y, Y, Y);
	hanoi(plate, start_col, tmp_col, end_col, 1, 1, t, m);
	cout << endl;
	cct_gotoxy(0, 25);
	cout << "按回车键继续...";
	while (_getch() != '\r');
}

//第六项菜单功能
void menu6()
{
	inputbox();
	menu5();
	print_pan();
	cct_gotoxy(0, 28);
	cout << "按回车键继续...";
	while (_getch() != '\r');
}

//第七项菜单功能
void menu7()
{
	inputbox();
	menu5();
	print_pan();
	move_pan(1, start_col, tmp_col, plate - 1, -1, 1);
	cct_gotoxy(0, 33);
	cout << "按回车键继续...";
	while (_getch() != '\r');
}

//第八项菜单功能
void menu8()
{
	inputbox();
	int t;
	while (1) {
		cout << "请输入移动速度（0-5），0-按回车单步演示，1-延时最长，5-延时最短：";
		cin >> t;
		if (cin.fail() || t < 0 || t > 5) {
			cin.clear();
			cin.ignore();
			continue;
		}
		break;
	}

	for (int i = 0; i < 10; i++) {     //为数组，即各柱子盘子数赋初值
		larry[f(start_col)][i] = plate - i;
		larry[f(tmp_col)][i] = -1;
		larry[f(end_col)][i] = -1;
	}

	menu5();   //画塔
	print_pan();    //画盘子
	cct_gotoxy(0, 0);          //移动光标
	cout << "从" << start_col << "移动到" << end_col << ",共" << plate << "层，延时设置为" << t << endl;
	print_zongxiangta(1);   //输出纵向的数字塔
	speed(t); //设定延时
	print_zongxiang(Y + 14, Y + 14, Y + 14);
	hanoi(plate, start_col, tmp_col, end_col, 1, 1, t, 1);
	cout << endl;
	cout << "按回车键继续...";
	while (_getch() != '\r');
}

//第九项菜单功能
void menu9()  //20211122给爷改, //20211123 确证了我是伞兵
{
	sum = 0;
	inputbox();
	menu5();
	print_pan();
	for (int i = 0; i < 10; ++i) {    //为数组，即各柱子盘子数赋初值
		larry[f(start_col)][i] = plate - i;
		larry[f(tmp_col)][i] = -1;
		larry[f(end_col)][i] = -1;
	}

	print_zongxiangta(1);
	print_zongxiang(Y + 14, Y + 14, Y + 14);

	while (1) {
		cct_gotoxy(0, 29);
		//这里加个输入错误吧
		cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
		cout << "     ";
		cct_gotoxy(65, 29);
		char c[2];
		//没有能够解决输入错误的问题
		for (int i = 0; i < 2; ++i) {
			cin >> c[i];
			if (c[i] == 'Q'||c[i]=='q')
				return ;
		}

		int j = 0, k = 0;

		if (larry[f(c[0])][0] == -1) {
			cct_gotoxy(0, 31);
			cout << "柱源为空";
			cout << "                                 ";
			continue;
		}
		//在这里判断！
		while (larry[f(c[0])][j] != -1 && j < plate)
			++j;
		while (larry[f(c[1])][k] != -1 && k < plate)
			++k;

		if (larry[f(c[0])][j - 1] > larry[f(c[1])][k - 1] && larry[f(c[1])][k - 1] > 0) {
			cct_gotoxy(0, 31);
			cout << "大盘压小盘，非法移动！";
			cout << "                                 ";
			continue;
		}

		if (c[0] == c[1])
			continue;
		else 
			move(larry[f(c[0])][j - 1], c[0], c[1], 1, 1, 0, 1);

		j = 0, k = 0;
		while (larry[f(start_col)][j] != -1 && j < plate)
			++j;
		while (larry[f(end_col)][k] != -1 && k < plate)
			++k;

		if (j == 0 && k == plate) {
			cct_gotoxy(0, 32);
			cout << "游戏结束!!!!!" << endl;
			break;
		}
	}

	cct_gotoxy(0, 34);
	cout << "按回车键继续...";
	while (_getch() != '\r');
}
