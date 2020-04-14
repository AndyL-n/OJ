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
		//�ݼ�����  ����С������ͨ�������ȥ�������Ӱ�� 
		//������һ�����ŵ�������ͬ��ȥ��ͬһ�� 
		if (Union(E[i].a, E[i].b) && pre != E[i].t) 
		{
			ans++;
			pre = E[i].t;
		}
	}
 
	cout << ans << endl;
	return 0;
}
