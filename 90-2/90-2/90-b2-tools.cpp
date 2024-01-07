/* 2150248 信18 姚天亮 */
//内部数组/图形方式共用的函数，如判断结束等。
#include <iostream>
#include <iomanip>
#include <string.h>
#include <Windows.h>
#include<conio.h>
#include"cmd_console_tools.h"
#include"90-b2.h"
using namespace std;

//找到数组中的最大值
int findmax(int larry[][10], int row, int column)
{
	int max = 0;
	//遍历数组
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < column; ++j){
			if (larry[i][j] > max)
				max = larry[i][j];
		}
	}

	return max;
}

//产生随机数
int rand_int(int max)
{
	int n;
	//下面是按照要求产生随机数,max即是题目所说的最大数值范围的表示
	switch (max){
		case 3:
			n = (rand() % 3) + 1;;
			return n;

		case 4:
			n = (rand() % 10) + 1;
			if (n == 10)
				return 4;
			else
				return n % 3 + 1;

		case 5:
			n = (rand() % 20) + 1;
			if (n == 1 || n == 2)
				return 5;
			else if (n == 3 || n == 4 || n == 5)
				return 4;
			else
				return n % 3 + 1;

		case 6: 
			n = (rand() % 20) + 1;
			if (n == 1)
				return 6;
			else if (n == 3 || n == 4 || n == 5)
				return 5;
			else
				return n % 4 + 1;

		default:
			n = (rand() % 20) + 1;
			if (n == 1)
				return max;
			else if (n == 2)
				return max - 1;
			else if (n == 3 || n == 4)
				return max - 2;
			else
				return (rand() % (max - 3)) + 1;
	}
}

//所有找到相邻的相同数
//非递归
void neighbour_get_N(int larry[][10], int row, int column, int larry_get[][10], int x, int y, int neighbour)
{
	static int get = 1;

	//放一个结构体变量，用来存放符合条件点的横纵坐标并标记遍历情况
	struct check{
		int x;
		int y;
		int flag = 0;
	};

	//赋初值
	check a[80];
	a[0].x = x;
	a[0].y = y;
	a[0].flag = 1;

	//result数组存放最终结果结构体的下标。
	int result[80] = { 0 };
	int sum = 1;

	for (int i = 0; i < row; ++i){
		for (int j = 0; j < column; ++j){
			if (larry[i][j] == neighbour){
				a[get].x = i;
				a[get].y = j;
				++get;
			}
		}
	}

	//下面就是上次扫雷的难看版的遍历了！！！查周围的数组元素
	for (int i = 0; i < sum; ++i){
		for (int j = 1; j < get; ++j){
			if (a[result[i]].x + 1 == a[j].x && a[result[i]].y == a[j].y && a[j].flag == 0){
				result[sum] = j;
				a[j].flag = 1;
				++sum;
			}
			if (a[result[i]].x == a[j].x && a[result[i]].y - 1 == a[j].y && a[j].flag == 0) {
				result[sum] = j;
				a[j].flag = 1;
				++sum;
			}
			if (a[result[i]].x == a[j].x && a[result[i]].y + 1 == a[j].y && a[j].flag == 0) {
				result[sum] = j;
				a[j].flag = 1;
				++sum;
			}
			if (a[result[i]].x - 1 == a[j].x && a[result[i]].y == a[j].y && a[j].flag == 0){
				result[sum] = j;
				a[j].flag = 1;
				++sum;
			}
		}
	}

	//将所有larry数组中对应的点在larry_get数组中置 1，表示可以与目标点值相同，可被同时消去。
	for (int i = 0; i < sum; i++){
		larry_get[a[result[i]].x][a[result[i]].y] = 1;
	}
}

//所有找到相邻的相同数
//递归
void neighbour_get_Y(int larry[][10], int row, int column, int larry_get[][10], int x, int y, int neighbour)
{
	if (x < 0 || y < 0 || x >= row || y >= column)
		return;

	static int num = 1;

	if (x > 0) {
		if ((larry[x - 1][y] == neighbour) && (larry_get[x - 1][y]==0)) {
			++num;
			larry_get[x - 1][y] = 1;
			neighbour_get_Y(larry, row, column, larry_get, x - 1, y, neighbour);
		}
		else
			;
	}

	if (x < row - 1) {
		if ((larry[x + 1][y] == neighbour) && (larry_get[x + 1][y] == 0)) {
			++num;
			larry_get[x + 1][y] = 1;
			neighbour_get_Y(larry, row, column, larry_get, x + 1, y, neighbour);
		}
		else
			;
	}
	if (y > 0) {
		if ((larry[x][y - 1] == neighbour) && (larry_get[x][y - 1]==0)) {
			++num;
			larry_get[x][y - 1] = 1;
			neighbour_get_Y(larry, row, column, larry_get, x, y - 1, neighbour);
		}
		else
			;
	}


	if (y < column - 1) {
		if ((larry[x][y + 1] == neighbour) && (larry_get[x][y + 1]==0)) {
			++num;
			larry_get[x][y + 1] = 1;
			neighbour_get_Y(larry, row, column, larry_get, x, y + 1, neighbour);
		}
		else
			;
	}
}

//显示相邻函数
int show_neighbour(int larry[][10], int row, int column, int larry_get[][10], int x, int y)
{
	int sum = 0;

	for (int i = 0; i < row; ++i){
		for (int j = 0; j < column; ++j){
			if (larry_get[i][j] == 1) {
				if (i == x && j == y)
					++larry[i][j];
				else {
					larry[i][j] = 0;
					++sum;
				}
			}
			else
				;
		}
	}

	return (sum + 1);
}

//检查扫雷的那个和这个一样
int judge_show(int larry[][10], int row, int column)
{
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < column; ++j){
			if (i >= 1){
				if (larry[i][j] == larry[i - 1][j])
					continue;
			}
			if (j >= 1){
				if (larry[i][j] == larry[i][j - 1])
					continue;
			}
			if (i < row - 1){
				if (larry[i][j] == larry[i + 1][j])
					continue;
			}
			if (j < column - 1){
				if (larry[i][j] == larry[i][j + 1])
					continue;
			}
			else
				return 0;
		}
	}
	return 1;
}

//检查相邻数
int judge_neighbour(int larry[][10], int row, int column, int x, int y)
{
	if (x >= 1){
		if (larry[x][y] == larry[x - 1][y])
			return 1;
	}
	if (y >= 1){
		if (larry[x][y] == larry[x][y - 1])
			return 1;
	}
	if (x < row - 1){
		if (larry[x][y] == larry[x + 1][y])
			return 1;
	}
	if (y < column - 1){
		if (larry[x][y] == larry[x][y + 1])
			return 1;
	}
	return 0;
}

//统计分数
int score(int neighbour, int sum)
{
	return neighbour * sum * 3;
}

//判断是否数字可以落下
void down(int larry[][10], int row, int column)
{
	for (int i = 0; i < column; ++i) {
		for (int j = row - 2; j >= 0; --j) {
			if (larry[j + 1][i] == 0 && larry[j][i] != 0) {
				larry[j + 1][i] = larry[j][i];
				larry[j][i] = 0;

				for (int k = j + 1; k < row - 1; ++k) {
					if (larry[k + 1][i] == 0 && larry[k][i] != 0) {
						larry[k + 1][i] = larry[k][i];
						larry[k][i] = 0;
					}
				}
			}
		}
	}
}

//设置
void set(int larry[][10], int row, int column)
{
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < column; ++j){
			larry[i][j] = rand_int(3);
		}
	}
}

//设置
void setmax(int larry[][10], int row, int column)
{
	int max = findmax(larry, row, column);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			if (larry[i][j] == 0)
				larry[i][j] = rand_int(max);
			else
				;
		}
	}
}

//游戏结束的输入处理
void game_ending(int column)
{
	cout << endl << "本小题结束，请输入End继续...";
	while (1) {
		char ch[3];
		for (int i = 0; i < 3; i++) {
			ch[i] = getchar();
		}
		if (!cin.good() || ch[0] != 'E' || ch[1] != 'n' || ch[2] != 'd') {
			cout << "输入不合法，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else {
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
	}
}