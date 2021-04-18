#include<stdio.h>	//包含标准输入输出头文件

int main()
{
	int iNum_1, iNum_2;	//声明两个int变量
	char cOp;	//声明char变量
	char cAnswer = 'y';	//声明char变量并赋值y
	do
	{
		printf("-------------Calculator with two numbers------------\n");	
		printf("Please input two numbers and operator:\n");	//提示输入信息
		scanf("%d%c%d", &iNum_1, &cOp,sizeof(cOp), &iNum_2);	//键入变量
		
		switch (cOp)		//switch选择语句
		{
		case'+':		//cOp为 + 的情况
			printf("%d+%d=%d\n", iNum_1, iNum_2, iNum_1 + iNum_2);
			break;	//跳出选择语句
		case'-':		//cOp为 - 的情况
			printf("%d-%d=%d\n", iNum_1, iNum_2, iNum_1 - iNum_2);
			break;
		case'*':		//cOp为 * 的情况
			printf("%d*%d=%d\n", iNum_1, iNum_2, iNum_1 * iNum_2);
			break;
		case'/':		//cOp为 / 的情况
			printf("%d/%d=%d\n", iNum_1, iNum_2, iNum_1 / iNum_2);
			break;
		default:		//默认情况
			printf("Input error,please re-enter!\n");
			break;
		}
		printf("Do you still need to enter it agin,if necessary enter 'y',or any other 'y'");	//提示信息
		cAnswer = getchar();		//键入字符cAnswer的值
	} while (cAnswer == 'y');	//当cAnswer='y'时进行循环
}