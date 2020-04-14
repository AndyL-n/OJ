#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string sh;
int i = 0;
int f()
{
	int mx = 0;
	int temp = 0;
	int len = sh.length();
	
	while( i < len)
	{
		if (sh[i] == '(')
		{
			i++;
			temp = temp + f();
		}
		else if(sh[i] == ')')
		{
			i++;
			break;
		}
		else if(sh[i] == '|')
		{
			i++;
			mx = max(temp,mx); 
			temp = 0; 
	   	}
	   else 
	   {
	   		i++;
	   		temp++;
	   }
	}
	return max(mx,temp); 
}
 
int main()
{
	cin>>sh;
	cout<<f()<<endl;
	return 0;
 } 

