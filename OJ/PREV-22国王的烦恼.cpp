#include <bits/stdc++.h> 
using namespace std;
typedef struct node
{
	int a,b,t;
}node;
 
node E[100005];
int flag[10005],n,m;
 
int cmp(node a, node b)
{
	return a.t > b.t;
}
 
int find(int x)
{
	if(x == flag[x])return x;
	return flag[x] = find(flag[x]);
}
int Union(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x == y) return 0;
	else flag[x] = y;
	return 1;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> E[i].a >> E[i].b >> E[i].t;

	sort(E,E + m, cmp); 
	
	
	for(int i = 0;i <= n;i++)
		flag[i] = i;
		
	int pre = -1, ans = 0;
	for (int i = 0; i < m; i++)
	{
		//递减排列  两个小岛不连通，则此桥去掉会产生影响 
		//且与上一个大桥的天数不同，去除同一天 
		if (Union(E[i].a, E[i].b) && pre != E[i].t) 
		{
			ans++;
			pre = E[i].t;
		}
	}
 
	cout << ans << endl;
	return 0;
}
