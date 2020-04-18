#include<bits/stdc++.h>
using namespace std;

int n,ans = 0;
int vis[35];
typedef struct
{
	int x,y,r;
}tree;
tree p[35];

bool check(int x)
{
	for(int i = 0;i < n;i++)
		if(i != x && vis[i] && (((p[i].x - p[x].x) * (p[i].x - p[x].x)) + ((p[i].y - p[x].y) * (p[i].y - p[x].y))) < ((p[i].r + p[x].r) * (p[i].r + p[x].r)))
		return false;
	return true;
}
void dfs(int t,int val)
{
	if(t == n)
	{
		ans = max(ans,val);
		return;
	}
	for(int i = 0;i < n;i++)
	if(vis[i] == 0)
	{
		int temp = p[i].r;
		if(!check(i)) p[i].r = 0;
		vis[i] = 1;
		dfs(t+1,val + (p[i].r * p[i].r));
		vis[i] = 0;
		p[i].r = temp;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	memset(vis,0,sizeof(vis));
	for(int i = 0;i < n;i++)
		cin >> p[i].x >> p[i].y >> p[i].r;
//	time_t current_time;  
//    current_time = time(NULL);  
//    printf("%d\n",current_time);  
	dfs(0,0);
//	current_time = time(NULL);  
//    printf("%d\n",current_time);  
	cout << ans << endl;
	return 0;
} 

