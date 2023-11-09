#include<bits/stdc++.h>
using namespace std;
#define read(x) scanf("%d",&x)
#define N 2000005
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
int vis[N];
int cnt[N];
int a[N],b[N];
int n,m;
int ans[N];
int solve(){
	while(1){
		for(int i=1;i<=n;i++){
			if(vis[a[i]]==0)vis[a[i]]=1;
			else if(vis[b[i]]==0)vis[b[i]]=1;
			else return i;
		}
	}
	return 20240824;
}
void del(){
	for(int i=1;i<=n;i++)vis[a[i]]=vis[b[i]]=0;
}
int main(){
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)read(a[i]),read(b[i]),cnt[a[i]]++,cnt[b[i]]++;
	int ct=0;
	del();
	for(int i=1;i<=m;i++){
		if(cnt[i]>0){
			ct++;
			vis[i]=1;
			ans[solve()]++;
			del();
			vis[i]=0;
		}
	}
	ans[solve()]+=m-ct;
	del();
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}

