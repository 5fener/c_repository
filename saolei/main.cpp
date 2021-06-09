#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"saolei.h"

int main()
{
	int input;
	//随机数发生器
	srand((unsigned int)time(NULL));
	//循环实现
	do
	{
		Menu();

		scanf_s("%d", &input);
		switch (input)
		{
		case 1: Game();
		case 0:printf("退出游戏!\n");
			break;
		default:printf("输入错误，请重新输入");
			break;
		}
	} while (input);
	return 0;
}
