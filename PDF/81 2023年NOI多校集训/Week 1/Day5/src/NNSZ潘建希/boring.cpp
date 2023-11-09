#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
long long a[10009];
int n,q;
int w,l,r,s[10009],cnt,prime[10000],zz=0;
long long da=1;
int ans[10009],b[10009];
bool v[10009],vis[10009];
void fj(long long x){
	for(int i=1;i<=zz;i++){
		if(!(x%prime[i])){
			while(!(x%prime[i])&&x!=1){
				x/=prime[i];
				b[prime[i]]++;
			}
		}
	}
	return;
}
void zs(){
	for(int i=2;i<=10000;i++){
		if(vis[i])continue;
		prime[++zz]=i;
		for(int j=1;i*j<=10000;j++)vis[i*j]=1;
	}
	return;
}
int main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	scanf("%d%d",&n,&q);
	zs();
	//for(int i=1;i<=zz;i++)cout<<prime[i];
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=q;i++){
		scanf("%d",&w);
		cnt=0;
		da=1;
		for(int j=1;j<=n;j++)s[j]=0,v[j]=false,ans[j]=0;
		for(int j=1;j<=w;j++){
			scanf("%d%d",&l,&r);
			for(int k=l;k<=r;k++)if(!v[a[k]])s[++cnt]=a[k],v[a[k]]=true;
		}
		for(int j=1;j<=cnt;j++){
			for(int k=1;k<=zz;k++)b[prime[k]]=0;
			//cout<<s[j];
			fj(s[j]);
			//for(int k=1;k<=zz;k++)cout<<b[prime[k]]<<" ";
			for(int k=1;k<=zz;k++){
				if(b[prime[k]]>ans[prime[k]])ans[prime[k]]=b[prime[k]];
			}
		}
		for(int j=1;j<=zz;j++){
			if(!ans[prime[j]])continue;
			da*=pow(prime[j],ans[prime[j]]);
			//cout<<ans[prime[j]];
			da%=N;
		}
		printf("%lld\n",da);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
