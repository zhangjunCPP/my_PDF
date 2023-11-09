/*
t1 
±©Á¦ 
*/ 
#include<bits/stdc++.h>
#define ll long long
#define y1 yl
using namespace std;
inline ll re(){
	ll x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
const ll N=25e4+10,MX=1e4+10;
const ll dx[8]={1,1,0,-1,-1,-1,0,1};
const ll dy[8]={0,1,1,1,0,-1,-1,-1};
struct B{
	ll a,b,c,d;
};
vector<B>a;
ll x1[N],x2[N],y1[N],y2[N];
ll n,m,q,i,op,jl,x,y,ans,j,k;
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=re();
	m=re();
	q=re();
	for(i=1;i<=n;++i){
		x1[i]=re();
		y1[i]=re();
		x2[i]=re();
		y2[i]=re();
		a.push_back({x1[i],y1[i],x2[i],y2[i]});
	}
//	add(1,1,1);
//	printf("%lld\n",sum(2,1));
	while(m--){
		op=re();
		i=re();
		jl=re();
		while(jl--){
			x1[i]+=dx[op],x2[i]+=dx[op];
			y1[i]+=dy[op],y2[i]+=dy[op];
			a.push_back({x1[i],y1[i],x2[i],y2[i]});
		}
	}
	while(q--){
		x=re();
		y=re();
		ans=0;
		for(auto u:a){
			if(u.a<=x&&u.b<=y&&u.c>=x&&u.d>=y)++ans;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

