#include<stdio.h>
#include<math.h>/*包含头文件（其中一个头文件包含各种数学函数）*/
void main()/*主函数返回类型为空*/
{
	int x,i,y;/*定义三个整型变量*/
	scanf_s("%d", &x);/*读入用户输入的数*/
	y = sqrt(x);/*用sqrt函数对x开根号*/
	if (x % 2 == 0)/*如果x能被2整除*/
	{
		printf("该数不是素数");/*则一定不是素数*/
	}
	else
	{
		printf("该数为素数");/*打印“该数为素数*/
	}
	for (i = 2; i <= y; i++)
	{
		if (x % i == 0)/*如果x能被i整除*/
		{
			printf("能");/*则打印“能”*/
		}
		else
		{
			printf("否");/*否则打印“否”*/
		}
	}
}