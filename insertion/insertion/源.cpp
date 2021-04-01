//插入排序：从第一个元素开始依次扫描每个元素进行插入排序
#include<stdio.h>
#define LEN 255
void insertion_sort(int[], int);
int main(void)
{
	int arr[LEN];
	int len;
	printf("please input the total of number:\n");
	scanf_s("%d", &len);
	printf("please input the numbers:\n");
	for (int i = 0; i < len; i++)
		scanf_s("%d", &arr[i]);
	insertion_sort(arr, len);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	return 0;
}
void insertion_sort(int arr[], int len)
{
	int i, j, temp;
	for (i = 1; i < len; i++)	//遍历访问元素
	{
		temp = arr[i];	//记录第i+1个元素
		for (j = i; j > 0 && arr[j - 1] > temp; j--)	//遍历第i+1个元素以前的元素并按从小到大顺序交换大小
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}