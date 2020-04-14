#include <bits/stdc++.h>
#include <cmath>
using namespace std;
double a[26][26],b[26];
typedef struct node
{
	double s;
	char c;
	node(double a,char b)
	{
		s = a;
		c = b;
	};
}node;
vector<node>S;
bool cmp(node a,node b)
{
	if(a.s != b.s)return a.s>b.s;
	else return a.c < b.c; 
}
int main()
{
	int n,k;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0;i < n;i++)
	{
		double t;
		char c;
		cin >> t >> c;
		S.push_back(node(t,c));
	}
	for(int i = 0;i < k;i++)
		for(int j = 0;j < k;j++)
			cin >> a[i][j];
	for(int i = 0;i < k;i++)
	{
		double sum = 0;
		for(int j = 0;j < k;j++)
			sum += a[j][i];
		double val = sum/k*1.0;
		sum = 0;
		int kk = 0;
		for(int j = 0;j < k;j++)
		if(fabs(val-a[j][i]) <= 15)
		{
			sum += a[j][i];
			kk++;
		}
		b[i] = (int)(sum/kk*1.0+0.5);
	}
	for(int i = 0;i < n;i++)
	S[i].s = (int)(S[i].s*0.6 + 0.4*b[S[i].c-'A']+0.5);
	sort(S.begin(),S.end(),cmp);
	for(int i = 0; i < n;i++)
	cout << (int)(S[i].s+0.5) << " " << S[i].c << endl;
	return 0;
}
