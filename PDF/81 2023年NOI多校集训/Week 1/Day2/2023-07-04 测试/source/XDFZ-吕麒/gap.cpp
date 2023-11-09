#include<bits/stdc++.h>
#define _fre(s,b) (b+1)&&(freopen(s".in","r",stdin),0),(b+1&&b)&&(freopen(s".out","w",stdout),0)
constexpr int N=2005,mod=998244353;
int n,a[N];
namespace solve1{
	int ans,b[N];
	bool used[N];
	void dfs(int x){
		if(x==n+1){
			static int x[N];
			for(int i=1;i<=n;++i) x[i]=0;
			bool flag=1;
			for(int i=1,r;i<=n&&flag;++i){
				for(r=i;r+1<=n&&b[r+1]==b[r]+1;++r);
				for(int j=i;j<=r;++j) x[j]=std::max(x[j],r-i+1);
				for(r=i;r+1<=n&&b[r+1]==b[r]-1;++r);
				for(int j=i;j<=r;++j) x[j]=std::max(x[j],r-i+1);
				if(x[i]!=a[i]) flag=0;
			}
			if(flag) ++ans;
			return;
		}
		for(int i=1;i<=n;++i)
			if(!used[i])
				used[b[x]=i]=1,dfs(x+1),used[i]=0;
	}
	int MAIN(){
		dfs(1);
		std::printf("%d",ans);
		return 0;
	}
}
signed main(){
	_fre("gap",1);
	std::scanf("%d",&n);
	for(int i=1;i<=n;++i) std::scanf("%d",&a[i]);
	if(n<=8) return solve1::MAIN();
//	solve1::MAIN();
	return 0;
}
/*
all 1:1,0,0,2,14,90,646,5242,47622
no idea...
can get 20pts maybe...eee
xxx,len=x,but then nothing...
you know i'm think about how to search
*/
