#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
int n,m,q,cnt,first[500005];
struct q1{
	int u,w,nex;
	ll v;
}a[1000005];
void add(int u1,int w1,ll v1){
	a[++cnt]={u1,w1,first[u1],v1};
	first[u1]=cnt;
}
priority_queue<pair<ll,int> > p;
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	n=read();
	m=read();
	q=read();
	for(int i=2,x,y;i<=m;i++){
		x=read();
		y=read();
		add(x,y,i);
		add(y,x,i);
	}
	while(q--){
		int s,t;
		ll ans=0;
		s=read();
		t=read();
		p.emplace(make_pair(1,s));
		while(!p.empty()){
			int k=p.top().second;
			ll val=p.top().first;
			p.pop();
			if(k==t)
				ans=max(ans,val);
			for(int i=first[k];i;i=a[i].nex){
				if(val*a[i].v>m)
					continue;
				p.emplace(make_pair(val*a[i].v,a[i].w));
			}
		}
		work(ans?ans:-1);
		putchar('\n');
	}
	return 0;
}
