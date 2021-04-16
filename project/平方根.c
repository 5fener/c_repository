#include<stdio.h>
#include<math.h>/*包含两个头文件（其中一个为包含按数学函数的文件）*/
void main()/*定义空函数*/
{
	int a, b, c;/*定义三个整型变量*/
	float delta, d, x1, x2;/*定义方程两根及delta为浮点型变量*/
	printf("依次输入a,b,c的值:");
	scanf_s("%d%d%d", &a, &b, &c);/*读入方程*/
	delta = b * b - 4*a*c;/*定义delta*/
	if (delta < 0)
	{
		printf("该方程无实根");
	}/*delta<0对于者方程无实数根的情况*/
	else
	{
		d = sqrt(delta);
		x1 = (-b + d) / (2 * a);
		x2 = (-b - d) / (2 * a);/*利用求根公式对方程的根进行求解*/
		printf("该方程的根为%f    ,   %f", x1, x2);/*输出方程两根*/
	}

}