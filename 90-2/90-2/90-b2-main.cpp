/* 2150248 ��18 Ҧ���� */
//���������˵����ֺ���
#include<iostream>
#include<conio.h>
#include<iomanip>
#include"cmd_console_tools.h"
#include"90-b2.h"
using namespace std;


//�˵���ʾ����
char menu()
{
	cct_setconsoleborder(120, 40, 120, 9000);
	cct_cls();
	char sel;
	while (1) {
	    cout << "-----------------------------------" << endl
			<< "1.�������ҳ��ɺϳ����ʶ(�ǵݹ�)" << endl
			<< "2.�������ҳ��ɺϳ����ʶ(�ݹ�)" << endl
			<< "3.���������һ�κϳ�(�ֲ�����ʾ)" << endl
			<< "4.������������(�ֲ�����ʾ)" << endl
			<< "5.αͼ�ν�����ʾ��ʼ����(�޷ָ���)" << endl
			<< "6.αͼ�ν�����ʾ��ʼ����(�зָ���)" << endl
			<< "7.αͼ�ν������ü�ͷ��/���ѡ��ǰɫ��" << endl
			<< "8.αͼ�ν������һ�κϳ�(�ֲ���)" << endl
			<< "9.αͼ�ν���������(֧�����)" << endl
			<< "0.�˳�" << endl
			<< "-----------------------------------" << endl
			<< "[��ѡ��0-9] ";
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
		//������� ��������ֱ���
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

//20211212���ȣ������������ɣ�Ŀǰʣ�ࣺ
//8ѡ��Ҫ�����β�����
//�ݲ�֧�����
//20211216 ����ȥ�����������ƺ���������û���κη�Ӧ....
//20211216 ���������������