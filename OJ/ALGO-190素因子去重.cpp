//#include <stdio.h>
//int main()
//{
//	long long n,ans = 1;
//	scanf("%lld",&n);
//	for(int i = 2;i <= n && n > 1;i++)
//    {
//		if(n % i == 0)
//		{
//             ans *= i;
//             while(n % i == 0) n /= i;
//        }
//    }
//	printf("%lld",ans);
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;
//се╤а
long long read(){
    long long x=0,f=1;
    char ch;
    while(ch<'0'||ch>'9')  {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
int main()
{
	ios::sync_with_stdio(false);
	long long n,ans = 1;
	n = read();
	for(int i = 2;i <= n && n > 1;i++)
    {
		if(n % i == 0)
		{
             ans *= i;
             while(n % i == 0) n /= i;
        }
    }
	cout << ans << endl;
	return 0;
}
