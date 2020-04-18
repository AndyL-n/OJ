#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	ll n,a,b,c,sum = 0;
	cin >> n >> a >> b >> c;
	for(int i = 1;i <= n;i++)
		if(i%a&&i%b&&i%c)sum++;
	cout << sum << endl;
	return 0;
 } 
