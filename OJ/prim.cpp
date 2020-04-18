#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000+5;
int n,vis[maxn];
double a[maxn][maxn],d[maxn], ans;

typedef struct
{
    int x,y,h;  
}node;
node p[maxn];

void Prim()
{
    
    d[1] = 0;
    for(int i = 1; i < n; i++)
    {
        int x = 0;
        for(int j = 1; j <= n; j++)
            if(!vis[j] && (x == 0 || d[j] < d[x])) x = j;
        vis[x] = 1;
        for(int y = 1; y <= n; y++)
            if(!vis[y]) d[y] = min(d[y], a[x][y]);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    memset(vis, 0, sizeof(vis));
    cin >> n;
    for(int i = 0; i <= n; i++,d[i] = DBL_MAX)
        for(int j = 0; j <= n; j++)
            a[i][j] = DBL_MAX;
    
    for(int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y >> p[i].h;

    for(int i = 1; i <= n - 1; i++)
        for(int j = i + 1; j <= n; j++)
            a[i][j] = a[j][i] = min(a[i][j],(double)sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y-p[j].y) * (p[i].y-p[j].y)) + (p[i].h-p[j].h) * (p[i].h-p[j].h));

    Prim();
    
    for(int i = 2; i <= n; i++) ans += d[i];
    printf("%.2f", ans);
    return 0;
}
