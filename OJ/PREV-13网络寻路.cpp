#include <bits/stdc++.h>
using namespace std;
#define MAXN 10010
#define MAXM 100010
int d[MAXN],u[MAXM],v[MAXM];
int main()
{
	std::ios::sync_with_stdio(false);
    long long n,m,ans=0;
	cin >> n >> m;
	
    memset(d,0,sizeof(d));
	memset(u,0,sizeof(u));
	memset(v,0,sizeof(v));
	
    for(int i = 0;i < m;i++)
	{
        cin >> u[i] >> v[i];
        d[u[i]]++;
        d[v[i]]++;
    }
    
    for(int i = 0;i < m;i++)
		if(d[u[i]] > 1 && d[v[i]]>1)//Ñ¡È¡(u,v)±ß 
			ans += (d[u[i]]-1)*(d[v[i]]-1)*2; 
    cout << ans << endl;
    return 0;
}
