/*2150248 ��18 Ҧ����*/
#define MAX_LAYER 10
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<cstdio>
#include"cmd_console_tools.h"
using namespace std;

int sum = 0;//����
int plate;//��������
int larry[3][10]; //������i��������ȫ�ֱ���
char start_col, end_col, tmp_col;
const int X = 10;
const int Y = 12;

//������ĸ��Ӧ����������һ��ת������
int f(char x)
{
	if (x == 'A')
		return 0;
	else if (x == 'B')
		return 1;
	else
		return 2;
}

//1/2/3/4/6/7/8���õ����뺯��
void inputbox()     
{
	int f(char x);
	while (1) {
		cout << "���������" << endl;
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
		cout << "��������ʼ��(A-C): " << endl;
		cin >> start_col;   //���ܱ�����������ַ���ֻȡ��һ�����������;
		if (start_col >= 'a' && start_col <= 'c')
			start_col -= 32;    //Сдת��д
		if (start_col >= 'A' && start_col <= 'C')
			break;
	}

	while (1) {
		cout << "������Ŀ����(A-C): " << endl;
		cin >> end_col;
		if (end_col >= 'a' && end_col <= 'c')
			end_col -= 32;
		if (end_col == start_col) {
			cout << "Ŀ����("<<start_col<<")��������ʼ��("<<start_col<<")��ͬ" << endl;
			continue;
		}

		if (end_col >= 'A' && end_col <= 'C')
			break;
	}

	if (f(end_col) + f(start_col) == 1)//ͨ���������ʼ���ͽ��������ж��м��� ���˺�����ֵ�ķ���������һ��
		tmp_col = 'C';
	else if (f(end_col) + f(start_col) == 2)
		tmp_col = 'B';
	else
		tmp_col = 'A';

}

//�趨�ٶ�
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

//�����ӡ����ֵ
//�Ż����鵽��'\t'��ʹ�õ���ʽ���ӷ���
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

//�����ӡ����ֵ
//��ӡ�����ո񣨱���˵10���֣��Ϳ���һ�θǵ�����
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

//֮ǰ�����������Ĵ�ӡ
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

	cout << "��ʼ��";
	print_hengxiang();

}

//����������
//ֱ�Ӿ��ǲ˵����������menu5
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

//����ʼλ�ô�ӡ����
void print_pan()
{
	for (int j = 14, p = plate; p > 0; --j, --p) {
		cct_showch((15 + 30 * f(start_col) - p), j, ' ', p, p, 2 * p + 1);
		Sleep(50);
	}
	cct_showch( 0, 33, ' ', 0, 7, 1);
}   

//�����ƶ����ӵĺ���
//������Ӧ
void move_pan(int p, char x, char y, int j, int k, int t)
{
	//��������
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
	//����t = -1, ������t = 1

	//�������Ƶ���һ����
	//��ʼ�����ӵĳ�ʼλ�ã��жϣ��Ƿ��ƶ���ϣ���������or����

	//�������ҵ��ƶ�
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

	//�����Ǻ������Ӧ����������ȥ
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

//�ƶ�����
//pictureֵ�Ƿ�Ҫ�ƶ�ͼ��
//bushuָ�Ƿ��ӡ����   
//shuzuxianshiָ�ڲ������沽�����ʾ��
//tָ�Ƿ���Ҫ��ʱ���Լ���ӡ��ʽ

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
		cout << "��" << setw(4) << sum << "�� " << '(' << setw(2) << i << "):" << x << "-->" << y;
		if (!shuzuxianshi)
			cout << endl;
	}
	else
		cout << i << '#' << ':' << x << "-->" << y << endl;

	//��ӡ�ڲ�����Ҳ�����ﴦ����
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
				move_pan(i, x, y, j - 1, k - 1, t);   //�ɶ�
			}
			else
				print_zongxiang(Y, Y, Y);
		}
		else
			;
	}
}

//bushuָ�Ƿ��ӡ���� 
//shuzuxianshiָ�ڲ������沽�����ʾ��
// tָ�Ƿ���Ҫ��ʱ���Լ���ӡ��ʽ
//pictureָ����ͼ�δ�ӡ
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

//��һ��˵�����
void menu1()
{
	inputbox();
	hanoi(plate, start_col, tmp_col, end_col, 0, 0, -1, 0);
	cout << endl;
	cout << "���س�������...";
	while (_getch() != '\r');
}

//�ڶ���˵�����
void menu2()
{
	sum = 0;
	inputbox();
	hanoi(plate, start_col, tmp_col, end_col, 1, 0, -1, 0);
	cout << endl;
	cout << "���س�������...";
	while (_getch() != '\r');
}

//������˵�����
void menu3()
{
	sum = 0;
	inputbox();
	for (int i = 0; i < 10; i++) {           //���飬������������������ֵ
		larry[f(start_col)][i] = plate - i;
		larry[f(tmp_col)][i] = -1;
		larry[f(end_col)][i] = -1;
	}
	cct_cls();
	cout << "��   ʼ��          ";
	print_hengxiang();
	hanoi(plate, start_col, tmp_col, end_col, 1, 1, -1, 0);
	cout << endl;
	cout << "���س�������...";
	while (_getch() != '\r');

}

//������˵�����
void menu4(int m)
{
	sum = 0;
	int t;
	inputbox();

	while (1) {
		cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
		cin >> t;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (t >= 0 && t <= 5)
			break;
	}

	for (int i = 0; i < 10; i++) {    //Ϊ���飬������������������ֵ
		larry[f(start_col)][i] = plate - i;
		larry[f(tmp_col)][i] = -1;
		larry[f(end_col)][i] = -1;
	}

	cct_cls();
	cct_gotoxy(0, 0);
	cout << "��" << start_col << "�ƶ���" << end_col << ",��" << plate << "�㣬��ʱ����Ϊ" << t << endl;
	print_zongxiangta(m);
	speed(t);
	print_zongxiang(Y, Y, Y);
	hanoi(plate, start_col, tmp_col, end_col, 1, 1, t, m);
	cout << endl;
	cct_gotoxy(0, 25);
	cout << "���س�������...";
	while (_getch() != '\r');
}

//������˵�����
void menu6()
{
	inputbox();
	menu5();
	print_pan();
	cct_gotoxy(0, 28);
	cout << "���س�������...";
	while (_getch() != '\r');
}

//������˵�����
void menu7()
{
	inputbox();
	menu5();
	print_pan();
	move_pan(1, start_col, tmp_col, plate - 1, -1, 1);
	cct_gotoxy(0, 33);
	cout << "���س�������...";
	while (_getch() != '\r');
}

//�ڰ���˵�����
void menu8()
{
	inputbox();
	int t;
	while (1) {
		cout << "�������ƶ��ٶȣ�0-5����0-���س�������ʾ��1-��ʱ���5-��ʱ��̣�";
		cin >> t;
		if (cin.fail() || t < 0 || t > 5) {
			cin.clear();
			cin.ignore();
			continue;
		}
		break;
	}

	for (int i = 0; i < 10; i++) {     //Ϊ���飬������������������ֵ
		larry[f(start_col)][i] = plate - i;
		larry[f(tmp_col)][i] = -1;
		larry[f(end_col)][i] = -1;
	}

	menu5();   //����
	print_pan();    //������
	cct_gotoxy(0, 0);          //�ƶ����
	cout << "��" << start_col << "�ƶ���" << end_col << ",��" << plate << "�㣬��ʱ����Ϊ" << t << endl;
	print_zongxiangta(1);   //��������������
	speed(t); //�趨��ʱ
	print_zongxiang(Y + 14, Y + 14, Y + 14);
	hanoi(plate, start_col, tmp_col, end_col, 1, 1, t, 1);
	cout << endl;
	cout << "���س�������...";
	while (_getch() != '\r');
}

//�ھ���˵�����
void menu9()  //20211122��ү��, //20211123 ȷ֤������ɡ��
{
	sum = 0;
	inputbox();
	menu5();
	print_pan();
	for (int i = 0; i < 10; ++i) {    //Ϊ���飬������������������ֵ
		larry[f(start_col)][i] = plate - i;
		larry[f(tmp_col)][i] = -1;
		larry[f(end_col)][i] = -1;
	}

	print_zongxiangta(1);
	print_zongxiang(Y + 14, Y + 14, Y + 14);

	while (1) {
		cct_gotoxy(0, 29);
		//����Ӹ���������
		cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
		cout << "     ";
		cct_gotoxy(65, 29);
		char c[2];
		//û���ܹ����������������
		for (int i = 0; i < 2; ++i) {
			cin >> c[i];
			if (c[i] == 'Q'||c[i]=='q')
				return ;
		}

		int j = 0, k = 0;

		if (larry[f(c[0])][0] == -1) {
			cct_gotoxy(0, 31);
			cout << "��ԴΪ��";
			cout << "                                 ";
			continue;
		}
		//�������жϣ�
		while (larry[f(c[0])][j] != -1 && j < plate)
			++j;
		while (larry[f(c[1])][k] != -1 && k < plate)
			++k;

		if (larry[f(c[0])][j - 1] > larry[f(c[1])][k - 1] && larry[f(c[1])][k - 1] > 0) {
			cct_gotoxy(0, 31);
			cout << "����ѹС�̣��Ƿ��ƶ���";
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
			cout << "��Ϸ����!!!!!" << endl;
			break;
		}
	}

	cct_gotoxy(0, 34);
	cout << "���س�������...";
	while (_getch() != '\r');
}
