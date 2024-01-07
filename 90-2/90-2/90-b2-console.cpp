/* 2150248 信18 姚天亮*/
//放cmd伪图形界面方式实现的各函数
//本函数219行处放鼠标功能
//417行这部分需要考虑如何切换到鼠标
#include <iostream>
#include <iomanip>
#include <string.h>
#include <Windows.h>
#include<conio.h>
#include"cmd_console_tools.h"
#include"90-b2.h"
using namespace std;

void initial_picture(char sel)
{
	cct_setcursor(CURSOR_INVISIBLE);
	int row, column;
	cct_cls();

	cout << "请输入行数(5-8)：";
	while (1) {
		cin >> row;

		if (!cin.good() || row > 8 || row < 5) {
			cout << "输入不合法，请重新输入";
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

	cout << "请输入列数(5-10)：";
	while (1) {
		cin >> column;
		if (!cin.good() || column > 10 || column < 5) {
			cout << "输入不合法，请重新输入";
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

	int larry[8][10] = { 0 };
	int larry_get[8][10] = { 0 };
	int aim = 0;
	if (sel == '8' || sel == '9') {
		cout << "请输入合成目标(5-20)：";
		while (1) {
			cin >> aim;
			if (!cin.good() || aim > 20 || aim < 5) {
				cout << "输入不合法，请重新输入";
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

	set(larry, row, column);

	if (sel == '5') {
		int a, b, c, d;
		cct_getconsoleborder(a, b, c, d);
		cct_setcolor();
		cct_cls();
		get_picture_size(row, column, false, c, d);
		d += 5;
		c += 4;
		cct_setconsoleborder(c, d + 5);
		cct_gotoxy(0, 0);
		cout << "屏幕当前设置为：" << c << "行" << d << "列";

		print_border(row, column, false);

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < column; ++j) {
				print_blank(i, j, larry[i][j], false);
				Sleep(30);
			}
		}

		cct_setcolor();
		set_botton_line();
		game_ending(column);
		cct_setconsoleborder(a, b);
	}

	if (sel == '6') {
		int a, b, c, d;
		cct_getconsoleborder(a, b, c, d);
		cct_setcolor();
		cct_cls();
		get_picture_size(row, column, true, c, d);
		d += 5;
		cct_setconsoleborder(c, d + 5);
		cct_gotoxy(0, 0);
		cout << "屏幕当前设置为：" << c << "行" << d << "列";
		print_border(row, column, true);
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < column; ++j) {
				print_blank(i, j, larry[i][j], true);
				Sleep(30);
			}
		}
		cct_setcolor();
		set_botton_line();
		game_ending(column);
		cct_setconsoleborder(a, b);
	}

	//7 8 9都要加鼠标
	if (sel == '7') {
		int a, b, c, d, e;
		cct_getconsoleborder(a, b, c, d);
		cct_setcolor();
		cct_cls();
		get_picture_size(row, column, true, c, d);
		d += 5;
		cct_setconsoleborder(c, d + 5);
		cct_gotoxy(0, 0);
		cout << "屏幕当前设置为：" << c << "行" << d << "列";
		print_border(row, column, true);

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < column; ++j) {
				print_blank(i, j, larry[i][j], true);
				Sleep(30);
			}
		}
		int x, y, lastX, lastY;
		x = y = lastX = lastY = 0;

		//在这里加鼠标！！！
		while (true) {
			//这里加了个enable_mouse，暂时没反应
			cct_enable_mouse();
			//读键盘鼠标
			if (cct_read_keyboard_and_mouse(a, b, c, d, e) == CCT_KEYBOARD_EVENT) {
				if (d == 13)
					break;
				switch (e) {
					//这里加了个左键的虚拟值，没反应......
					case VK_LBUTTON:
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (--y < 0) {
							y = row - 1;
						}
						lastY = y;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_UP:
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (--y < 0) {
							y = row - 1;
						}
						lastY = y;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_DOWN:
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (++y >= row) {
							y = 0;
						}
						lastY = y;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_LEFT:
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (--x < 0) {
							x = column - 1;
						}
						lastX = x;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_RIGHT:
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (++x >= column) {
							x = 0;
						}
						lastX = x;
						print_blank(y, x, larry[y][x] , true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					default:
						break;
				}
			}
		}
		cct_setcolor();
		set_botton_line();
		game_ending(column);
		cct_setconsoleborder(a, b);
	}

	if (sel == '8') {
		int a, b, c, d, e;
		cct_getconsoleborder(a, b, c, d);
		cct_setcolor();
		cct_cls();
		get_picture_size(row, column, true, c, d);
		d += 5;
		cct_setconsoleborder(c, d + 5);
		cct_gotoxy(0, 0);
		cout << "屏幕当前设置为：" << c << "行" << d << "列";
		print_border(row, column, true);

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < column; ++j) {
				print_blank(i, j, larry[i][j], true);
				Sleep(30);
			}
		}

		int x, y, lastX, lastY;
		x = y = lastX = lastY = 0;
		bool sure = false;
		print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);

		//在这里加鼠标
		//鼠标不会
		while (1) {
			cct_enable_mouse();   //允许使用鼠标
			if (cct_read_keyboard_and_mouse(a, b, c, d, e) == CCT_KEYBOARD_EVENT) {
				set_botton_line();
				cct_setcolor();
				cout << "箭头键/鼠标移动，回车键/鼠标选择                  ";
				//
				if (d == 13) {
					if (!judge_neighbour(larry, row, column, y, x)) {
						set_botton_line();
						cct_setcolor(0, COLOR_HYELLOW);
						cout << "周围无相同值";
						cct_setcolor();
						cout << "箭头键/鼠标移动，回车键/鼠标选择";
					}
					else {
						if (sure == 0) {
							for (int i = 0; i < row; ++i) {
								for (int j = 0; j < column; ++j) {
									larry_get[i][j] = 0;
								}
							}
							neighbour_get_Y(larry, row, column, larry_get, y, x, larry[y][x]);
						}
						else {         //当再次按下回车键时,确认要合并时
							int res = larry[y][x];
							int merge_sum = show_neighbour(larry, row, column, larry_get, y, x);
							int score_cur = score(res, merge_sum);
							cct_setcolor(); cct_gotoxy(0, 0);
							cout << "本次得分：" << score_cur << " 总得分：" << score_cur << " 合成目标：" << aim;
							for (int i = 0; i < row; ++i) {
								for (int j = 0; j < column; j++) {
									if (larry_get[i][j]) {
										print_blank(i, j, larry[i][j], true, COLOR_HWHITE, COLOR_HWHITE);//涂白
									}
								}
							}
							//闪烁
							for (int i = 0; i < 5; ++i) {
								print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_HRED);
								Sleep(100);
								print_blank(y, x, larry[y][x], true);
								Sleep(100);
							}

							cct_setcolor(); 
							set_botton_line();
							cout << "合成完成，回车键下落0                ";
							int cmd;
							while (1) {
								cmd = _getch();
								if (cmd == 13) {
									break;
								}
							}

							larry_get[y][x] = 0;
							move(larry, larry_get, row, column);
							down(larry, row, column);
							cct_setcolor(); 
							set_botton_line();
							cout << "下落0完成，回车键/鼠标左键填充新值                ";
							while (1) {
								cmd = _getch();
								if (cmd == 13) {
									break;
								}
							}

							int max = findmax(larry, row, column);
							for (int i = 0; i < row; ++i){
								for (int j = 0; j < column; ++j){
									if (larry[i][j] == 0) {
										Sleep(200);
										larry[i][j] = rand_int(max);
										print_blank(i, j, larry[i][j], true);    //填充新值
									}
								}
							}

							cct_setcolor();
							set_botton_line();
							game_ending(column);
							cct_setconsoleborder(a, b);
							return;
						}

						for (int i = 0; i < row; ++i) {
							for (int j = 0; j < column; ++j) {
								if (larry_get[i][j]) {
									print_blank(i, j, larry[i][j], true, COLOR_HYELLOW, COLOR_CYAN);
								}
							}
						}
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_HRED);
						sure = true;
					}
				}
				if (sure && d != 13) {
					for (int i = 0; i < row; ++i) {
						for (int j = 0; j < column; ++j) {
							if (larry_get[i][j]) {
								print_blank(i, j, larry[i][j], true);
							}
						}
					}
					print_blank(lastY, lastX, larry[lastY][lastX], true);
					sure = false;
				}
				switch (e){
					case VK_LBUTTON:
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (--y < 0) {
							y = row - 1;
						}
						lastY = y;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_UP:
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (--y < 0) {
							y = row - 1;
						}
						lastY = y;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_DOWN:
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (++y >= row) {
							y = 0;
						}
						lastY = y;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_LEFT:
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (--x < 0) {
							x = column - 1;
						}
						lastX = x;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_RIGHT:
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (++x >= column) {
							x = 0;
						}
						lastX = x;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					default:
						break;
				}
			}
		}
		cct_setcolor();
		set_botton_line();
		game_ending(column);
		cct_setconsoleborder(a, b);
	}

	if (sel == '9') {
		int a, b, c, d, e;
		int score_total = 0;

		cct_getconsoleborder(a, b, c, d);
		cct_setcolor();
		cct_cls();
		get_picture_size(row, column, true, c, d);
		d += 5;
		cct_setconsoleborder(c, d + 5);
		cct_gotoxy(0, 0);

		cout << "屏幕当前设置为：" << c << "行" << d << "列";
		print_border(row, column, true);

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < column; ++j) {
				print_blank(i, j, larry[i][j], true);
				Sleep(30);
			}
		}
		int x, y, lastX, lastY;
		x = y = lastX = lastY = 0;

		int sure = false;
		bool enter = false;

		print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
		while (true) {
			//这里该如何切换鼠标？我不会
			if (cct_read_keyboard_and_mouse(a, b, c, d, e) == CCT_KEYBOARD_EVENT) { 
				set_botton_line();
				cct_setcolor();
				cout << "箭头键/鼠标移动，回车键/鼠标左键选择                                                  ";
				if (d == 13) {
					if (!judge_neighbour(larry, row, column, y, x)) {
						set_botton_line();
						cct_setcolor(0, COLOR_HYELLOW);
						cout << "周围无相同值";
						cct_setcolor();
						cout << "箭头键/鼠标移动，回车键/鼠标左键选择";
					}
					else {
						if (sure == 0) {
							for (int i = 0; i < row; ++i) {
								for (int j = 0; j < column; ++j) {
									larry_get[i][j] = 0;
								}
							}
							neighbour_get_Y(larry, row, column, larry_get, y, x, larry[y][x]);
						}
						//当再次按下回车键时,确认要合并时
						else {
							if (!enter) {
								sure = 3;
								int res = larry[y][x];
								int merge_sum = show_neighbour(larry, row, column, larry_get, y, x);
								int score_cur = score(res, merge_sum);
								score_total += score_cur;
								cct_setcolor(); cct_gotoxy(0, 0);
								cout << "本次得分：" << score_cur << " 总得分：" << score_total << " 合成目标：" << aim << "     ";
							}
							for (int i = 0; i < row; ++i) {
								for (int j = 0; j < column; ++j) {
									if (larry_get[i][j]) {
										print_blank (i, j, larry[i][j], true, COLOR_HWHITE, COLOR_HWHITE);//涂白
									}
								}
							}
							enter = true;

							//闪烁
							for (int i = 0; i < 5; ++i) {
								print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_HRED);
								Sleep(100);
								print_blank(y, x, larry[y][x], true);
								Sleep(100);
							}

							larry_get[y][x] = 0;
							move(larry, larry_get, row, column);
							down(larry, row, column);

							int max = findmax(larry, row, column);
							for (int i = 0; i < row; ++i) {
								for (int j = 0; j < column; ++j) {
									if (larry[i][j] == 0) {
										Sleep(00);
										larry[i][j] = rand_int(max);
										print_blank(i, j, larry[i][j], true);    //填充新值
									}
								}
							}
							for (int i = 0; i < row; ++i) {
								for (int j = 0; j < column; ++j) {
									larry_get[i][j] = 0;
								}
							}
							if (findmax(larry, row, column) >= aim) {
								set_botton_line();
								cct_setcolor(0, COLOR_HYELLOW);

								cout << "已经合成到" << aim;
								cct_setcolor();
								cout << "按回车键继续向更高目标进发...     ";

								int cmd;
								while (1) {
									cmd = _getch();
									if (cmd == 13) {
										break;
									}
								}
								++aim;
							}
							set_botton_line();
							cct_setcolor();
							cout << "箭头键/鼠标移动，回车键/鼠标左键选择                    ";
							sure = 2;

						}

						for (int i = 0; i < row; i++) {
							for (int j = 0; j < column; j++) {
								if (larry_get[i][j]) {
									print_blank(i, j, larry[i][j], true, COLOR_HYELLOW, COLOR_CYAN);

								}
							}
						}
						if (sure != 2)
							print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_HRED);
						else 
							print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);

						sure = true;
					}

				}
				if (sure && d != 13) {
					for (int i = 0; i < row; ++i) {
						for (int j = 0; j < column; ++j) {
							if (larry_get[i][j]) {
								print_blank(i, j, larry[i][j], true);
							}
						}
					}
					print_blank(lastY, lastX, larry[lastY][lastX], true);
					sure = false;
				}


				switch (e) {
					case VK_LBUTTON:
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (--y < 0) {
							y = row - 1;
						}
						lastY = y;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_UP:
						enter = false;
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (--y < 0) {
							y = row - 1;
						}
						lastY = y;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_DOWN:
						enter = false;
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (++y >= row) {
							y = 0;
						}
						lastY = y;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_LEFT:
						enter = false;
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (--x < 0) {
							x = column - 1;
						}
						lastX = x;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_RIGHT:
						enter = false;
						print_blank(lastY, lastX, larry[lastY][lastX], true);
						if (++x >= column) {
							x = 0;
						}
						lastX = x;
						print_blank(y, x, larry[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					default:
						break;
				}
			}
		}
		cct_setcolor();
		set_botton_line();
		game_ending(column);
		cct_setconsoleborder(a, b);
	}
}

void print_blank(int card_y, int card_x, int value, bool haveBorder, int bgcolor, int fgcolor)
{
	int x = (haveBorder) ? (2 + card_x * 6 + card_x * 2) : (2 + card_x * 6);
	int y = (haveBorder) ? (2 + card_y * 3 + card_y) : (2 + card_y * 3);

	if (bgcolor != -1)
		cct_setcolor(bgcolor, fgcolor);
	else 
		cct_setcolor(value);

	cct_gotoxy(x, y);
	cout << "╔═╗";
	cct_gotoxy(x, y + 1);

	if (value < 10) {
		cout << "║ " << value << "║";
	}

	else {
		cout << "║" << value << "║";
	}

	cct_gotoxy(x, y + 2);
	cout << "╚═╝";
}

void print_border(int row, int column, bool haveBorder)
{
	int temp = row;
	row = column;
	column = temp;
	cct_gotoxy(0, 1);
	//width hight是指的内容中的宽高
	int width = (haveBorder) ? row * 2 * 3 + (row - 1) * 2 :
		row * 2 * 3;
	int hight = (haveBorder) ? column * 3 + (column - 1) : column * 3;
	set_botton_line(true, haveBorder ? hight + 3 : hight + 2); //更新
	int unicode_rowLength = (width + 4) / 2;
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cout << "╔";

	for (int i = 0; i < unicode_rowLength - 2; ++i) {
		cout << "═";
		Sleep(30);
	}
	cout << "╗";

	for (int i = 0; i < hight + 1; ++i) {
		cct_gotoxy(0, i + 2); cout << "║";
		cct_gotoxy(width + 2, i + 2); cout << "║";
		Sleep(30);
	}

	cct_gotoxy(0, hight + 2);
	cout << "╚";

	for (int i = 0; i < unicode_rowLength - 2; ++i) {
		cout << "═";
		Sleep(30);
	}
	cout << "╝";

	if (haveBorder) {
		for (int i = 0; i < column - 1; ++i) {
			cct_gotoxy(2, i * 4 + 5);
			cout << "\b\b╟";
			for (int j = 0; j < width / 2; ++j) {
				cout << "─";
				Sleep(5);
			}
			cout << "╢";
		}
		int j = 0;
		for (int i = 0; i < row - 1; ++i) {
			cct_gotoxy(2 * 4 + i * 8, 1);
			cout << "╤";
			for (j = 0; j < hight; j++) {
				cct_gotoxy(2 * 4 + i * 8, 2 + j);
				cout << "│";
				if (!((j + 1) % 4)) {
					cout << "\b\b┼";
					Sleep(30);
				}
			}
			cct_gotoxy(2 * 4 + i * 8, 2 + j);
			cout << "╧";
		}
	}
}

void set_botton_line(bool set, int value)
{
	static int pox_Y = 0;
	if (set){
		pox_Y = value;
	}
	else
		cct_gotoxy(0, pox_Y);
}

void get_picture_size(int row, int column, bool haveBorder, int& width, int& heigh)
{
	int temp = row;
	row = column;
	column = temp;
	width = (haveBorder) ? row * 2 * 3 + (row + 1) * 2 :
		row * 2 * 3;
	heigh = (haveBorder) ? column * 3 + (column) : column * 3;
}

void card_fall_smooth(int card_x, int card_y, int value)
{
	int x = 2 + card_x * 6 + card_x * 2;
	int y = 2 + card_y * 3 + card_y;
	int i;
	for (i = 1; i < 5; ++i){
		++y;
		cct_gotoxy(x, y - 1);
		cct_setcolor(15, 0);
		cout << "      ";
		cct_gotoxy(x, y);
		cct_setcolor(value);
		cout << "╔═╗";
		cct_gotoxy(x, y + 1);

		if (value < 10){
			cout << "║ " << value << "║";
		}
		else{
			cout << "║" << value << "║";
		}
		cct_gotoxy(x, y + 2);
		cout << "╚═╝";
		Sleep(30);
	}

	cct_setcolor(15, 0);
	cct_gotoxy(x, y - 1);
	cct_setcolor(15, 0);
	cout << "───";
}

void move(int larry[][10], int larry_get[][10], int row, int column)
{
	//倒着扫描
	int width = row;
	int hight = column;
	for (int j = 0; j < column; ++j) { //第一列扫描
		for (int i = row - 1; i >= 0; --i) {//从最后一行开始扫描
			if (larry_get[i][j]) {
				int num = 0; //空隙的数量
				int k;
				for (k = i; k >= 0; --k) {
					if (larry_get[k][j]==0)
						break;  //如果向上有占用
					if (k == 0) {
						num = 0; 
						break;
					}
					++num;
				}
				if (num) {
					larry_get[k][j] = 1;
					larry_get[i][j] = 0;
				}
				for (int a = 0; a < num; ++a) {
					card_fall_smooth(j, k + a, larry[k][j]);
				}
			}
		}
	}
}