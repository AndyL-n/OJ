#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n;
	int *a = new int[n];
	for(int i = 0;i < n;i++)
		cin >> a[i];
	cin >> m;
	int *b = new int[m]; 
	for(int i = 0;i < m;i++)
		cin >> b[i];
	int ans = INT_MAX;	
	for(int i = 0;i + n < m;i++)
	{
		int	sum = 0;
		for(int j = 0;j < n;j++)
			sum += (b[i+j]-a[j])*(b[i+j]-a[j]); 
		ans = ans<sum?ans:sum;
	}
	cout << ans << endl;
	return 0;
 } 
