#include<stdio.h>
#include<string.h>/*包含两个头文件（其中一个为字符串函数头文件）*/
void main()
{
	char s1[100], s2[10];/*定义两个字符数组：s1,s2*/
	int i, j, k, len1, len2, b[10];/*定义几个整型变量及整形数组*/
	gets_s(s1);/*读入s1字符数组*/
		gets_s(s2);/*读入s2字符数组*/
	len1 = strlen(s1);
	len2 = strlen(s2);/*运用strlen函数来测量字符数组s1,s2的长度*/
	for (i = 0, k = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			if (s1[i + j] != s2[j]) 
				break;/*若两者相等则结束跳出*/
			if (j >= len2)
			{
				b[k++] = i + 1;
			}/*如果*/
		}
	}/*运用for循环查找两个字符数组s1,s2中相同的字符串序号*/
	printf("%d\n", k);
	for (i = 0; i < k; i++)
		printf("%d ", b[i]); /*利用for循环打印出所有相等的序号*/
	printf("\n");/*输出换行操作*/
}