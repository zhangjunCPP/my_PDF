#include<bits/stdc++.h>
#define int long long 
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
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
}
const int N=1e3+5;
int n,ans;
bool ma[N];
int l[N],r[N],c[N];
int vl[N],vis[N];
int sum[N],g[N];
inline bool cmp(int x,int y){
	return sum[x]<sum[y]; 
}
inline void dfs(int pos){
	if(pos==n+1){
		int S=0;
		for(int i=1;i<=n;++i)ma[i]=0;
		for(int i=1;i<=n;++i){
			int f=vl[i];
			int su=0;
			ma[f]=1;
			for(int j=l[f];j<=r[f];++j){
				if(!ma[j])su++; 
			}
			S+=su*c[f];
		}
		ans=max(ans,S);
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		vis[i]=1;
		vl[pos]=i;
		dfs(pos+1);
		vis[i]=0;
	}
}
signed main(){
	FRE();
	n=rd();
	bool flag=1;
	for(int i=1;i<=n;++i){
		l[i]=rd(),r[i]=rd(),c[i]=rd(); 
		if(l[i]!=r[i])flag=0;
	}
	if(flag){
		puts("0");
		return 0;
	}
	if(n<=20){
		dfs(1);
		wr(ans);
		return 0; 
	}
	for(int i=1;i<=n;++i)vl[i]=i;
	for(int ff=1;ff<=n;++ff){
		for(int i=1;i<=n;++i){
			if(ma[i])continue;
			for(int j=max(i-7,1ll);j<=min(i+7,n);++j){
				if(l[j]<=i&&i<=r[j])sum[i]+=c[i];
				for(int z=l[j];z<=r[j];++z){
					if(ma[z])sum[i]+=c[i];
				}
			}
		}
		sort(vl+1,vl+n+1,cmp);
		g[ff]=vl[1];ma[vl[1]]=1;
		sum[vl[1]]=1e18;
		for(int i=1;i<=n;++i){
			if(!ma[i])sum[i]=0;
		}
	}
	memset(ma,0,sizeof(ma));
	for(int i=1;i<=n;++i){
		int f=g[i];
		int su=0;
		ma[f]=1;
		for(int j=l[f];j<=r[f];++j){
			if(!ma[j])su++; 
		}
		ans+=su*c[f];
	}
	wr(ans);
	return 0;
} 
/*
5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5
*/
