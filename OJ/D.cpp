#include<iostream> 
#include <string>
using namespace std; 
int main()
{	
 	string str,s;
 	int ans = 0;
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		switch(s[i])
		{
			case '0':str = str + "0000";break;
			case '1':str = str + "0001";break;
			case '2':str = str + "0010";break;
			case '3':str = str + "0011";break;
			case '4':str = str + "0100";break;
			case '5':str = str + "0101";break;
			case '6':str = str + "0110";break;
			case '7':str = str + "0111";break;
			case '8':str = str + "1000";break;
			case '9':str = str + "1001";break;
			case 'A':str = str + "1010";break;
			case 'B':str = str + "1011";break;
			case 'C':str = str + "1100";break;
			case 'D':str = str + "1101";break;
			case 'E':str = str + "1110";break;
			case 'F':str = str + "1111";break;
		}
		while(1)
		{
			while(str[0]== '0')str = str.substr(1,str.size());
			if(str.size() < 3)break;		
			if(str.substr(0,3) == "100")
			{
				str = "011" + str.substr(3,str.size());
				ans++;
				continue;
			}
			if(str.substr(0,3) == "101")
			{
				str = "010"+str.substr(3,str.size());
				ans++;
				continue;
			}			
			if(str.substr(0,3) == "110")
			{
				str = "001"+str.substr(3,str.size());
				ans++;
				continue;
			}			
			if(str.substr(0,3) == "111")
			{
				str = "000"+str.substr(3,str.size());
				ans++;
				continue;
			}		
		}
		
	}
	if(str == "")cout << ans << endl;
	else if(str == "11" || str == "1")cout << ans + 1 << endl;
	else cout << "No" << endl;
	return 0;
}
/*
			case '0':str = str + "0000";break;
			case '1':str = str + "1000";break;
			case '2':str = str + "0100";break;
			case '3':str = str + "1100";break;
			case '4':str = str + "0010";break;
			case '5':str = str + "1010";break;
			case '6':str = str + "0110";break;
			case '7':str = str + "1110";break;
			case '0':str = str + "0001";break;
			case '1':str = str + "1001";break;
			case '2':str = str + "0101";break;
			case '3':str = str + "1101";break;
			case '4':str = str + "0011";break;
			case '5':str = str + "1011";break;
			case '6':str = str + "0111";break;
			case '7':str = str + "1111";break;
			
			case '0':str = str + "0000";break;
			case '1':str = str + "1000";break;
			case '2':str = str + "0100";break;
			case '3':str = str + "1100";break;
			case '4':str = str + "0010";break;
			case '5':str = str + "1010";break;
			case '6':str = str + "0110";break;
			case '7':str = str + "1110";break;
			case '8':str = str + "0001";break;
			case '9':str = str + "1001";break;
			case 'A':str = str + "0101";break;
			case 'B':str = str + "1101";break;
			case 'C':str = str + "0011";break;
			case 'D':str = str + "1011";break;
			case 'E':str = str + "0111";break;
			case 'F':str = str + "1111";break;
			*/
