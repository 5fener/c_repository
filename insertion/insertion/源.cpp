//�������򣺴ӵ�һ��Ԫ�ؿ�ʼ����ɨ��ÿ��Ԫ�ؽ��в�������

#include<stdio.h>	//������׼��������ļ�
#define LEN 255		////�궨������߽�

void insertion_sort(int[], int);	//��������ԭ��

int main(void)	//�����κβ��������������ҷ���һ������
{
	int arr[LEN];	//����һ����Ϊarr���������鲢�Ҹ���С��LEN
	int len;	//����һ����Ϊlen�����α���
	printf("please input the total of number:\n");	//����printf��������Ļ�ϴ�ӡ���������� ��\n����һ�У�
	scanf_s("%d", &len);	//����scanf�����ڼ����ϼ���len������ֵ
	printf("please input the numbers:\n");	//����printf��������Ļ�ϴ�ӡ��������
	for (int i = 0; i < len; i++)	//forѭ�����������α���i����ֵΪ0����i<len������½���ѭ���壬һ��ѭ����ִ��i++��ѭ����ʼǰ�ȳ�ʼ�����ʽ���жϣ�
		scanf_s("%d", &arr[i]);	//����scanf�����ڼ����ϼ�������arr�е�i+1������ֵ
	insertion_sort(arr, len);	//��������
	for (int i = 0; i < len; i++)	//forѭ�����������α���i����ֵΪ0����i<len������½���ѭ���壬һ��ѭ����ִ��i++��ѭ����ʼǰ�ȳ�ʼ�����ʽ���жϣ�
		printf("%d ", arr[i]);	//����printf��������Ļ�ϴ�ӡ����arr�е�i+1��ֵ 
	return 0;	//����printf��������Ļ�ϴ�ӡ����arr�е�i+1��ֵ 
}
void insertion_sort(int arr[], int len)	//��������
{
	int i, j, temp;	//����i��j��temp���α���
	for (i = 1; i < len; i++)	//��������Ԫ�أ���i<lenʱ����ѭ����,ÿ��ѭ����+1
	{
		temp = arr[i];	//��¼��i+1��Ԫ��
		for (j = i; j > 0 && arr[j - 1] > temp; j--)	//������i+1��Ԫ����ǰ��Ԫ�ز�����С����˳�򽻻���С
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}