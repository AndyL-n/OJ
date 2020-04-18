#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string str;
	cin >> str;
	for(int i = 0;i < str.size();i++)
		str[i] = (str[i] + 3 - 'a') % 26 + 'a';
	cout << str << endl;
	return 0;
}
