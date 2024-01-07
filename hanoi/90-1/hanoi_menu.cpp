/* 2150248 信18 姚天亮 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include"hanoi.h"
#include<math.h>
#include<iomanip>
using namespace std;

char hanoi_menu()
{
	char sel;
	while (1) {
		cout << "---------------------------------" << endl;
		cout << "1.基本解" << endl;
		cout << "2.基本解(步数记录)" << endl;
		cout << "3.内部数组显示(横向)" << endl;
		cout << "4.内部数组显示(纵向 + 横向)" << endl;
		cout << "5.图形解 - 预备 - 画三个圆柱" << endl;
		cout << "6.图形解 - 预备 - 在起始柱上画n个盘子" << endl;
		cout << "7.图形解 - 预备 - 第一次移动" << endl;
		cout << "8.图形解 - 自动移动版本" << endl;
		cout << "9.图形解 - 游戏版" << endl;
		cout << "0.退出" << endl;
		cout << "---------------------------------" << endl;
		cout << "[请选择:]" << endl;
		sel = _getch();
		if (sel >= '0' && sel <= '9')
			break;
	}
	
	return sel;
}