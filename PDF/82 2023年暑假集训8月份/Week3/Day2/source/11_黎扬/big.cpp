#include<bits/stdc++.h>
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
const int mod=998244353;
int n,m,q,cnt,vis[25],d[25];
pair<int,int> a[205],b[205];
int main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=m;i++){
		a[i].first=read();
		a[i].second=read();
	}
	q=read();
	while(q--){
		memset(vis,0,sizeof(vis));
		for(int i=1,x;i<=n;i++){
			scanf("%1d",&x);
			vis[i]=x;
		}
		cnt=0;
		for(int i=1;i<=m;i++){
			if(vis[a[i].first]&&vis[a[i].second])
				b[++cnt]=a[i];
		}
		int ans=0;
		for(int i=3;i<(1<<cnt);i++){
			memset(d,0,sizeof(d));
			for(int j=1;j<=cnt;j++){
				if((i>>(j-1))&1){
					d[b[j].first]++;
					d[b[j].second]++;
				}
			}
			int flag=1;
			for(int j=1;j<=n;j++){
				if(d[j]<2&&vis[j])
					flag=0;
			}
			ans+=flag;
			ans%=mod;
		}
		work(ans);
		putchar('\n');
	}
	return 0;
}
