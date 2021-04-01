//插入排序：从第一个元素开始依次扫描每个元素进行插入排序

#include<stdio.h>	//包含标准输入输出文件
#define LEN 255		////宏定义数组边界

void insertion_sort(int[], int);	//声明函数原型

int main(void)	//不带任何参数的主函数并且返回一个整数
{
	int arr[LEN];	//声明一个名为arr的整形数组并且个数小于LEN
	int len;	//声明一个名为len的整形变量
	printf("please input the total of number:\n");	//调用printf函数在屏幕上打印（）的内容 （\n另起一行）
	scanf_s("%d", &len);	//调用scanf函数在键盘上键入len的整形值
	printf("please input the numbers:\n");	//调用printf函数在屏幕上打印（）的内
	for (int i = 0; i < len; i++)	//for循环，声明整形变量i并赋值为0，在i<len的情况下进入循环体，一次循环后执行i++（循环开始前先初始化表达式并判断）
		scanf_s("%d", &arr[i]);	//调用scanf函数在键盘上键入数组arr中第i+1个整形值
	insertion_sort(arr, len);	//函数调用
	for (int i = 0; i < len; i++)	//for循环，声明整形变量i并赋值为0，在i<len的情况下进入循环体，一次循环后执行i++（循环开始前先初始化表达式并判断）
		printf("%d ", arr[i]);	//调用printf函数在屏幕上打印数组arr中第i+1个值 
	return 0;	//调用printf函数在屏幕上打印数组arr中第i+1个值 
}
void insertion_sort(int arr[], int len)	//函数定义
{
	int i, j, temp;	//声明i，j，temp整形变量
	for (i = 1; i < len; i++)	//遍历访问元素，当i<len时进入循环体,每次循环后+1
	{
		temp = arr[i];	//记录第i+1个元素
		for (j = i; j > 0 && arr[j - 1] > temp; j--)	//遍历第i+1个元素以前的元素并按从小到大顺序交换大小
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}