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
		int min = i;	//��¼��Сֵ����һ��Ԫ��Ĭ����С
		for (j = i + 1; j < len; j++)	//����δ�����Ԫ��
		{
			if (arr[j]< arr[min])	//�ҵ�Ŀǰ��С��
			{
				min = j;	//��¼��Сֵ
			}
		}
		if (min != i)
		{
			temp = arr[min];	//������������
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}