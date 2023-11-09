#include<bits/stdc++.h>
#define fi first 
#define se second
using namespace std;
inline int rd(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0');
}
inline void FRE(){
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
}
const int N=1e5+5;
typedef pair<int,int> PII;
bool vis[N];
bool mark[N];
int n,m;
PII a[N];
int ans[N];
int main(){
	FRE();
	n=rd();m=rd();
	for(int i=1;i<=n;++i)a[i].fi=rd(),a[i].se=rd(),mark[a[i].fi]=mark[a[i].se]=1;
	int tot=1;
	while(tot<=n){
		if(!vis[a[tot].fi]){
			vis[a[tot].fi]=1;
		}
		else if(!vis[a[tot].se]){
			vis[a[tot].se]=1;
		}
		else{
			break;
		}
		tot++;
		if(tot==n+1)tot=1;
	}
	for(int i=1;i<=m;++i){
		if(!mark[i])ans[tot]++;
	}
	for(int i=1;i<=m;++i){
		if(!mark[i])continue;
		int tot=1;
		for(int j=1;j<=m;++j)vis[j]=0;
		while(tot<=n){
			if(!vis[a[tot].fi]&&a[tot].fi!=i){
				vis[a[tot].fi]=1;
			}
			else if(!vis[a[tot].se]&&a[tot].se!=i){
				vis[a[tot].se]=1;
			}
			else{
				break;
			}
			tot++;
			if(tot==n+1)tot=1;
		}
		ans[tot]++;
	}
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
}
