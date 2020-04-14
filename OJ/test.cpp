#include<bits/stdc++.h>
using namespace std;
typedef int State[9]; //����"״̬"����
const int maxstate = 1000000;
State st[maxstate], goal; //״̬���顣����״̬������������
int dist[maxstate]; //��������
//�����Ҫ��ӡ�����������������һ��"���ױ��"���� int fa[maxstate]
const int dx[ ] = {-1, 1, 0, 0};
const int dy[ ] = {0, 0, -1, 1};
//BFS������Ŀ��״̬��st�����±�
 
const int hashsize = 1000003;
int head[hashsize], next[maxstate];//next����ʵ������Ĺ��ܡ�
void init_lookup_table( ) { memset(head, 0, sizeof(head)); }
int hash(State& s){
	int v = 0;
	for(int i = 0; i < 9; i++) v = v * 10 + s[i];//��9��������ϳ�9λ��
	return v % hashsize; //ȷ��hash����ֵ�ǲ�����hash��Ĵ�С�ķǸ�����
}
bool try_to_insert(int s){
	int h = hash(st[s]);
	int u = head[h]; //�ӱ�ͷ��ʼ��������
	while(u){
	if(memcmp(st[u],st[s], sizeof(st[s]))==0)return false; //�ҵ��ˣ�����ʧ��
	u = next[u]; //˳�����������
	}
	next[s] = head[h]; //���뵽������
	head[h] = s;
	return true;
}
 
int bfs( ) {
	init_lookup_table( ); //��ʼ�����ұ�
	int front = 1, rear = 2; //��ʹ���±�0����Ϊ0������"������"
	while(front < rear) {
		State& s = st[front]; //��"����"�򻯴���
		if(memcmp(goal, s, sizeof(s)) == 0) return front;//�ҵ�Ŀ��״̬���ɹ�����
		int z;
		for(z = 0; z < 9; z++) if(!s[z]) break; //��"0"��λ��
		int x = z/3, y = z%3; //��ȡ���б�ţ�0~2�� 
		for(int d = 0; d < 4; d++) {
			int newx = x + dx[d];
			int newy = y + dy[d];
			int newz = newx * 3 + newy;
			if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){ //����ƶ��Ϸ�
				State& t = st[rear];
				memcpy(&t, &s, sizeof(s)); //��չ�½��
				t[newz] = s[z];
				t[z] = s[newz];
				dist[rear] = dist[front] + 1; //�����½��ľ���ֵ
				if(try_to_insert(rear)) rear++; //����ɹ�������ұ��޸Ķ�βָ��
			}
		}
		front++; //��չ��Ϻ����޸Ķ���ָ��
	}
	return 0; //ʧ��
}
 
int main( ){
string sa, sb;
	cin>> sa>> sb;
	for(int i = 0; i < 9; i++){
		sa[i] != '.' ?  st[1][i] = sa[i]-'0' : st[1][i] = 0;
		sb[i] != '.' ?  goal[i] = sb[i]-'0'  :  goal[i] = 0;
	}
	int ans = bfs( ); //����Ŀ��״̬���±�
	if(ans > 0) printf("%d\n", dist[ans]);
	else printf("-1\n");
	return 0;

