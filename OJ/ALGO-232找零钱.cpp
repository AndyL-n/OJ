#include <iostream>
using namespace std;
int main()
{
	int n,x,a = 0,b = 0;
	cin >> n;
	while(n-- && a >= 0 && b >= 0)
	{
		cin >> x;
		switch(x)
		{
			case 25:a++;break;
			case 50:a--;b++;break;
			case 100:{if(b == 0)a -= 3;else { a--;b--;}}break;
		}
	}
	if(a < 0 || b < 0)cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}
