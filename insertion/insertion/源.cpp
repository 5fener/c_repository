//�������򣺴ӵ�һ��Ԫ�ؿ�ʼ����ɨ��ÿ��Ԫ�ؽ��в�������
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
	for (i = 1; i < len; i++)	//��������Ԫ��
	{
		temp = arr[i];	//��¼��i+1��Ԫ��
		for (j = i; j > 0 && arr[j - 1] > temp; j--)	//������i+1��Ԫ����ǰ��Ԫ�ز�����С����˳�򽻻���С
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}