#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,cnt = 1,p,temp;
	cin >> n >> p;
	for(int i = 1;i < n;i++)
	{
		cin >> temp;
		if(temp < p)cnt++;
	}
	cout << (int)(log(cnt)/log(2)) << endl; 
	return 0;
}
