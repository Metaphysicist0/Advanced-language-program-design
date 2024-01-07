/* 2150248 ��18 Ҧ���� */
//���ڲ����鷽ʽʵ�ֵĸ�����
//ȱ���ʵ��
#include<iostream>
#include<conio.h>
#include<iomanip>
#include"cmd_console_tools.h"
#include"90-b2.h"
using namespace std;

//��ӡ����
void print_larry(int larry[][10], int row, int column)//��ӡ����
{
	cout << "��ǰ���飺" << endl;
	cout << "  |";

	for (int i = 0; i < column; ++i)
		cout << setw(3) << i;

	cout << endl << "--+";
	for (int i = 0; i < 3 * column; ++i)
		cout << "-";

	cout << "-" << endl;
	for (int i = 0; i < row; ++i){
		cout << char(i + 'A') << " |";
		for (int j = 0; j < column; ++j){
			cout << setw(3) << larry[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//�鲢��Ʒֵ���ʾ
int put_together_and_show_score(int larry[][10], int row, int column, int larry_get[][10], int x, int y, int res, int target, int score_sum)
{
	cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���c2��(Y/N/Q)��";
	char sel_1;

	while (1){
		sel_1 = _getch();
		if (sel_1 == 'y' || sel_1 == 'Y'){
			cout << "y" << endl << endl;
			cout << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
			int show_sum = show_neighbour(larry, row, column,larry_get, x, y);
			print_result(larry, row, column,larry_get, 0);
			int score_thistime = score(res, show_sum);
			score_sum += score_thistime;
			cout << endl << "���ε÷֣�" << score_thistime << " �ܵ÷֣�" << score_sum << " �ϳ�Ŀ�꣺" << target << endl;
			print_removeZero(larry, row, column, larry_get);
			break;
		}

		else if (sel_1 == 'n' || sel_1 == 'N'){
			cout << "n" << endl << endl;
			return score_sum;
		}

		else if (sel_1 == 'q' || sel_1 == 'Q'){
			cout << "q" << endl << endl;
			return -1;
		}
	}

	return score_sum;
}

//�����0����
void print_removeZero(int larry[][10], int row, int column, int larry_get[][10])
{
	cout << endl << "���س����������������0����..." << endl;
	int sel_1;

	while (1){
		sel_1 = _getch();
		if (sel_1 == 13) {
			break;
		}
		else
			;
	}

	for (int i = 0; i < row; ++i){
		for (int j = 0; j < column; ++j){
			larry_get[i][j] = 0;
		}
	}

	down(larry, row, column);
	cout << "��0�������(��ͬɫ��ʶ)��" << endl;
	cout << "  |";

	for (int i = 0; i < column; ++i)
		cout << setw(3) << i;
	cout << endl << "--+";

	for (int i = 0; i < 3 * column; ++i)
		cout << "-";
	cout << "-" << endl;

	for (int i = 0; i < row; ++i){
		cout << char(i + 'A') << " |";
		for (int j = 0; j < column; ++j){
			if (larry[i][j] != 0)
				cout << setw(3) << larry[i][j];
			else{
				int x, y;
				cct_getxy(x, y);
				cct_showint(x, y, 0, COLOR_BLACK, COLOR_BLACK, 2);
				cct_showint(x + 2, y, larry[i][j], COLOR_BLACK, COLOR_HYELLOW);
				larry_get[i][j] = 1;
				cct_setcolor(0, 7);
			}
		}
		cout << endl;
	}

	cout << endl << "���س���������ֵ���..." << endl;
	int sel_2;

	while (1){
		sel_2 = _getch();
		if (sel_2 == 13) {
			break;
		}
		else
			;
	}

	setmax(larry, row, column);

	cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
	cout << "  |";

	for (int i = 0; i < column; ++i)
		cout << setw(3) << i;
	cout << endl << "--+";

	for (int i = 0; i < 3 * column; ++i)
		cout << "-";
	cout << "-" << endl;

	for (int i = 0; i < row; ++i){
		cout << char(i + 'A') << " |";
		for (int j = 0; j < column; ++j){
			if (larry_get[i][j] == 0)
				cout << setw(3) << larry[i][j];
			else{
				int x, y;
				cct_getxy(x, y);
				cct_showint(x, y, 0, COLOR_BLACK, COLOR_BLACK, 2);
				cct_showint(x + 2, y, larry[i][j], COLOR_BLACK, COLOR_HYELLOW);
				larry_get[i][j] = 0;
				cct_setcolor(0, 7);
			}
		}
		cout << endl;
	}

	cout << endl << "���κϳɽ��������س���������һ�εĺϳ�..." << endl;
	int sel_3;
	while (1){
		sel_3 = _getch();
		if (sel_3 == 13) {
			break;
		}
		else
			;
	}
}

//��ӡ��ȥ��Ľ��
void print_result(int larry[][10], int row, int column, int larry_get[][10], int flag)
{
	if (flag == 1){
		cout << "���ҽ�����飺" << endl;
		cout << "  |";

		for (int i = 0; i < column; ++i)
			cout << setw(3) << i;
		cout << endl << "--+";

		for (int i = 0; i < 3 * column; ++i)
			cout << "-";
		cout << "-" << endl;

		for (int i = 0; i < row; ++i){
			cout << char(i + 'A') << " |";
			for (int j = 0; j < column; ++j){
				if (larry_get[i][j] == 0)
					cout << setw(3) << larry_get[i][j];
				else
					cout << setw(3) << "*";
			}
			cout << endl;
		}

		cout << endl << endl << "��ǰ����(��ͬɫ��ʶ)��" << endl;
	}

	cout << "  |";

	for (int i = 0; i < column; ++i)
		cout << setw(3) << i;
	cout << endl << "--+";

	for (int i = 0; i < 3 * column; ++i)
		cout << "-";
	cout << "-" << endl;

	for (int i = 0; i < row; ++i){
		cout << char(i + 'A') << " |";
		for (int j = 0; j < column; ++j){
			if (larry_get[i][j] == 0)
				cout << setw(3) << larry[i][j];
			else{
				int x, y;
				cct_getxy(x, y);
				cct_showint(x, y, 0, COLOR_BLACK, COLOR_BLACK, 2);
				cct_showint(x + 2, y, larry[i][j], COLOR_BLACK, COLOR_HYELLOW);
				cct_setcolor(0, 7);
			}
		}
		cout << endl;
	}
}

//��ʼ����һ���ܴ�ĺ������Ͳ˵��йص�
void chushihua(char sel)
{
	int row, column;
	cct_cls();
	cout << "����������(5-8)��";
	while (1){
		cin >> row;
		if (!cin.good() || row > 8 || row < 5){
			cout << "���벻�Ϸ�������������";
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else{
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
	}

	cout << "����������(5-10)��";
	while (1){
		cin >> column;
		if (!cin.good() || column > 10 || column < 5){
			cout << "���벻�Ϸ�������������";
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else{
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
	}

	int aim;
	if (sel == '3' || sel == '4'){
		cout << "������ϳ�Ŀ��(5-20)��";
		while (1){
			cin >> aim;
			if (!cin.good() || aim > 20 || aim < 5){
				cout << "���벻�Ϸ�������������";
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else{
				cin.clear();
				cin.ignore(65536, '\n');
				break;
			}
		}
	}

	cct_gotoxy(0, 4);
	int larry[8][10] = { 0 };

	set(larry, row, column);
	print_larry(larry, row, column);

	char x;
	int y;

	while (1){
		cout << endl << "������ĸ+������ʽ[����c2]����������꣺";
		cin >> x >> y;

		if (!cin.good() || y > column || y < 0 || x < 'a' || x>char(row + 'a')){
			cout << "���벻�Ϸ�������������"<<endl;
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}

		else{
			cin.clear();
			cin.ignore(65536, '\n');
		}
		cout << "����Ϊ" << x << "��" << y << "��" << endl << endl;

		int judge_the_same;
		judge_the_same = judge_neighbour(larry, row, column, x - 'a', y);
		if (judge_the_same == 1)
			break;
		else
			cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
	}

	int larry_get[8][10] = { 0 };
	int res = larry[x - 'a'][y];
	larry_get[x - 'a'][y] = 1;

	if (sel == '1'){
		neighbour_get_N(larry, row, column, larry_get, x - 'a', y, res);
		print_result(larry, row, column, larry_get, 1);
	}

	else if (sel == '2'){
		neighbour_get_Y(larry, row, column, larry_get, x - 'a', y, res);
		print_result(larry, row, column, larry_get, 1);
	}

	else if (sel == '3'){
		neighbour_get_Y(larry, row, column, larry_get, x - 'a', y, res);
		print_result(larry, row, column, larry_get, 1);
		int score_sum = 0;
		score_sum += put_together_and_show_score(larry, row, column, larry_get, x - 'a', y, res, aim, score_sum);
	}

	else if (sel == '4'){
		int score_sum = 0;
		int flag_four = 0;

		while (1){
			if (flag_four == 1)
				print_larry(larry, row, column);

			while (flag_four == 1){
				cout << endl << "������ĸ+������ʽ[����c2]����������꣺";
				cin >> x >> y;

				if (!cin.good() || y > column || y < 0 || x<'a' || x>char(row + 'a')){
					cout << "���벻�Ϸ�������������";
					cin.clear();
					cin.ignore(65536, '\n');
					continue;
				}

				else{
					cin.clear();
					cin.ignore(65536, '\n');
				}
				cout << "����Ϊ" << x << "��" << y << "��" << endl << endl;

				int jud_adjoin;
				jud_adjoin = judge_neighbour(larry, row, column, x - 'a', y);

				if (jud_adjoin == 1){
					++flag_four;
					break;
				}

				else
					cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
			}

			for (int i = 0; i < row; ++i){
				for (int j = 0; j < column; ++j){
					larry_get[i][j] = 0;
				}
			}

			res = larry[x - 'a'][y];
			larry_get[x - 'a'][y] = 1;
			neighbour_get_Y(larry, row, column, larry_get, x - 'a', y, res);
			print_result(larry, row, column,larry_get, 1);
			int score_cur = put_together_and_show_score(larry, row, column, larry_get, x - 'a', y, res, aim, score_sum);

			flag_four = 1;

			if (score_cur == -1)
				break;

			else
				score_sum += score_cur;
			
			if (findmax(larry, row, column) >= aim){
				int x, y;
				cct_getxy(x, y);
				cct_showstr(x, y, "�Ѿ��ϳɵ�", COLOR_HYELLOW, COLOR_HRED);
				cct_showint(x + 10, y, aim, COLOR_HYELLOW, COLOR_HRED);
				cct_setcolor(0, 7);
				cout << endl << "���س������������Ŀ�����..." << endl;
				
				int sel_1;
				while (1){
					sel_1 = _getch();
					if (sel == 13){
						break;
					}
				}
				++aim;
			}
		}
	}

	game_ending(column);
	return;
}