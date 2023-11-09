#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(int k){
	if(k<0){
		k=-k;
		putchar('-');
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
int k,x,y;
queue<pair<int,int> > q;
set<pair<int,int> > p;
map<pair<int,int>,int> ans;
map<pair<int,int>,pair<int,int> > pre;
stack<pair<int,int> > h;
int main(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
	k=read();
	x=read();
	y=read();
	if((!(k&1))&&((x+y)&1)){
		work(-1);
		return 0;
	}
	q.emplace(make_pair(0,0));
	ans[make_pair(0,0)]=0;
	p.insert(make_pair(0,0));
	while(!q.empty()){
		int ex=q.front().first,ey=q.front().second,num=ans[make_pair(ex,ey)];
		if(abs(ex)>1e9||abs(ey)>1e9){
			q.pop();
			continue;
		}
		if(ex==x&&ey==y){
			work(num);
			putchar('\n');
			auto now=make_pair(ex,ey);
			h.emplace(now);
			while(pre.find(now)!=pre.end()){
				now=pre[now];
				h.emplace(now);
			}
			h.pop();
			while(!h.empty()){
				work(h.top().first);
				putchar(' ');
				work(h.top().second);
				putchar('\n');
				h.pop();
			}
			return 0;
		}
		q.pop();
		for(int i=0;i<=k;i++){
			if(p.find(make_pair(ex-i,ey-(k-i)))==p.end()){
				q.emplace(make_pair(ex-i,ey-(k-i)));
				ans[make_pair(ex-i,ey-(k-i))]=num+1;
				pre[make_pair(ex-i,ey-(k-i))]=make_pair(ex,ey);
				p.insert(make_pair(ex-i,ey-(k-i)));
			}
			if(p.find(make_pair(ex+i,ey-(k-i)))==p.end()){
				q.emplace(make_pair(ex+i,ey-(k-i)));
				ans[make_pair(ex+i,ey-(k-i))]=num+1;
				pre[make_pair(ex+i,ey-(k-i))]=make_pair(ex,ey);
				p.insert(make_pair(ex+i,ey-(k-i)));
			}
			if(p.find(make_pair(ex-i,ey+(k-i)))==p.end()){
				q.emplace(make_pair(ex-i,ey+(k-i)));
				ans[make_pair(ex-i,ey+(k-i))]=num+1;
				pre[make_pair(ex-i,ey+(k-i))]=make_pair(ex,ey);
				p.insert(make_pair(ex-i,ey+(k-i)));
			}
			if(p.find(make_pair(ex+i,ey+(k-i)))==p.end()){
				q.emplace(make_pair(ex+i,ey+(k-i)));
				ans[make_pair(ex+i,ey+(k-i))]=num+1;
				pre[make_pair(ex+i,ey+(k-i))]=make_pair(ex,ey);
				p.insert(make_pair(ex+i,ey+(k-i)));
			}
		}
	}
	work(-1);
	return 0;
}
