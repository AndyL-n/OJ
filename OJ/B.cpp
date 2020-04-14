#include <bits/stdc++.h>
int c[100000+5];
int b[100000+5];
int t[100000+5];
int n;
typedef struct node
{
	int a,b;
}node;
node val[100000+5]; 
using namespace std;
bool cmp(node a,node b)
{
	return a.a < b.a;
}
int bfs(int x)
{
	if(c[x] == 0)c[x] = 1;
	for(int i = x-1;i >= 0 && b[i] > b[i+1];i--)
	{
		c[i] = max(c[i],c[i+1]+1);
	}
	for(int i = x+1;i < n && b[i] > b[i-1];i++)
	{
		c[i] = max(c[i],c[i-1]+1);
	}	 
}
int main()
{
	std::ios::sync_with_stdio(false);
	int tmp;
	cin >> n;
	memset(c,0,sizeof(c));
	memset(t,0,sizeof(t));
	cin >> b[0];
	val[0].a = b[0];
	val[0].b = 0;
	t[0] = 1;
	int i = 1;
	for(int j = 1;j < n;j++,i++)
	{
		cin >> b[i];
		if(val[i-1].a == b[i])
		{
			i--;
			t[i]++;
		}
		else
		{
			val[i].a = b[i];
			t[i] = 1;
			val[i].b = i;
		}
	}
	n = i;
//	for(i = 0;i < n;i++)cout << b[i] << " ";
//	cout << endl;
//	for(i = 0;i < n;i++)cout << t[i] << " ";
	sort(val,val+n,cmp);
	for(int i = 0; i < n;i++)
		if(c[val[i].b] == 0)bfs(val[i].b);			
	int sum = 0;
	for(int j = 0;j < n;j++)cout << c[j] << " ";
	cout << endl;
	for(int j = 0;j < n;j++ )sum +=c[j]*t[j];
	cout <<sum <<  endl;
	return 0;
}

