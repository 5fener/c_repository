#ifndef __SAOLEI_H__    

//��ֹͷ�ļ����ظ����ú󣬵�Ԥ����������������ͷ�ļ�������滻����ʱ,��ʹ���������󣬿ɱ���ͷ�ļ����ظ�����

#define __SAOLEI_H__

#define ROW 10

#define COL 10

//�˵�

void Menu();

//��Ϸ

void Game();

//�׵ĳ�ʼ��

void Init_Mine(char Mine[ROW + 2][COL + 2], int row, int col);

//���̵ĳ�ʼ��

void Init_Board(char Board[ROW + 2][COL + 2], int row, int col);

//������

void Set_Mine(char Mine[ROW + 2][COL + 2], int row, int col);

//����ÿ������Χ�׵ĸ���

int Calcu_Mine(char Mine[ROW + 2][COL + 2], int x, int y);

//չʾ����

void Display(char board[ROW + 2][COL + 2], int row, int col);

//���ɨ��

int Player(char Mine[ROW + 2][COL + 2], char Board[ROW + 2][COL + 2], int row, int col, int count);

//�ж��Ƿ�Ӯ

int Is_Win(char Board[ROW + 2][COL + 2], int row, int col);

//��ǰ�����Χ�ļ������ǲ���0��������չ��

void If_Blank(char Mine[ROW + 2][COL + 2], char Board[ROW + 2][COL + 2], int x, int y);

#endif//__SAOLEI_H__
