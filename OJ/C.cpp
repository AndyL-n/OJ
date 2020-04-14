#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int> p;
bool cmp(pair<int,int> a, pair<int,int> b) 
{
	return a.second < b.second;
}
int main()
{
	ll n,a,b;
	cin >> n;
	while(n--)
	{
		
		cin >> a >> b;
		map<int, int>::iterator it = p.find(a);
		if(it == p.end())p.insert(make_pair(a, 1));
		else it->second ++;
		a = a ^ b;
		it = p.find(a);
		if(it == p.end())p.insert(make_pair(a, 1));
		else it->second ++;	
	}
	a = 0;b = 0;
	for(map<int, int>::iterator it =  p.begin();it != p.end();it++)
	{
//		cout << it -> first << " " << it ->second << endl;
			if(b == it ->second)
			{
				if(a > it->first)a = it->first;
			}
			else if(b < it ->second)
			{
				b = it ->second;
				a = it -> first;
			}
	}
	cout << a << endl;
	return 0;
 } 
