#ifndef __SAOLEI_H__    

//防止头文件被重复引用后，当预处理是在主函数里头文件被多次替换而耗时,当使用这条语句后，可避免头文件的重复引用

#define __SAOLEI_H__

#define ROW 10

#define COL 10

//菜单

void Menu();

//游戏

void Game();

//雷的初始化

void Init_Mine(char Mine[ROW + 2][COL + 2], int row, int col);

//雷盘的初始化

void Init_Board(char Board[ROW + 2][COL + 2], int row, int col);

//设置雷

void Set_Mine(char Mine[ROW + 2][COL + 2], int row, int col);

//计算每个空周围雷的个数

int Calcu_Mine(char Mine[ROW + 2][COL + 2], int x, int y);

//展示雷盘

void Display(char board[ROW + 2][COL + 2], int row, int col);

//玩家扫雷

int Player(char Mine[ROW + 2][COL + 2], char Board[ROW + 2][COL + 2], int row, int col, int count);

//判断是否赢

int Is_Win(char Board[ROW + 2][COL + 2], int row, int col);

//当前格和周围的几个格是不是0，若是则展开

void If_Blank(char Mine[ROW + 2][COL + 2], char Board[ROW + 2][COL + 2], int x, int y);

#endif//__SAOLEI_H__
