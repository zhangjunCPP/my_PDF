#include<bits/stdc++.h>
using namespace std;
inline int read(){
    char ch=getchar();int sum=0,f=1;
    while(!isdigit(ch))f=(ch=='-')?-1:1,ch=getchar();
    while(isdigit(ch))sum=(sum<<1)+(sum<<3)+(ch^48),ch=getchar();
    return sum*f;
}
const int mod=1e9+7;
int dep[30];
struct ST{
    int minn[30][30],log[30];
    ST(){memset(minn,0x3f,sizeof(minn));}
    void build(int *a,int n){
        log[0]=-1;
        for(int i=1;i<=n;++i)minn[i][0]=a[i],log[i]=log[i/2]+1;
        for(int j=1;j<=log[n];++j)
            for(int i=1;i+(1<<j)-1<=n;++i)
                minn[i][j]=(dep[minn[i][j-1]]<dep[minn[i+(1<<(j-1))][j-1]]?minn[i][j-1]:minn[i+(1<<(j-1))][j-1]);
    }
    int ask(int l,int r){
        int p=log[r-l+1];
        return (dep[minn[l][p]]<dep[minn[r-(1<<p)+1][p]]?minn[l][p]:minn[r-(1<<p)+1][p]);
    }
}f;
int id[30],euler[30],pos;
vector<int>E[30];
int LCA(int x,int y){//查x、y的LCA 
    return f.ask(min(id[x],id[y]),max(id[x],id[y]));
}
int DIS(int x,int y){//查x、y的距离 
    return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
void dfs(int x,int fa){
    euler[++pos]=x;
    if(!id[x])id[x]=pos;
    for(int v:E[x]){
        if(v==fa)continue;
        dep[v]=dep[x]+1;
        dfs(v,x);
        euler[++pos]=x;
    }
}
int col[30];
int n,ans=0;
int fast_pow(int x,int y){
	int res=1;
	for(;y;y>>=1,x=x*x%mod)if(y&1)res=res*x%mod;
	return res;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	if(n<=10){
		for(int i=1;i<n;++i){
			int x=read(),y=read();
			E[x].push_back(y);E[y].push_back(x);
		}
		dep[1]=1;
    	dfs(1,0);
    	f.build(euler,pos);
		for(int i=0;i<(1<<n);++i){
			int cnt=0;
			for(int j=1;j<=n;++j)col[j]=(i>>(j-1))&1;
			for(int x=1;x<=n;++x)
				for(int y=1;y<=n;++y)
					if(x!=y&&col[x]==col[y])
						cnt=max(cnt,DIS(x,y));
			ans=(ans+cnt)%mod;
		}
		printf("%d",ans);
	}
	else{
		if(n%2==1){
			int cnt=0;
			for(int i=n/2+1;i<=n-1;++i)cnt=(cnt+fast_pow(2,i-n+i-1))%mod;
			ans=(cnt+fast_pow(2,n-2))*2;
			cout<<ans;
		}
		else{
			int cnt=0;
			for(int i=n/2+1;i<=n-1;++i)if(i>1)cnt+=(max(1,fast_pow(2,max(0,i-(n-i)-1))-1)*(i-1));
			cnt=cnt*2;ans=(cnt+fast_pow(2,n-2)*(n-1)+(n%2==0?n/2-1:0))*2;
			cout<<ans;			
		}
	}
	return 0;
}
