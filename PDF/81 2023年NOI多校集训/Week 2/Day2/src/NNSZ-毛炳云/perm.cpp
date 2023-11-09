//测试点1-11的数据范围很小，可以直接搜索
//只能暴力全排列 
#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
long long n,mod;
int p[N],q[N];
long long ans;
bool used[N];
long long lst=0;

void dfs(int x,int cnt,int ta){
	used[x]=1;
	p[cnt]=x;
	q[p[cnt]]=cnt;
	/*for(int i=1;i<=cnt;i++){
		printf("%d %d\n",p[i],q[i]);
		if(q[i]!=0&&q[i]<p[i])return;
	}*/
	if(cnt==ta){
		int f=0;
		for(int i=1;i<=ta;i++){
			if(p[i]>q[i])break;
			else if(q[i]>p[i]){
				f=1;break;
			}
		}
		if(f)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=ta;i++){
		if(used[i])continue;
		dfs(i,cnt+1,ta);
		used[i]=0;p[cnt+1]=0;
		q[p[cnt+1]]=0;
	}
	used[x]=0;
	p[cnt]=0;
	q[p[cnt]]=0;
}


int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	scanf("%lld%lld",&n,&mod);
	for(int k=1;k<=n;k++){
		ans=0;
		for(int i=1;i<=k;i++){
			dfs(i,1,k);
		}
		//printf("ans%d\n",ans);
		ans%=mod;
		lst=lst^ans;
	}
	printf("%lld",lst);
	return 0;
}
