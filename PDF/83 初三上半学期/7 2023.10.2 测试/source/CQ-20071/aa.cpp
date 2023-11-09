/*
t1 
±©Á¦ 
*/ 
#include<bits/stdc++.h>
#define ll long long
#define y1 yl
using namespace std;
const ll N=25e4+10,MX=1e4+10;
const ll dx[8]={1,1,0,-1,-1,-1,0,1};
const ll dy[8]={0,1,1,1,0,-1,-1,-1};
ll x1[N],x2[N],y1[N],y2[N],tr[MX][MX];
ll lowbit(ll x){return x&(-x);}
void add(ll x,ll y,ll v){
	++x,++y;
	for(ll i=x;i<=MX-10;i+=lowbit(i)){
		for(ll j=y;j<=MX-10;j+=lowbit(j)){
			tr[i][j]+=v;
		}
	}
}
ll sum(ll x,ll y){
	++x,++y;
	ll res=0;
	for(ll i=x;i;i-=lowbit(i)){
		for(ll j=y;j;j-=lowbit(j)){
			res+=tr[i][j];
		}
	}
	return res;
}
void calc(ll i){
	add(x2[i]+1,y2[i]+1,-1);
	add(x1[i]-1,y2[i],1);
	add(x2[i],y1[i]-1,1);
	add(x1[i]-1,y1[i]-1,-1);
}
ll n,m,q,i,op,jl,x,y,ans,j,k;
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(i=1;i<=n;++i){
		scanf("%lld%lld%lld%lld",x1+i,y1+i,x2+i,y2+i);
		for(j=x1[i];j<=x2[i];++j)for(k=y1[i];k<=y2[i];++k)++tr[j][k];
	}
//	add(1,1,1);
//	printf("%lld\n",sum(2,1));
	while(m--){
		scanf("%lld%lld%lld",&op,&i,&jl);
		while(jl--){
			x1[i]+=dx[op],x2[i]+=dx[op];
			y1[i]+=dy[op],y2[i]+=dy[op];
			for(j=x1[i];j<=x2[i];++j)for(k=y1[i];k<=y2[i];++k)++tr[j][k];
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",tr[x][y]);
	}
	return 0;
}

