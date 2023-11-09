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
int n,m,k,cnt,first[55];
priority_queue<pair<int,vector<int> >,vector<pair<int,vector<int> > >,greater<pair<int,vector<int> > > > q;
vector<int> gg;
struct q1{
	int u,w,v,nex;
}a[5005];
void add(int u1,int w1,int v1){
	a[++cnt]={u1,w1,v1,first[u1]};
	first[u1]=cnt;
}
int main(){
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1,x,y,z;i<=m;i++){
		x=read();
		y=read();
		z=read();
		add(x,y,z);
	}
	gg.emplace_back(1);
	q.emplace(make_pair(0,gg));
	while(!q.empty()&&k){
		int now=q.top().first,k1=0;
		vector<int> g=q.top().second;
		k1=g.back();
		q.pop();
		if(k1==n){
			k--;
			if(!k){
				work(g.size());
				putchar('\n');
				for(auto i:g){
					work(i);
					putchar(' ');
				}
				return 0;
			}
			continue;
		}
		for(int i=first[k1];i;i=a[i].nex){
			int flag=0;
			for(auto j:g){
				if(j==a[i].w){
					flag=1;
					break;
				}
			}
			if(flag)
				continue;
			vector<int> h=g;
			h.emplace_back(a[i].w);
			q.emplace(make_pair(now+a[i].v,h));
		}
	}
	work(-1);
	return 0;
}
