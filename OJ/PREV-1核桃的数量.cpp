#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	if(b > a)swap(a,b);
	int temp;
	while(b != 0)
	{
		if(b > a)swap(a,b);
		temp = a % b;
		a = b;
		b = temp;
	} 
	return a;
} 
int main()
{
	std::ios::sync_with_stdio(false);
	ll a,b,c;
	cin >> a >> b >> c;
	ll ans = a*b/gcd(a,b);
	ans = ans*c/gcd(ans,c);
	cout << ans << endl;
	return 0;
} 
