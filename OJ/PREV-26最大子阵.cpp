#include<bits/stdc++.h>
using namespace std;
int dp[505][505] = {0};
int n,m,t;
int main()
{
	std::ios::sync_with_stdio(false);
	memset(dp,0,sizeof(dp));
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
		{
			cin >> t;
			dp[i][j] = dp[i-1][j] + t;//列向前缀和 
		}
		
	int maxn = INT_MIN,s;
	for(int i = 1;i <= n;i++)
	for(int j = i;j <= n;j++)
	{
		s = 0;
		for(int k = 1;k <= m;k++)
		{
			s += dp[j][k] - dp[i - 1][k];
			if(s > maxn) maxn = s;
			if(s < 0) s = 0;
		}
	}
	cout << maxn << endl;
	return 0;
}
