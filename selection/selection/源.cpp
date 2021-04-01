#include<stdio.h>
#define LEN 255

void selection_sort(int[], int);

int main(void)
{
	int arr[LEN];
	int len;
	printf("please input the total of number:\n");
	scanf_s("%d", &len);
	printf("please input the numbers:\n");
	for (int i = 0; i < len; i++)
		scanf_s("%d", &arr[i]);
	selection_sort(arr, len);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	return 0;
}
void selection_sort(int arr[], int len)
{
	int i, j, temp;
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
			temp = arr[min];	//交换两个变量
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}