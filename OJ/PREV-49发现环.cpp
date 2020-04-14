#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
vector<int> v[maxn];
int n;
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	queue<int> d;
	for(int i = 1;i <= n;i++)
	{
		if(v[i].size() == 1)d.push(i);
	}
	while(!d.empty())
	{
		int x = d.front();
		vector<int>::iterator it = find(v[v[x][0]].begin(), v[v[x][0]].end(), x);
		v[v[x][0]].erase(it);
		if(v[v[x][0]].size() == 1)d.push(v[x][0]);
		v[x].clear();
		d.pop();
	}
	for(int i = 0;i <= n;i++)
		if(v[i].size() == 2)cout << i << " ";
	cout << endl; 
	return 0; 
} 
