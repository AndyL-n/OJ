//#include <bits/stdc++.h>
//using namespace std;
//map<string,int>p; 
//queue<string>Q;
//int main()
//{
//	string str,s;
//	cin >> str >> s;
//	p[str] = 0;
//	Q.push(str);
//	while(!Q.empty() && Q.front() != s)
//	{
//		str = Q.front();
//		Q.pop(); 
//		int pos = str.find('*');
//		
//		if(pos + 1 < str.length())
//		{
//			string nt=now;
//			swap(nt[pos],nt[pos+1]);
//			if(!mp[nt]){
//				mp[nt]=mp[now]+1;
//				q.push(nt);
//			}
//		}
//		if(pos+2<now.length()){
//			string nt=now;
//			swap(nt[pos],nt[pos+2]);
//			if(!mp[nt]){
//				mp[nt]=mp[now]+1;
//				q.push(nt);
//			}
//		}
//		if(pos+3<now.length()){
//			string nt=now;
//			swap(nt[pos],nt[pos+3]);
//			if(!mp[nt]){
//				mp[nt]=mp[now]+1;
//				q.push(nt);
//			}
//		}
//		if(pos-1>=0){
//			string nt=now;
//			swap(nt[pos],nt[pos-1]);
//			if(!mp[nt]){
//				mp[nt]=mp[now]+1;
//				q.push(nt);
//			}
//		}
//		if(pos-2>=0){
//			string nt=now;
//			swap(nt[pos],nt[pos-2]);
//			if(!mp[nt]){
//				mp[nt]=mp[now]+1;
//				q.push(nt);
//			}
//		}
//		if(pos-3>=0){
//			string nt=now;
//			swap(nt[pos],nt[pos-3]);
//			if(!mp[nt]){
//				mp[nt]=mp[now]+1;
//				q.push(nt);
//			}
//
//	}
//	cout << p[Q.front()] << endl;
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
typedef struct
{
	string str;
	int d;	
}node;
queue<node> Q;
int main()
{
	string str,s;
	cin >> str >> s;

	node begin;
	begin.str = str;
	begin.d = 0;
	Q.push(begin);
	while(!Q.empty() && Q.front().str != s)
	{
		
		int pos = Q.front().str.find('*');
		cout << pos << "\t" << Q.front().str << "\t" << Q.front().d << endl;
		//×ó
		if(pos - 1 >= 0)
		{
			node p;
			p.str = Q.front().str;
			p.d = Q.front().d + 1;
			char t = p.str[pos - 1];
			p.str[pos - 1] = '*';
			p.str[pos] = t;
//			cout << p.str << endl;
			Q.push(p); 
		}
		if(pos - 2 >= 0)
		{
			node p;
			p.str = Q.front().str;
			p.d = Q.front().d + 1;
			char t = p.str[pos - 2];
			p.str[pos - 2] = '*';
			p.str[pos] = t;
//			cout << p.str<< endl;
			Q.push(p); 
		}
		if(pos - 3 >= 0)
		{
			node p;
			p.str = Q.front().str;
			p.d = Q.front().d + 1;
			char t = p.str[pos - 3];
			p.str[pos - 3] = '*';
			p.str[pos] = t;
//			cout << p.str<< endl;
			Q.push(p); 
		} 
		//ÓÒ 
		if(pos + 1 < Q.front().str.size())
		{
			node p;
			p.str = Q.front().str;
			p.d = Q.front().d + 1;
			char t = p.str[pos + 1];
			p.str[pos + 1] = '*';
			p.str[pos] = t;
//			cout << p.str<< endl;
			Q.push(p);
		} 
		if(pos + 2 < Q.front().str.size())
		{
			node p;
			p.str = Q.front().str;
			p.d = Q.front().d + 1;
			char t = p.str[pos + 2];
			p.str[pos + 2] = '*';
			p.str[pos] = t;
//			cout << p.str<< endl;
			Q.push(p);
		}
		if(pos + 3 < Q.front().str.size())
		{
			node p;
			p.str = Q.front().str;
			p.d = Q.front().d + 1;
			char t = p.str[pos + 3];
			p.str[pos + 3] = '*';
			p.str[pos] = t;
//			cout << p.str<< endl;
			Q.push(p);
		}
		Q.pop(); 
	}
	cout << Q.front().d << endl;
	return 0;
}
