/* 2150248 ��18 Ҧ���� */
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
		cout << "1.������" << endl;
		cout << "2.������(������¼)" << endl;
		cout << "3.�ڲ�������ʾ(����)" << endl;
		cout << "4.�ڲ�������ʾ(���� + ����)" << endl;
		cout << "5.ͼ�ν� - Ԥ�� - ������Բ��" << endl;
		cout << "6.ͼ�ν� - Ԥ�� - ����ʼ���ϻ�n������" << endl;
		cout << "7.ͼ�ν� - Ԥ�� - ��һ���ƶ�" << endl;
		cout << "8.ͼ�ν� - �Զ��ƶ��汾" << endl;
		cout << "9.ͼ�ν� - ��Ϸ��" << endl;
		cout << "0.�˳�" << endl;
		cout << "---------------------------------" << endl;
		cout << "[��ѡ��:]" << endl;
		sel = _getch();
		if (sel >= '0' && sel <= '9')
			break;
	}
	
	return sel;
}