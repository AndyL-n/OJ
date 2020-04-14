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
	//中心十字
	map[len/2][len/2] = '$';
	map[len/2][len/2 + 1] = '$';
	map[len/2 + 1][len/2] = '$';
	map[len/2][len/2 - 1] = '$';
	map[len/2 - 1][len/2] = '$';
	map[len/2][len/2 + 2] = '$';
	map[len/2 + 2][len/2] = '$';
	map[len/2][len/2 - 2] = '$';
	map[len/2 - 2][len/2] = '$';
	
	//画边
	for(i = 1;i <= n;i++)
	{
		//上边
		for(j = 1;j < len - 2 * i;j++)
			if(j > 2 * i)map[2 * i - 1][j]='$';
		//下边
		for(j = 1;j < len - 2 * i;j++)
			if(j > 2 * i)map[len - 2 * i + 1][j]='$';
		//左边
		for(j = 1;j < len - 2 * i;j++)
			if(j > 2 * i)map[j][2 * i - 1]='$';
		//右边
		for(j = 1;j < len - 2 * i;j++)
			if(j > 2 * i)map[j][len - 2 * i + 1]='$';
	} 
	
	//画角
	for(i = 1;i <= n;i++)
	{
		//左上 
		map[2 * i + 1][2 * i + 1] = '$';
		map[2 * i + 1][2 * i] = '$';
		map[2 * i][2 * i + 1] = '$';
		//右下 
		map[len - 2 * i - 1][len - 2 * i - 1] = '$';
		map[len - 2 * i - 1][len - 2 * i] = '$';
		map[len - 2 * i][len - 2 * i - 1] = '$';
		//左下 
		map[len - 2 * i - 1][2 * i + 1] = '$';
		map[len - 2 * i - 1][2 * i] = '$';
		map[len - 2 * i][2 * i + 1] = '$';
		//右上 
		map[2 * i + 1][len - 2 * i - 1] = '$';
		map[2 * i + 1][len - 2 * i] = '$';
		map[2 * i][len - 2 * i - 1] = '$';
	} 
	//输出 
	for(i = 1;i < len;i++,cout << endl)
		for(j = 1;j < len;j++)
			cout << map[i][j];
	return 0;
} 
