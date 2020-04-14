#include <bits/stdc++.h>
using namespace std;
const int d[4][2] = {-1,0,1,0,0,-1,0,1};
typedef struct node
{
	int a[10];
	int t;
}node;
node s,p;
queue<node> q;
string str;
int vis[900000000];

int num(node a)
{
	int sum = 0;
	for(int i = 0;i < 9;i++)
		sum = sum * 10 + a.a[i];
	return sum;
}
int main()
{
	std::ios::sync_with_stdio(false);
	memset(vis,0,sizeof(vis));
	cin >> str;
	for(int i = 0; i < str.size(); i++)
		s.a[i]  = str[i] != '.' ? str[i] - '0':0;
	s.t = 0;
	vis[num(s)] = 1;
	q.push(s);
	cin >> str;
	for(int i = 0; i < str.size(); i++)
		s.a[i]  = str[i] != '.' ? str[i] - '0':0;
	s.t = 0;
	int ans = 0;
	while(!q.empty() && !ans)
	{
		p = q.front();
		q.pop();
		int x,y,z;
		for(z = 0;z < 9;x++)
			if(!p.a[z])break;
		y = z % 3;z /= 3;
		for(int i = 0;i < 4 && !ans;i++)
		{
			int xx = x + d[i][0];
			int yy = y + d[i][1];
			int zz = xx * 3 + yy;
			if(xx >= 0 && xx < 3 && yy >= 0 && yy < 3)
			{
			
			}
		}
		
		
		
		
		if(memcmp(p.a, s.a, sizeof(p.a)) == 0)
		{
			ans = p.t;
			break; 
		}
	}	
	return 0;
}
