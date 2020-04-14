#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s,str;
	cin >> s >> str;
	int ans = 0,i = 0;
	while(s != str && i < s.size())
	{
		for(;i < s.size();i++)
			if(s[i] != str[i])
			{
				s[i+1] = (s[i+1] == '*'?'o':'*');
				s[i] = (s[i] == '*'?'o':'*');
				ans++;
				i++;
				break;
			}
	}
	cout << ans << endl;
	return 0;
}
