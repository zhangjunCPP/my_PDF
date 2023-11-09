#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=1e5+5,M=1e6+6;
int n,m;
int a[N],b[N],cnt[N];
int vis[M];
bitset<M>can;
int jo(int x){
	can.reset();
	can[x]=1;
	int now=1;
	while(1){
		if(!can[a[now]])can[a[now]]=1,now++;
		else{
			if(!can[b[now]])can[b[now]]=1,now++;
			else return now;
		}now=(now-1)%n+1;
	}
}
int main(){
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
	n=rd(),m=rd();
	int no=0;
	for(int i=1;i<=n;i++)a[i]=rd(),b[i]=rd(),vis[a[i]]=vis[b[i]]=1;
	for(int i=1;i<=m;i++)if(vis[i])cnt[jo(i)]++;else no++;
	cnt[jo(0)]+=no;
	for(int i=1;i<=n;i++)printf("%d\n",cnt[i]);
	return 0;
}

