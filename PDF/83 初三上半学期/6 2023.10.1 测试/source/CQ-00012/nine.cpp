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
T3 和 T1 都很小丑 
T3 大概率是CZC加的题目
真的吃的丑中丑，方的人下人
想不出高招
该不会是 A* 直接搜索吧
再度小丑
尝试过很多操作 
就是做不出来，我真服了 
该不会判一下无解，剩下的直接A*就能过？
真的丑，好像不大能。 
这次考试好烦呐
真的不好打
CCF考过这些东西吗 
I know
有无解和x,y的奇偶有关
因为 k 为偶数时，x,y一定只能和为偶数。
但是奇数可以改变奇偶性，soga。 
其余情况先假设 现在走一步可以覆盖到目标点
那么在少量步数能走到吧。
2,3步吧。
当他们曼哈顿距离小于k时，应该可以 
悲剧了差最后一步，还有15min 
小丑了，大概率可以摆了。
我真TM无语了，最后搞出T3没写完。
SB T2
MMD 
*/
