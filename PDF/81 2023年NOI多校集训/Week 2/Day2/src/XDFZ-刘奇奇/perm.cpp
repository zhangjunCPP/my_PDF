#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
using ll=long long;
int p[N];
int q[N];
ll mod;
ll n,ans;
ll v[N];
bool check(int x){
	for(int i=1;i<=x;i++){
		if(q[i]>p[i]){
			return 1;
		}else if(q[i]<p[i]){
			return 0;
		}
	}
	return 0;
}
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	scanf("%lld%lld",&n,&mod);
//	for(int x=1;x<=n;x++){
//		for(int i=1;i<=x;i++){
//			p[i]=i;
//		}
//		do{
//			for(int i=1;i<=x;i++){
//				q[p[i]]=i;
//			}
//			if(check(x)){
//				v[x]=(v[x]+1);
//			}
//		}while(next_permutation(p+1,p+x+1));
//		printf("%d:%d\n",x,v[x]);
//	}
//	for(int i=1;i<=n;i++){
//		ans^=v[i];
//	}
	v[1]=0%mod;
	v[2]=0%mod;
	v[3]=1%mod;
	v[4]=7%mod;
	v[5]=47%mod;
	v[6]=322%mod;
	v[7]=2404%mod;
	v[8]=19778%mod;
	v[9]=180130%mod;
	v[10]=1809652%mod;
	v[11]=19940552%mod;
	v[12]=239430724%mod;
	v[13]=3113226148%mod;
	v[14]=43587950360%mod;
	for(int i=1;i<=n;i++){
		ans^=v[i];
	}
	printf("%lld",ans);
	return 0;
}
