//ð�����򣺱Ƚ�����Ԫ�� ʱ�临�Ӷ�O��n^2)

#include<stdio.h>  //������׼�������ͷ�ļ�
#define LEN 255     //�궨������߽�

void bubble_sort(int[], int);   //��������ԭ��

int main(void)  //�����κβ��������������ҷ���һ������
{
    int arr[LEN];   //����һ����Ϊarr���������鲢�Ҹ���С��LEN
    int len;    //����һ����Ϊlen�����α���
    printf("please input the total of number:\n");  //����printf��������Ļ�ϴ�ӡ���������� ��\n����һ�У�
    scanf_s("%d", &len);    //����scanf�����ڼ����ϼ���len������ֵ
    printf("please input the numbers:\n");  //����printf��������Ļ�ϴ�ӡ����������
    for (int i = 0; i < len; i++)   //forѭ�����������α���i����ֵΪ0����i<len������½���ѭ���壬һ��ѭ����ִ��i++��ѭ����ʼǰ�ȳ�ʼ�����ʽ���жϣ�
        scanf_s("%d", &arr[i]);    //����scanf�����ڼ����ϼ�������arr�е�i+1������ֵ
    bubble_sort(arr, len);  //��������
    for (int i = 0; i < len; i++)   //forѭ�����������α���i����ֵΪ0����i<len������½���ѭ���壬һ��ѭ����ִ��i++��ѭ����ʼǰ�ȳ�ʼ�����ʽ���жϣ�
        printf("%d ", arr[i]);   //����printf��������Ļ�ϴ�ӡ����arr�е�i+1��ֵ 
    return 0;   //����һ���� ��������main��������
}
void bubble_sort(int arr[], int len)    //��������
{
    int i, j, temp;     //����i��j��temp���α���
    //��������Ԫ��
    for (i = 0; i < len - 1; i++)   //forѭ�����������α���i����ֵΪ0����i<len-1������½���ѭ���壬һ��ѭ����ִ��i++��ѭ����ʼǰ�ȳ�ʼ�����ʽ���жϣ�
    {
        for (j = 0; j < len - 1 - i; j++)   //forѭ�����������α���j����ֵΪ0����j<len-1-i������½���ѭ���壬һ��ѭ����ִ��i++��ѭ����ʼǰ�ȳ�ʼ�����ʽ���жϣ�
        {
            if (arr[j] > arr[j + 1])    //�����жϣ���arr[j]>arr[j+1]ʱ������ֵΪ�棬ִ��statement
            {
                temp = arr[j];  //��arr[j]��ֵ����temp
                arr[j] = arr[j + 1];    //��arr[j+1]��ֵ����arr[j]
                arr[j + 1] = temp;  //��temp��ֵ����arr[j+1]
                //����arr[j]��arr[j+1]��ֵ
            }
        }
    }
}