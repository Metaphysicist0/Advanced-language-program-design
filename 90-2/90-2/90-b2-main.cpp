/* 2150248 信18 姚天亮 */
//主函数及菜单部分函数
#include<iostream>
#include<conio.h>
#include<iomanip>
#include"cmd_console_tools.h"
#include"90-b2.h"
using namespace std;


//菜单显示函数
char menu()
{
	cct_setconsoleborder(120, 40, 120, 9000);
	cct_cls();
	char sel;
	while (1) {
	    cout << "-----------------------------------" << endl
			<< "1.命令行找出可合成项并标识(非递归)" << endl
			<< "2.命令行找出可合成项并标识(递归)" << endl
			<< "3.命令行完成一次合成(分步骤显示)" << endl
			<< "4.命令行完整版(分步骤显示)" << endl
			<< "5.伪图形界面显示初始数组(无分隔线)" << endl
			<< "6.伪图形界面显示初始数组(有分隔线)" << endl
			<< "7.伪图形界面下用箭头键/鼠标选择当前色块" << endl
			<< "8.伪图形界面完成一次合成(分步骤)" << endl
			<< "9.伪图形界面完整版(支持鼠标)" << endl
			<< "0.退出" << endl
			<< "-----------------------------------" << endl
			<< "[请选择0-9] ";
		sel = _getch();
		if (sel >= '0' && sel <= '9')
			break;
	}

	return sel;
}

int main()
{
	while (1){
		time_t t;
		srand((unsigned)time(&t));
		cct_setconsoleborder(120, 40, 120, 9000);
		cct_cls();
		const int sel = menu(); 
		//输入参数 根据输入分别处理
		switch (sel) {
			case '0':
				cout << endl;
				return 0;
			case '1':
				chushihua(sel);
				break;
			case '2':
				chushihua(sel);
				break;
			case '3':
				chushihua(sel);
				break;
			case '4':
				chushihua(sel);
				break;
			case '5':
				initial_picture(sel);
				break;
			case '6':
				initial_picture(sel);
				break;
			case '7':
				initial_picture(sel);
				break;
			case '8':
				initial_picture(sel);
			case '9':
				initial_picture(sel);
				break;
			default:
				break;
		}
	}

	return 0;
}

//20211212进度：单机版基本完成，目前剩余：
//8选项要玩两次才能退
//暂不支持鼠标
//20211216 塞进去了两个鼠标控制函数，但是没有任何反应....
//20211216 网络版让我再想想