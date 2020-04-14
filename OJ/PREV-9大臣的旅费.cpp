#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct point{//节点自定义数据类型 
    int num;//节点编号 
    int route;//线路长 
};
int sta_lef;//起始叶节点 
int dest;//最长线路尾节点 
int ans=0;//线路总长度（暂时） 
//第一次深度优先搜索，找到离“首都”最远的城市（叶节点） 
//第二次深度优先搜索，找到离“’首都‘最远城市”最远的城市 
void dfs(vector<point> m[],int vis[],int sta,int dist){ 
    vector<point> cur_sta=m[sta];
    int isleaf=1;//叶节点判断变量 
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
        if(dist>ans){//找到距离以最初始的sta的树的根节点最远的叶节点 
            ans=dist;//更新ans,dest信息 
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
