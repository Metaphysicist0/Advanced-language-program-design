/* 2150248 信18 姚天亮 */
//放内部数组方式实现的各函数
//缺鼠标实现
#include<iostream>
#include<conio.h>
#include<iomanip>
#include"cmd_console_tools.h"
#include"90-b2.h"
using namespace std;

//打印数组
void print_larry(int larry[][10], int row, int column)//打印数组
{
	cout << "当前数组：" << endl;
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

//归并与计分的显示
int put_together_and_show_score(int larry[][10], int row, int column, int larry_get[][10], int x, int y, int res, int target, int score_sum)
{
	cout << "请确认是否把相邻的相同值合并到c2中(Y/N/Q)：";
	char sel_1;

	while (1){
		sel_1 = _getch();
		if (sel_1 == 'y' || sel_1 == 'Y'){
			cout << "y" << endl << endl;
			cout << "相同值归并后的数组(不同色标识)：" << endl;
			int show_sum = show_neighbour(larry, row, column,larry_get, x, y);
			print_result(larry, row, column,larry_get, 0);
			int score_thistime = score(res, show_sum);
			score_sum += score_thistime;
			cout << endl << "本次得分：" << score_thistime << " 总得分：" << score_sum << " 合成目标：" << target << endl;
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

//下落除0操作
void print_removeZero(int larry[][10], int row, int column, int larry_get[][10])
{
	cout << endl << "按回车键进行数组下落除0操作..." << endl;
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
	cout << "除0后的数组(不同色标识)：" << endl;
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

	cout << endl << "按回车键进行新值填充..." << endl;
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

	cout << "新值填充后的数组(不同色标识)：" << endl;
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

	cout << endl << "本次合成结束，按回车键继续新一次的合成..." << endl;
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

//打印消去后的结果
void print_result(int larry[][10], int row, int column, int larry_get[][10], int flag)
{
	if (flag == 1){
		cout << "查找结果数组：" << endl;
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

		cout << endl << endl << "当前数组(不同色标识)：" << endl;
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

//初始化，一个很大的函数，和菜单有关的
void chushihua(char sel)
{
	int row, column;
	cct_cls();
	cout << "请输入行数(5-8)：";
	while (1){
		cin >> row;
		if (!cin.good() || row > 8 || row < 5){
			cout << "输入不合法，请重新输入";
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

	cout << "请输入列数(5-10)：";
	while (1){
		cin >> column;
		if (!cin.good() || column > 10 || column < 5){
			cout << "输入不合法，请重新输入";
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
		cout << "请输入合成目标(5-20)：";
		while (1){
			cin >> aim;
			if (!cin.good() || aim > 20 || aim < 5){
				cout << "输入不合法，请重新输入";
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
		cout << endl << "请以字母+数字形式[例：c2]输入矩阵坐标：";
		cin >> x >> y;

		if (!cin.good() || y > column || y < 0 || x < 'a' || x>char(row + 'a')){
			cout << "输入不合法，请重新输入"<<endl;
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}

		else{
			cin.clear();
			cin.ignore(65536, '\n');
		}
		cout << "输入为" << x << "行" << y << "列" << endl << endl;

		int judge_the_same;
		judge_the_same = judge_neighbour(larry, row, column, x - 'a', y);
		if (judge_the_same == 1)
			break;
		else
			cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
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
				cout << endl << "请以字母+数字形式[例：c2]输入矩阵坐标：";
				cin >> x >> y;

				if (!cin.good() || y > column || y < 0 || x<'a' || x>char(row + 'a')){
					cout << "输入不合法，请重新输入";
					cin.clear();
					cin.ignore(65536, '\n');
					continue;
				}

				else{
					cin.clear();
					cin.ignore(65536, '\n');
				}
				cout << "输入为" << x << "行" << y << "列" << endl << endl;

				int jud_adjoin;
				jud_adjoin = judge_neighbour(larry, row, column, x - 'a', y);

				if (jud_adjoin == 1){
					++flag_four;
					break;
				}

				else
					cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
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
				cct_showstr(x, y, "已经合成到", COLOR_HYELLOW, COLOR_HRED);
				cct_showint(x + 10, y, aim, COLOR_HYELLOW, COLOR_HRED);
				cct_setcolor(0, 7);
				cout << endl << "按回车键继续向更高目标进发..." << endl;
				
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