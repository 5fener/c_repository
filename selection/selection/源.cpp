//ѡ��������δ�����������ҵ���СԪ�ز����������������ĩβ

#include<stdio.h>	//������׼��������ļ�
#define LEN 255		////�궨������߽�

void selection_sort(int[], int);//��������ԭ��

int main(void)	//�����κβ��������������ҷ���һ������
{
	int arr[LEN];	//����һ����Ϊarr���������鲢�Ҹ���С��LEN
	int len;	//����һ����Ϊlen�����α���
	printf("please input the total of number:\n");	//����printf��������Ļ�ϴ�ӡ���������� ��\n����һ�У�
	scanf_s("%d", &len);	//����scanf�����ڼ����ϼ���len������ֵ
	printf("please input the numbers:\n");	//����printf��������Ļ�ϴ�ӡ��������
	for (int i = 0; i < len; i++)	//forѭ�����������α���i����ֵΪ0����i<len������½���ѭ���壬һ��ѭ����ִ��i++��ѭ����ʼǰ�ȳ�ʼ�����ʽ���жϣ�
		scanf_s("%d", &arr[i]);		//����scanf�����ڼ����ϼ�������arr�е�i+1������ֵ
	selection_sort(arr, len);	//��������
	for (int i = 0; i < len; i++)	//forѭ�����������α���i����ֵΪ0����i<len������½���ѭ���壬һ��ѭ����ִ��i++��ѭ����ʼǰ�ȳ�ʼ�����ʽ���жϣ�
		printf("%d ", arr[i]);	//����printf��������Ļ�ϴ�ӡ����arr�е�i+1��ֵ 
	return 0;	//����printf��������Ļ�ϴ�ӡ����arr�е�i+1��ֵ 
}
void selection_sort(int arr[], int len)	//��������
{
	int i, j, temp;	//����i��j��temp���α���
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
			temp = arr[min];	//��������������ֵ
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}