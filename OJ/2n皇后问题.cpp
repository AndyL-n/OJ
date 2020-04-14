#include <bits/stdc++.h>
using namespace std;
int n,data[10][10],ans = 0,k = 0; 
int vis1[10],vis1x[20],vis1c[20];
int vis2[10],vis2x[20],vis2c[20];

void dfs2(int t)
{
	if(t == n)
	{
//		for(int i = 0;i < n;i++,cout << endl)
//			for(int j = 0;j < n;j++)
//				cout << data[i][j] << " ";
		ans++;
//		cout << ans << endl;
	}
	else 
	{
		for(int i = 0;i <n;i++)
			if(data[t][i] == 1 && vis2[i] == 0 && vis2x[i + t - 2] == 0 && vis2c[t - i + n -1] == 0)
			{
				vis2[i] = 1;
				vis2x[i + t - 2] = 1;
				vis2c[t - i + n -1] = 1;
				data[t][i] = 0;
				dfs2(t+1);
				data[t][i] = 1;
				vis2[i] = 0;
				vis2x[i + t - 2] = 0;
				vis2c[t - i + n -1] = 0;
			}
	}
}

void dfs1(int t)
{
	if(t == n)
	{
//		for(int i = 0;i < n;i++,cout << endl)
//			for(int j = 0;j < n;j++)
//				cout << data[i][j] << " ";
		dfs2(0);
//		k++;
//		cout << k << endl;
//		cout << endl;
	}
	else 
	{
		for(int i = 0;i <n;i++)
			if(data[t][i] == 1 && vis1[i] == 0 && vis1x[i + t - 2] == 0 && vis1c[t - i + n -1] == 0)
			{
				vis1[i] = 1;
				vis1x[i + t - 2] = 1;
				vis1c[t - i + n -1] = 1;
				data[t][i] = 0;
				dfs1(t+1);
				data[t][i] = 1;
				vis1[i] = 0;
				vis1x[i + t - 2] = 0;
				vis1c[t - i + n -1] = 0;
			}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	memset(data,0,sizeof(data));
	memset(vis1,0,sizeof(vis1));
	memset(vis1x,0,sizeof(vis1x));
	memset(vis1c,0,sizeof(vis1c));
	memset(vis2,0,sizeof(vis2)); 
	memset(vis2x,0,sizeof(vis2x));
	memset(vis2c,0,sizeof(vis2c));
	int i,j;
	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
			cin >> data[i][j];
			
//	for(i = 0;i < n;i++,cout << endl)
//		for(j = 0;j < n;j++)
//			cout << data[i][j] << " ";
	
	dfs1(0);
	cout << ans << endl;		
	return 0;
} 
