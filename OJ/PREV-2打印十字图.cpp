#include <iostream>
using namespace std;
int main()
{
	int n,i,j;
	cin >> n;
	int len = 5 + 4 * n + 1;
	char map[len][len];
	for(i = 0;i < len;i++)
		for(j = 0;j < len;j++)
			map[i][j] = '.';
	//����ʮ��
	map[len/2][len/2] = '$';
	map[len/2][len/2 + 1] = '$';
	map[len/2 + 1][len/2] = '$';
	map[len/2][len/2 - 1] = '$';
	map[len/2 - 1][len/2] = '$';
	map[len/2][len/2 + 2] = '$';
	map[len/2 + 2][len/2] = '$';
	map[len/2][len/2 - 2] = '$';
	map[len/2 - 2][len/2] = '$';
	
	//����
	for(i = 1;i <= n;i++)
	{
		//�ϱ�
		for(j = 1;j < len - 2 * i;j++)
			if(j > 2 * i)map[2 * i - 1][j]='$';
		//�±�
		for(j = 1;j < len - 2 * i;j++)
			if(j > 2 * i)map[len - 2 * i + 1][j]='$';
		//���
		for(j = 1;j < len - 2 * i;j++)
			if(j > 2 * i)map[j][2 * i - 1]='$';
		//�ұ�
		for(j = 1;j < len - 2 * i;j++)
			if(j > 2 * i)map[j][len - 2 * i + 1]='$';
	} 
	
	//����
	for(i = 1;i <= n;i++)
	{
		//���� 
		map[2 * i + 1][2 * i + 1] = '$';
		map[2 * i + 1][2 * i] = '$';
		map[2 * i][2 * i + 1] = '$';
		//���� 
		map[len - 2 * i - 1][len - 2 * i - 1] = '$';
		map[len - 2 * i - 1][len - 2 * i] = '$';
		map[len - 2 * i][len - 2 * i - 1] = '$';
		//���� 
		map[len - 2 * i - 1][2 * i + 1] = '$';
		map[len - 2 * i - 1][2 * i] = '$';
		map[len - 2 * i][2 * i + 1] = '$';
		//���� 
		map[2 * i + 1][len - 2 * i - 1] = '$';
		map[2 * i + 1][len - 2 * i] = '$';
		map[2 * i][len - 2 * i - 1] = '$';
	} 
	//��� 
	for(i = 1;i < len;i++,cout << endl)
		for(j = 1;j < len;j++)
			cout << map[i][j];
	return 0;
} 
