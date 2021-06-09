//包含的头文件

#include<stdio.h>
#include<stdlib.h>
#include"saolei.h"

// 菜单函数，提示按1进入游戏，按0退出

void Menu()
{
	printf("****************\n");
	printf("*****1.play*****\n");
	printf("*****0.exit*****\n");
	printf("****************\n");
}

//雷盘的初始化

void Init_Mine(char Mine[ROW + 2][COL + 2], int row, int col)
{
	int i = 0;
	int j = 0;
	//遍历二维数组，将雷盘上的所有坐标初始化为0
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Mine[i][j] = '0';
		}
	}
}

//玩家界面初始化

void Init_Board(char Board[ROW + 2][COL + 2], int row, int col)
{
	int i = 0;
	int j = 0;
	//遍历二维数组，将雷盘上的所有坐标初始化为特殊符号*，即表示未知状态
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Board[i][j] = '*';
		}
	}
}

//随机放置雷（0视为没有雷，1视为有雷）

void Set_Mine(char Mine[ROW + 2][COL + 2], int row,int col)
{
	int i = 0;
	int j = 0;
	int count = 10;	//通过循环放10个雷
	while (count--)
	{
		i = rand() % 10 + 1;		//通过rand函数产生随机数0~9，加1后是0~10
		j = rand() % 10 + 1;		//通过rand函数产生随机数0~9，加1后是0~10
		if (Mine[i][j] == '0')	//随机产生的这个位置如果没雷，就把这个位置放上雷
		{
			Mine[i][j] = '1';
		}

		//如果这个位置有雷，这个位置就不能放了，要换个位置放
		//因为要产生10个雷，是通过count来计数的，因为刚刚count减1，但没有放雷
		//所以此时给count加上1
		else
		{
			count++;
		}
	}
}

//计算每个空周围雷的个数

int Calcu_Mine(char Mine[ROW + 2][COL + 2], int x, int y)
{
	//整形数字与字符数字的ASCII码相差48，而0=0，'0'=48，所以减去'0'
	//直接返回该位置周围8个点的雷数
	return (Mine[x - 1][y - 1] - '0' + Mine[x - 1][y] - '0'
		+ Mine[x - 1][y + 1] - '0' + Mine[x][y - 1] - '0'
		+ Mine[x][y + 1] - '0' + Mine[x + 1][y - 1] - '0'
		+ Mine[x + 1][y] - '0' + Mine[x + 1][y + 1] - '0');
}

//展开格与周围格是否为0的情况

void If_Blank(char Mine[ROW + 2][COL + 2], char Board[ROW + 2][COL + 2], int x, int y)
{	//调用Calcu_Mine函数判断当前格和周围是否为0，若是则展开
	Board[x - 1][y - 1] = Calcu_Mine(Mine, x - 1, y - 1) + '0';
	Board[x - 1][y] = Calcu_Mine(Mine, x - 1, y) + '0';
	Board[x - 1][y + 1] = Calcu_Mine(Mine, x - 1, y + 1) + '0';
	Board[x][y - 1] = Calcu_Mine(Mine, x, y - 1) + '0';
	Board[x][y + 1] = Calcu_Mine(Mine, x, y + 1) + '0';
	Board[x + 1][y - 1] = Calcu_Mine(Mine,x + 1, y - 1) + '0';
	Board[x + 1][y] = Calcu_Mine(Mine, x + 1, y) + '0';
	Board[x + 1][y + 1] = Calcu_Mine(Mine, x + 1, y + 1) + '0';
}

//玩家游戏操作实现

int Player(char Mine[ROW + 2][COL + 2], char Board[ROW + 2][COL + 2], int row, int col, int count)
{
	int x = 0;
	int y = 0;
	printf("请输入坐标>\n");
	//设置为1保证可以一直循环输入坐标至游戏结束
	while (1)	
	{
		scanf_s("%d%d", &x, &y);
		//判断输入坐标未超出界限
		if (x < 1 || x >= row || y < 1 || y >= col)
		{
			printf("坐标输入错误，请重新输入>\n");
		}
		//输入正确（未超过界限）的坐标后
		else
		{
			if (count == 1)
			{
				//始终保证第一次扫到的不会是雷
				if (Mine[x][y] == '1')
				{
					Mine[x][y] = '0';
					//通过while循环根据输入坐标更新未踩到雷的情况后的雷盘界面
					while (1)
					{
						if (Mine[rand() % 10 + 1][rand() % 10 + 1] == '0')
						{
							Mine[rand() % 10 + 1][rand() % 10 + 1] = '1';
							printf("更新后的雷盘的界面\n");
							Display(Mine, ROW + 2, COL + 2);
							break;
						}
					}
				}
			}
			//保证输入坐标不包括已经扫过的坐标
			if (Board[x][y] != '*')
			{
				printf("此处已经被扫过，请重新输入位置>\n");
			}
			else
				break;
		}
	}
	//更新当踩到雷时的情况展示界面并结束程序
	if (Mine[x][y] == '1')
	{
		Board[x][y] = '1';
		Display(Board, ROW + 2, COL + 2);
		printf("哈哈哈哈，你踩到雷了，GAME OVER！！！\n");
		return 0;
	}
	//更新当周围位置没有雷时的情况
	else
	{
		Board[x][y] = Calcu_Mine(Mine, x, y) + '0';
		if (Calcu_Mine(Mine, x, y) == 0)
		{
			If_Blank(Mine, Board, x, y);
		}
		return 1;
	}
}

//展示雷盘的界面

void Display(char board[ROW + 2][COL + 2], int row, int col)
{
	int i = 0;
	int j = 0;
	//显示雷盘界面的横纵坐标
	printf("   1 2 3 4 5 6 7 8 9 10\n");
	printf("---------------------- \n");
	for (i = 1; i < row - 1; i++)
	{
		printf("%-2d", i);
		printf("|");
		for (j=1;j<col-1;j++)
		{
			printf("%c", board[i][j]);
			printf(" ");
		}
		printf("---------------------- \n");
	}
}

//判断玩家胜利
//总雷数共10个，若在未踩雷情况下界面只剩下10个*符号，则判断玩家游戏胜利

int Is_Win(char Board[ROW + 2][COL+ 2], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	//遍历输出*总个数
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			if (Board[i][j] == '*')
			{
				count++;
			}
	}
	//当*数=雷数，游戏胜利
	if (count == 10)
	{
		printf("你真棒，雷都被你扫完啦！\n");
		return 1;
	}
	return 0;
}

//游戏函数实现

void Game()
{
	//初始化雷盘
	char Mine[ROW + 2][COL + 2] = { 0 };
	char Board[ROW + 2][COL + 2] = { 0 };
	//调用各级函数
	Init_Mine(Mine, ROW + 2, COL + 2);
	Set_Mine(Mine, ROW + 2, COL + 2);
	Display(Mine, ROW + 2, COL + 2);
	Init_Board(Board, ROW + 2, COL + 2);
	Display(Board, ROW + 2, COL + 2);
	//设置初始值
	int ret = 0;
	int count = 1;
	//调用函数实现游戏界面展示刷新和游戏胜利判断
	while (1)
	{
		ret = Player(Mine, Board, ROW + 2, COL + 2, count++);
		Display(Board, ROW + 2, COL + 2);
		if (ret == 0)
		{
			break;
		}
		if (Is_Win(Board, ROW + 2, COL + 2) == 1)
		{
			Display(Mine, ROW + 2, COL + 2);
			break;
		}
	}
}
