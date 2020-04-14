#include <bits/stdc++.h>
using namespace std;
typedef int BigInteger[10100];
 
#define DEPTH 10

int comp(const BigInteger a,const int c,const int d,const BigInteger b) //大数比较
{
    int i,t=0,O=-DEPTH*2;
    if(b[0]-a[0]<d&&c) return 1;
    for(i=b[0];i>d;i--)
    {
        t=t*DEPTH+a[i-d]*c-b[i];
        if(t>0) return 1;
        if(t<O) return 0;
    }
    for(i=d;i;i--)
    {
        t=t*DEPTH-b[i];
        if(t>0) return 1;
        if(t<O) return 0;
    }
    return t>0;
}
 
void sub(BigInteger a,const BigInteger b,const int c,const int d) //大数减
{
    int i,O=b[0]+d;
    for(i=1+d;i<=O;i++)
        if((a[i]-=b[i-d]*c)<0)
            a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH;
    for(;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
    for(;!a[a[0]]&&a[0]>1;a[0]--);
}
 
void Sqrt(BigInteger b,BigInteger a) //开平方
{
    int h,l,m,i;
    memset((void*)b,0,sizeof(BigInteger));
    for(i= b[0]=(a[0]+1)>>1;i;sub(a,b,m,i-1),b[i]+=m,i--)
        for(h=DEPTH-1,l=0,b[i]=m=(h+l+1)>>1;h>l;b[i]=m=(h+l+1)>>1)
            if(comp(b,m,i-1,a)) h=m-1;
            else l = m;
    for(;!b[b[0]]&&b[0]>1;b[0]--);
    for (i = 1; i <= b[0]; b[i++] >>= 1);
}//大数加法
string add(string s1,string s2){

	if(s1 == ""&&s2 == "")return "0";
	if(s1 == "")return s2;
	if(s2 == "")return s1;	
	string maxx = s1,minn = s2;
	if(s1.length() < s2.length())
	{
		maxx = s2;
		minn = s1;
	}
	int i,a = maxx.length()-1,b = minn.length()-1;
	for(i = b;i >=0 ;--i)
	{
		maxx[a--] += minn[i] - '0';
	}
	for(i = maxx.length() - 1;i > 0;--i)
	{
		if(maxx[i] > '9')
		{
			maxx[i] -= 10;
			maxx[i-1]++;
		}
	}
	
	if(maxx[0] > '9')
	{
		maxx[0] -= 10;
		maxx = '1'+maxx;
	}
	
	return maxx;
}


//大数乘法 
string mult(string s,int n){
	int i,len = s.length(),temp = 0; 
	for(i = len - 1;i >= 0;i--)
	{
		temp = temp + (s[i] - '0')*n;
		s[i] = (temp%10)+'0';
		temp =  temp/10;//进位 
	}
	char c;
	while(temp)
	{
		c = (temp%10)+'0';
		s = c + s;
		temp /= 10;
	}
	return s;
}

string mul(string a,string b)
{
	string ans = "\0",t = "\0";
	for(int i = b.size() - 1;i >= 0;i--)
	{
		t = mult(a,b[i]-'0');
		for(int j = 1;j < b.size() - i;j++)
			t += '0';
		ans = add(ans,t);
	}
	return ans;
}
char str[10100];
BigInteger a,b,sum;
 
int main()
{
	scanf("%s",str);
    a[0]=strlen(str);
    for(int i=1; i<=a[0]; i++)
        a[i]=str[a[0]-i]-'0';
    Sqrt(b,a);
    string sa = "\0";
	for(int i=b[0]; i>=1; i--)
    	sa += b[i] + '0';
//    cout << sa << endl;
    scanf("%s",str);
    a[0]=strlen(str);
    for(int i=1; i<=a[0]; i++)
        a[i]=str[a[0]-i]-'0';
    Sqrt(b,a);
    string sb = "\0";
    for(int i=b[0]; i>=1; i--)
   		sb += b[i] + '0';
//    cout << sb << endl;
 	cout << mul(sa,sb) << endl;
 	return 0;
}


