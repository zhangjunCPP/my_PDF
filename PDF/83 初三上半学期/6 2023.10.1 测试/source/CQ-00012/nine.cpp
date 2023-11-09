#include<bits/stdc++.h>
using namespace std;
#define int long long
map<pair<int,int>,int> d;
map< pair<int,int>,pair<int,int> > pre;
queue< pair<int,int> > q;
int k,X,Y;
inline void dfs(int x,int y){
	if(!x && !y) return ;
	dfs(pre[{x,y}].first,pre[{x,y}].second);
	cout<<x<<" "<<y<<endl;
}
inline bool solve(){
	d[{0,0}]=1;
	q.push(make_pair(0,0));
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int i=0;i<=k;i++){
			int j=k-i;
			if(!d[{x-i,y-j}]){
				d[{x-i,y-j}]=d[{x,y}]+1;
				pre[{x-i,y-j}]=make_pair(x,y);
				q.push(make_pair(x-i,y-j));
				if(x-i==X && y-j==Y) return 1; 
			}
			if(!d[{x+i,y+j}]){
				d[{x+i,y+j}]=d[{x,y}]+1;
				pre[{x+i,y+j}]=make_pair(x,y);
				q.push(make_pair(x+i,y+j));
				if(x+i==X && y+j==Y) return 1; 
			}
			if(!d[{x+i,y-j}]){
				d[{x+i,y-j}]=d[{x,y}]+1;
				pre[{x+i,y-j}]=make_pair(x,y);
				q.push(make_pair(x+i,y-j));
				if(x+i==X && y-j==Y) return 1; 
			}
			if(!d[{x-i,y+j}]){
				d[{x-i,y+j}]=d[{x,y}]+1;
				pre[{x-i,y+j}]=make_pair(x,y);
				q.push(make_pair(x-i,y+j));
				if(x-i==X && y+j==Y) return 1; 
			}
		}
	}
	return 0;
}
vector< pair<int,int> > ans;
signed main(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>k>>X>>Y;
	if(k%2==0 && (X+Y)%2==1){
		cout<<-1<<endl;
		return 0;
	}
	if(k<=10 && abs(X)<=10 && abs(Y)<=10){
		solve();
		cout<<d[{X,Y}]-1<<endl;
		dfs(X,Y);
		return 0;
	}
	int x=0,y=0;
	while(1){
		if(X<x-k){
			ans.push_back(make_pair(x-k,y));
		}
		else if(x+k<X){
			ans.push_back(make_pair(x+k,y));
		}
		else if(Y<y-k){
			ans.push_back(make_pair(x,y-k));
		}
		else if(y+k<Y){
			ans.push_back(make_pair(x,y+k));
		}
		else break;
	}
	int s=abs(x-X)+abs(y-Y);
	if(s%2==1 && k%2==1){
		
	}
	else{
		
	}
	ans.push_back(make_pair(X,Y));
	cout<<(int)ans.size()<<endl;
	for(auto v:ans){
		cout<<v.first<<" "<<v.second;
	}
	return 0;
}
/*
0,0 -> y=x+k y=x-k y=-x+k y=-x-k
T3 �� T1 ����С�� 
T3 �������CZC�ӵ���Ŀ
��ĳԵĳ��г󣬷���������
�벻������
�ò����� A* ֱ��������
�ٶ�С��
���Թ��ܶ���� 
��������������������� 
�ò�����һ���޽⣬ʣ�µ�ֱ��A*���ܹ���
��ĳ󣬺��񲻴��ܡ� 
��ο��Ժ÷���
��Ĳ��ô�
CCF������Щ������ 
I know
���޽��x,y����ż�й�
��Ϊ k Ϊż��ʱ��x,yһ��ֻ�ܺ�Ϊż����
�����������Ըı���ż�ԣ�soga�� 
��������ȼ��� ������һ�����Ը��ǵ�Ŀ���
��ô�������������ߵ��ɡ�
2,3���ɡ�
�����������پ���С��kʱ��Ӧ�ÿ��� 
�����˲����һ��������15min 
С���ˣ�����ʿ��԰��ˡ�
����TM�����ˣ������T3ûд�ꡣ
SB T2
MMD 
*/
