#include<stdio.h>/*包含头文件*/
int move(int, char, char, char);/*引用move函数声明*/
int main()/*定义主函数*/
{
	int num = 0;/*将num初始化赋值为0*/
	int a;/*定义整型变量*/
	printf("输入汉诺塔层数：");
	scanf_s("%d", &a);/*读入用户输入的汉诺塔层数*/
	int c = move(a, 'X', 'Y', 'Z');
	printf("共移动%d次", num);/*打印移动的次数*/
	return 0;
}

int move(int n, char x, char y, char z)  /*借助y移动到z */
{
	int num = 0;/*定义num的初始值为0*/
	if (n == 1)/*归的终止条是= 1时，输出如何移动，本次调用结束，返回上一层*/
	{
		printf("%c--%c\n", x, z);
		num++;/*num自增*/
		return 0;
	}
	else
	{
		move(n - 1, x, z, y);/*使用move函数进行移动*/
		printf("%c--%c\n", x, z);
		num++;
		move(n - 1, y, x, z);/*再次使用move函数进行移动*/
	}/*首先借助C把A上n - 1个盘移到B上，此时A仅剩1个，直接移到C上，再把B上的n - 1个盘借助A移到C上。*/
	return num;
}