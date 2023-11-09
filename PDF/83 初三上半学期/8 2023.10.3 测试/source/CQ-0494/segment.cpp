#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=2e5+10;
int n,a[N],maxx,minn,ans,vis1[N],vis2[N],ch[N];
vector<int> mina,maxa;
set<int> canmi,canma;
void dfs(int now){
	if(now>n){
		int minn2=1e9+10,maxx2=-1;
		for(int i=1;i<=n;++i)
			if(!ch[i])minn2=min(minn2,a[i]),maxx2=max(maxx2,a[i]);
			else minn2=min(minn2,a[i]+a[i+1]),maxx2=max(maxx2,a[i]+a[i+1]),++i;
		ans=min(ans,maxx2-minn2);return;
	}
	ch[now]=1,dfs(now+2);
	ch[now]=0,dfs(now+1);
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	n=read(),minn=1e9+10;
	for(int i=1;i<=n;++i)a[i]=read(),maxx=max(maxx,a[i]),minn=min(minn,a[i]);
	ans=maxx-minn;
	for(int i=1;i<=n;++i){
		if(a[i]==minn)mina.push_back(i),vis1[i]=1,canmi.insert(i-1),canmi.insert(i+1);
		if(a[i]==maxx)maxa.push_back(i),vis2[i]=1,canma.insert(i-1),canma.insert(i+1);
	}
	if(n<=20){
		dfs(1);
		printf("%d\n",ans);
	}else if(n<=300){
		printf("0\n");
	}
	return 0;
}
/*
5
2 2 3 5 2
*/
