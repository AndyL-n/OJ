#include <iostream>
using namespace std;
int main()
{
	int n,ans = 1;
	cin >> n;
	for(int i = 2;i <= n;i++)
	{
		ans *= i;
		while(ans % 10 == 0)
			ans /= 10;
		ans %= 1000000;
	} 
	cout << ans%10 << endl;
	return 0;
}
