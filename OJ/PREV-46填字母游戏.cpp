#include<bits/stdc++.h>
using namespace std;
int fun(string x)
{
    int len = x.length(); 
    if(x.find("LOL")!=string::npos) return -1;//����LOL 
    if(x.find("*") == string::npos) return 0;//������ 
    
    int flag = 0;//�ȼ���Ϊƽ�� 
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
    //�������ƽ�֣�����Ϊƽ��,������ 
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

