#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct point{//�ڵ��Զ����������� 
    int num;//�ڵ��� 
    int route;//��·�� 
};
int sta_lef;//��ʼҶ�ڵ� 
int dest;//���·β�ڵ� 
int ans=0;//��·�ܳ��ȣ���ʱ�� 
//��һ����������������ҵ��롰�׶�����Զ�ĳ��У�Ҷ�ڵ㣩 
//�ڶ�����������������ҵ��롰���׶�����Զ���С���Զ�ĳ��� 
void dfs(vector<point> m[],int vis[],int sta,int dist){ 
    vector<point> cur_sta=m[sta];
    int isleaf=1;//Ҷ�ڵ��жϱ��� 
    vis[sta]=0;
    for(int i=0;i<cur_sta.size();i++){
        int num=cur_sta[i].num;
        if(vis[num]==-1){
            isleaf=0;
            dfs(m,vis,num,dist+cur_sta[i].route);
        }
    } 
    vis[sta]=-1;
    if(isleaf){
        if(dist>ans){//�ҵ����������ʼ��sta�����ĸ��ڵ���Զ��Ҷ�ڵ� 
            ans=dist;//����ans,dest��Ϣ 
            dest=sta;
        }
    }
} 
int main(){
    int N;
    cin>>N;
    vector<point> mapp[N+1];
    int vis[N+1];
    int sta,end,rou;
    for(int i=0;i<N-1;i++){
        cin>>sta>>end>>rou;
        point p1={sta,rou};
        point p2={end,rou};
        mapp[sta].push_back(p2);
        mapp[end].push_back(p1); 
    }
    memset(vis,-1,sizeof(vis));
    dfs(mapp,vis,1,0); 
    sta_lef=dest;
    dfs(mapp,vis,sta_lef,0);
	int sum = 0;
	for(int i = 1;i <= ans;i++)
		sum += (i+10);
	cout << sum << endl;
   return 0;
}
