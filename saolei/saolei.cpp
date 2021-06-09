//������ͷ�ļ�

#include<stdio.h>
#include<stdlib.h>
#include"saolei.h"

// �˵���������ʾ��1������Ϸ����0�˳�

void Menu()
{
	printf("****************\n");
	printf("*****1.play*****\n");
	printf("*****0.exit*****\n");
	printf("****************\n");
}

//���̵ĳ�ʼ��

void Init_Mine(char Mine[ROW + 2][COL + 2], int row, int col)
{
	int i = 0;
	int j = 0;
	//������ά���飬�������ϵ����������ʼ��Ϊ0
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Mine[i][j] = '0';
		}
	}
}

//��ҽ����ʼ��

void Init_Board(char Board[ROW + 2][COL + 2], int row, int col)
{
	int i = 0;
	int j = 0;
	//������ά���飬�������ϵ����������ʼ��Ϊ�������*������ʾδ֪״̬
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Board[i][j] = '*';
		}
	}
}

//��������ף�0��Ϊû���ף�1��Ϊ���ף�

void Set_Mine(char Mine[ROW + 2][COL + 2], int row,int col)
{
	int i = 0;
	int j = 0;
	int count = 10;	//ͨ��ѭ����10����
	while (count--)
	{
		i = rand() % 10 + 1;		//ͨ��rand�������������0~9����1����0~10
		j = rand() % 10 + 1;		//ͨ��rand�������������0~9����1����0~10
		if (Mine[i][j] == '0')	//������������λ�����û�ף��Ͱ����λ�÷�����
		{
			Mine[i][j] = '1';
		}

		//������λ�����ף����λ�þͲ��ܷ��ˣ�Ҫ����λ�÷�
		//��ΪҪ����10���ף���ͨ��count�������ģ���Ϊ�ո�count��1����û�з���
		//���Դ�ʱ��count����1
		else
		{
			count++;
		}
	}
}

//����ÿ������Χ�׵ĸ���

int Calcu_Mine(char Mine[ROW + 2][COL + 2], int x, int y)
{
	//�����������ַ����ֵ�ASCII�����48����0=0��'0'=48�����Լ�ȥ'0'
	//ֱ�ӷ��ظ�λ����Χ8���������
	return (Mine[x - 1][y - 1] - '0' + Mine[x - 1][y] - '0'
		+ Mine[x - 1][y + 1] - '0' + Mine[x][y - 1] - '0'
		+ Mine[x][y + 1] - '0' + Mine[x + 1][y - 1] - '0'
		+ Mine[x + 1][y] - '0' + Mine[x + 1][y + 1] - '0');
}

//չ��������Χ���Ƿ�Ϊ0�����

void If_Blank(char Mine[ROW + 2][COL + 2], char Board[ROW + 2][COL + 2], int x, int y)
{	//����Calcu_Mine�����жϵ�ǰ�����Χ�Ƿ�Ϊ0��������չ��
	Board[x - 1][y - 1] = Calcu_Mine(Mine, x - 1, y - 1) + '0';
	Board[x - 1][y] = Calcu_Mine(Mine, x - 1, y) + '0';
	Board[x - 1][y + 1] = Calcu_Mine(Mine, x - 1, y + 1) + '0';
	Board[x][y - 1] = Calcu_Mine(Mine, x, y - 1) + '0';
	Board[x][y + 1] = Calcu_Mine(Mine, x, y + 1) + '0';
	Board[x + 1][y - 1] = Calcu_Mine(Mine,x + 1, y - 1) + '0';
	Board[x + 1][y] = Calcu_Mine(Mine, x + 1, y) + '0';
	Board[x + 1][y + 1] = Calcu_Mine(Mine, x + 1, y + 1) + '0';
}

//�����Ϸ����ʵ��

int Player(char Mine[ROW + 2][COL + 2], char Board[ROW + 2][COL + 2], int row, int col, int count)
{
	int x = 0;
	int y = 0;
	printf("����������>\n");
	//����Ϊ1��֤����һֱѭ��������������Ϸ����
	while (1)	
	{
		scanf_s("%d%d", &x, &y);
		//�ж���������δ��������
		if (x < 1 || x >= row || y < 1 || y >= col)
		{
			printf("���������������������>\n");
		}
		//������ȷ��δ�������ޣ��������
		else
		{
			if (count == 1)
			{
				//ʼ�ձ�֤��һ��ɨ���Ĳ�������
				if (Mine[x][y] == '1')
				{
					Mine[x][y] = '0';
					//ͨ��whileѭ�����������������δ�ȵ��׵����������̽���
					while (1)
					{
						if (Mine[rand() % 10 + 1][rand() % 10 + 1] == '0')
						{
							Mine[rand() % 10 + 1][rand() % 10 + 1] = '1';
							printf("���º�����̵Ľ���\n");
							Display(Mine, ROW + 2, COL + 2);
							break;
						}
					}
				}
			}
			//��֤�������겻�����Ѿ�ɨ��������
			if (Board[x][y] != '*')
			{
				printf("�˴��Ѿ���ɨ��������������λ��>\n");
			}
			else
				break;
		}
	}
	//���µ��ȵ���ʱ�����չʾ���沢��������
	if (Mine[x][y] == '1')
	{
		Board[x][y] = '1';
		Display(Board, ROW + 2, COL + 2);
		printf("������������ȵ����ˣ�GAME OVER������\n");
		return 0;
	}
	//���µ���Χλ��û����ʱ�����
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

//չʾ���̵Ľ���

void Display(char board[ROW + 2][COL + 2], int row, int col)
{
	int i = 0;
	int j = 0;
	//��ʾ���̽���ĺ�������
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

//�ж����ʤ��
//��������10��������δ��������½���ֻʣ��10��*���ţ����ж������Ϸʤ��

int Is_Win(char Board[ROW + 2][COL+ 2], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	//�������*�ܸ���
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			if (Board[i][j] == '*')
			{
				count++;
			}
	}
	//��*��=��������Ϸʤ��
	if (count == 10)
	{
		printf("��������׶�����ɨ������\n");
		return 1;
	}
	return 0;
}

//��Ϸ����ʵ��

void Game()
{
	//��ʼ������
	char Mine[ROW + 2][COL + 2] = { 0 };
	char Board[ROW + 2][COL + 2] = { 0 };
	//���ø�������
	Init_Mine(Mine, ROW + 2, COL + 2);
	Set_Mine(Mine, ROW + 2, COL + 2);
	Display(Mine, ROW + 2, COL + 2);
	Init_Board(Board, ROW + 2, COL + 2);
	Display(Board, ROW + 2, COL + 2);
	//���ó�ʼֵ
	int ret = 0;
	int count = 1;
	//���ú���ʵ����Ϸ����չʾˢ�º���Ϸʤ���ж�
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
