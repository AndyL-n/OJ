#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int h[maxn],w[maxn];
int n,k,r = maxn,l = 1,ans = 0;
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0;i < n;i++)
		cin >> h[i] >> w[i];
		
	while(l <= r)
	{
		int mid = (l + r)/2;
		int sum = 0;
		for(int i = 0;i < n;i++)
			sum += (h[i] / mid)*(w[i] / mid);
		if(sum >= k)
		{
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
