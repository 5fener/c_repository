//选择排序：在未排序序列中找到最小元素并依序放置至已排序末尾

#include<stdio.h>	//包含标准输入输出文件
#define LEN 255		////宏定义数组边界

void selection_sort(int[], int);//声明函数原型

int main(void)	//不带任何参数的主函数并且返回一个整数
{
	int arr[LEN];	//声明一个名为arr的整形数组并且个数小于LEN
	int len;	//声明一个名为len的整形变量
	printf("please input the total of number:\n");	//调用printf函数在屏幕上打印（）的内容 （\n另起一行）
	scanf_s("%d", &len);	//调用scanf函数在键盘上键入len的整形值
	printf("please input the numbers:\n");	//调用printf函数在屏幕上打印（）的内
	for (int i = 0; i < len; i++)	//for循环，声明整形变量i并赋值为0，在i<len的情况下进入循环体，一次循环后执行i++（循环开始前先初始化表达式并判断）
		scanf_s("%d", &arr[i]);		//调用scanf函数在键盘上键入数组arr中第i+1个整形值
	selection_sort(arr, len);	//函数调用
	for (int i = 0; i < len; i++)	//for循环，声明整形变量i并赋值为0，在i<len的情况下进入循环体，一次循环后执行i++（循环开始前先初始化表达式并判断）
		printf("%d ", arr[i]);	//调用printf函数在屏幕上打印数组arr中第i+1个值 
	return 0;	//调用printf函数在屏幕上打印数组arr中第i+1个值 
}
void selection_sort(int arr[], int len)	//函数定义
{
	int i, j, temp;	//声明i，j，temp整形变量
	for (i = 0; i < len-1; i++)
	{
		int min = i;	//记录最小值，第一个元素默认最小
		for (j = i + 1; j < len; j++)	//访问未排序的元素
		{
			if (arr[j]< arr[min])	//找到目前最小组
			{
				min = j;	//记录最小值
			}
		}
		if (min != i)
		{
			temp = arr[min];	//交换两个变量的值
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}