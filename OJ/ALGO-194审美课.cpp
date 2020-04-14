#include<iostream> 
using namespace std;
int data[50005];
int count[1<<20+5]={0};
int main()
{
	int n,m,tmp,ans = 0;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			cin >> tmp;
			data[i] = (data[i] << 1) + tmp;
		}
		count[data[i]]++;
	} 
	int maxn = (1 << m)-1;
	for(int i = 0;i < n;i++)
	{ 
		tmp = data[i] ^ maxn;
		ans += count[tmp] ;
	}
	cout << ans / 2 << endl;
	return 0;
} 







































//#include <bits/stdc++.h>
//using namespace std;
//int main()
//{
//	int n,m;
//	cin >> n >> m;
//	string s1[n],s2[n];
//	for(int i = 0;i < n;i++)
//	{
//		s1[i] = "\0";s2[i] = "\0"; 
//		for(int j = 0;j < m;j++)
//		{
//			int tmp;
//			cin >> tmp;
//			if(tmp){s1[i] = s1[i] + '1';s2[i] = s2[i] + '0';}
//			else {s1[i] = s1[i] + '0';s2[i] = s2[i] + '1';}
//		}	
//	}
//	sort(s1,s1+n);
//	sort(s2,s2+n);
////	for(int i = 0;i < n;i++)
////		cout << s1[i] << "\t" << s2[i] << endl;
//	int i= 0,j = 0,ans = 0,tmp = 0;
//	
//	while(i < n || j < n)
//	{
////		cout << i << " " << j << endl;
//		if(i > 0 && s1[i] == s1[i-1])
//		{
/////			cout << tmp << endl;
////			cout << "flag" << endl;
//			i++;
//		}
//		else
//		{
//			if(s1[i] == s2[j])
//			{
//				for(tmp = 0;j < n;j++)
//					if(s1[i] == s2[j])tmp++;
//					else 
//					{
//						i++;
//						break;
//					}
//			}
//			else 
//			{
//				tmp = 0;
//				if(s1[i] > s2[j])j++;
//				else i++;
//			}
//		}
//		
//		ans += tmp;
////		cout << tmp << endl;
//	}
//	cout << ans/2 << endl;
//	return 0;
//}
