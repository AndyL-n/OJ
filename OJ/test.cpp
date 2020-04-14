#include<bits/stdc++.h>
using namespace std;
typedef int State[9]; //定义"状态"类型
const int maxstate = 1000000;
State st[maxstate], goal; //状态数组。所有状态都保存在这里
int dist[maxstate]; //距离数组
//如果需要打印方案，可以在这里加一个"父亲编号"数组 int fa[maxstate]
const int dx[ ] = {-1, 1, 0, 0};
const int dy[ ] = {0, 0, -1, 1};
//BFS，返回目标状态在st数组下标
 
const int hashsize = 1000003;
int head[hashsize], next[maxstate];//next数组实现链表的功能。
void init_lookup_table( ) { memset(head, 0, sizeof(head)); }
int hash(State& s){
	int v = 0;
	for(int i = 0; i < 9; i++) v = v * 10 + s[i];//把9个数字组合成9位数
	return v % hashsize; //确保hash函数值是不超过hash表的大小的非负整数
}
bool try_to_insert(int s){
	int h = hash(st[s]);
	int u = head[h]; //从表头开始查找链表
	while(u){
	if(memcmp(st[u],st[s], sizeof(st[s]))==0)return false; //找到了，插入失败
	u = next[u]; //顺着链表继续找
	}
	next[s] = head[h]; //插入到链表中
	head[h] = s;
	return true;
}
 
int bfs( ) {
	init_lookup_table( ); //初始化查找表
	int front = 1, rear = 2; //不使用下标0，因为0被看作"不存在"
	while(front < rear) {
		State& s = st[front]; //用"引用"简化代码
		if(memcmp(goal, s, sizeof(s)) == 0) return front;//找到目标状态，成功返回
		int z;
		for(z = 0; z < 9; z++) if(!s[z]) break; //找"0"的位置
		int x = z/3, y = z%3; //获取行列编号（0~2） 
		for(int d = 0; d < 4; d++) {
			int newx = x + dx[d];
			int newy = y + dy[d];
			int newz = newx * 3 + newy;
			if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){ //如果移动合法
				State& t = st[rear];
				memcpy(&t, &s, sizeof(s)); //扩展新结点
				t[newz] = s[z];
				t[z] = s[newz];
				dist[rear] = dist[front] + 1; //更新新结点的距离值
				if(try_to_insert(rear)) rear++; //如果成功插入查找表，修改队尾指针
			}
		}
		front++; //扩展完毕后再修改队首指针
	}
	return 0; //失败
}
 
int main( ){
string sa, sb;
	cin>> sa>> sb;
	for(int i = 0; i < 9; i++){
		sa[i] != '.' ?  st[1][i] = sa[i]-'0' : st[1][i] = 0;
		sb[i] != '.' ?  goal[i] = sb[i]-'0'  :  goal[i] = 0;
	}
	int ans = bfs( ); //返回目标状态的下标
	if(ans > 0) printf("%d\n", dist[ans]);
	else printf("-1\n");
	return 0;

