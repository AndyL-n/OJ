#include<bits/stdc++.h>
using namespace std;

int a[1005][1005];
int main()
{
	ios::sync_with_stdio(false);
    int n,m,x,y;
    cin >> n >> m >> x >> y;
	memset(a,0,sizeof(a));
	
    int i = 0,j = 0,t = 1;
    while(t <= n*m)
    {
        while(a[i][j] == 0 && j < m && !a[x-1][y-1])
        {
            a[i][j] = t;t++;j++;
        }
        if(a[x-1][y-1])break;
        j--;i++;
        while(a[i][j] == 0 && i < n && !a[x-1][y-1])
        {
            a[i][j] = t;t++;i++;
        }
        if(a[x-1][y-1])break;
        i--;j--;
        while(a[i][j] == 0 && j >= 0 && !a[x-1][y-1])
        {
            a[i][j] = t;t++;j--;
        }
        if(a[x-1][y-1])break;
        i--;j++;
        while(a[i][j] == 0 && i >= 0 && !a[x-1][y-1])
        {
            a[i][j] = t;t++;i--;
        }
        if(a[x-1][y-1])break;
        i++;j++;
    }
// 	for(i = 0;i < n;i++,cout << endl)
// 		for(j = 0;j < m;j++)
// 			cout << a[i][j] << " ";
	cout << a[x-1][y-1] << endl;
    return 0;
} 
