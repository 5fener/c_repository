//冒泡排序：比较相邻元素 时间复杂度O（n^2)

#include<stdio.h>  //包含标准输入输出头文件
#define LEN 255     //宏定义数组边界

void bubble_sort(int[], int);   //声明函数原型

int main(void)  //不带任何参数的主函数并且返回一个整数
{
    int arr[LEN];   //声明一个名为arr的整形数组并且个数小于LEN
    int len;    //声明一个名为len的整形变量
    printf("please input the total of number:\n");  //调用printf函数在屏幕上打印（）的内容 （\n另起一行）
    scanf_s("%d", &len);    //调用scanf函数在键盘上键入len的整形值
    printf("please input the numbers:\n");  //调用printf函数在屏幕上打印（）的内容
    for (int i = 0; i < len; i++)   //for循环，声明整形变量i并赋值为0，在i<len的情况下进入循环体，一次循环后执行i++（循环开始前先初始化表达式并判断）
        scanf_s("%d", &arr[i]);    //调用scanf函数在键盘上键入数组arr中第i+1个整形值
    bubble_sort(arr, len);  //函数调用
    for (int i = 0; i < len; i++)   //for循环，声明整形变量i并赋值为0，在i<len的情况下进入循环体，一次循环后执行i++（循环开始前先初始化表达式并判断）
        printf("%d ", arr[i]);   //调用printf函数在屏幕上打印数组arr中第i+1个值 
    return 0;   //返回一个数 用来结束main（）函数
}
void bubble_sort(int arr[], int len)    //函数定义
{
    int i, j, temp;     //声明i，j，temp整形变量
    //遍历所有元素
    for (i = 0; i < len - 1; i++)   //for循环，声明整形变量i并赋值为0，在i<len-1的情况下进入循环体，一次循环后执行i++（循环开始前先初始化表达式并判断）
    {
        for (j = 0; j < len - 1 - i; j++)   //for循环，声明整形变量j并赋值为0，在j<len-1-i的情况下进入循环体，一次循环后执行i++（循环开始前先初始化表达式并判断）
        {
            if (arr[j] > arr[j + 1])    //条件判断，当arr[j]>arr[j+1]时，返回值为真，执行statement
            {
                temp = arr[j];  //将arr[j]的值赋给temp
                arr[j] = arr[j + 1];    //将arr[j+1]的值赋给arr[j]
                arr[j + 1] = temp;  //将temp的值赋给arr[j+1]
                //交换arr[j]和arr[j+1]的值
            }
        }
    }
}