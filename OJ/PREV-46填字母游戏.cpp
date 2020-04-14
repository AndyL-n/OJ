#include<bits/stdc++.h>
using namespace std;
int fun(string x)
{
    int len = x.length(); 
    if(x.find("LOL")!=string::npos) return -1;//存在LOL 
    if(x.find("*") == string::npos) return 0;//填完了 
    
    int flag = 0;//先假设为平局 
    for(int i = 0;i < len;i++)
	{
        if(x[i]=='*')
		{
            x[i]='L';
            switch(fun(x))
            {
                case -1: return 1;
                case 0: flag = 1;
            } 
            x[i]='O';
            switch(fun(x))
            {
                case -1: return 1;
                case 0: flag = 1;
            }
            x[i]='*';
        } 
    }
    //如果存在平局，则结果为平局,否则即输 
    return flag?0:-1;
}

int main()
{
    int n;
    cin >> n;
    string str;
    while(n--)
	{
		cin >> str;
		cout << fun(str) << endl;
	} 
    return 0;
} 

