#include <bits/stdc++.h>
using namespace std;
int dp[1004][1004];
const int mod = 10000;
int main()
{
	ios::sync_with_stdio(false);
    int m,n;
    cin >> m >> n;
	memset(dp,0,sizeof(dp)); 
	
    for(int i = 1; i <= n; i++)
        dp[1][i] = n - i + 1;

    for(int i = 2; i <= m; i++)
        if(i % 2)
            for(int j = n; j >= 1; j--)
                dp[i][j] = (dp[i-1][j-1] + dp[i][j+1]) % mod;
        else
            for(int j = 1; j <= n; j++)
                dp[i][j] = (dp[i-1][j+1] + dp[i][j-1]) % mod;


    cout <<	(m % 2 ? dp[m][1] : dp[m][n]) << endl;

    return 0;
}
