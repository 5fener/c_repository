#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"saolei.h"

int main()
{
	int input;
	//�����������
	srand((unsigned int)time(NULL));
	//ѭ��ʵ��
	do
	{
		Menu();

		scanf_s("%d", &input);
		switch (input)
		{
		case 1: Game();
		case 0:printf("�˳���Ϸ!\n");
			break;
		default:printf("�����������������");
			break;
		}
	} while (input);
	return 0;
}
