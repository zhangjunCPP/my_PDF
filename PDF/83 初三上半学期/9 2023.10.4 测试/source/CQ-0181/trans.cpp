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
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
}
const int mod=1e9+7; 
const int N=150;
int T;
int sum;
int n,m,k;
int vl[N];
bool vis[N];
int x[N],y[N],one[N],two[N]; 
inline void dfs(int pos){
	if(pos==n+1){
		int ans=1;
		for(int i=1;i<=m;++i){
			if(vl[x[i]]==vl[y[i]]){
				if(!two[i]){
					ans=0;break; 
				}
				ans*=two[i];ans%=mod;
			}
			else{
				if(!one[i]){
					ans=0;break;
				}
				ans*=one[i];ans%=mod;
			}
		}
		sum+=ans;sum%=mod;
		return;
	}
	for(int i=1;i<=k;++i){
		vl[pos]=i;
		dfs(pos+1);
	}
}
signed main(){
	FRE();
	T=rd();
	while(T--){
		sum=0;
		n=rd(),m=rd(),k=rd();
		for(int i=1;i<=m;++i){
			x[i]=rd(),y[i]=rd();
			one[i]=rd(),two[i]=rd(); 
		}
		if(n==2){
			int ans1=1,ans2=1;
			for(int i=1;i<=m;++i){//相同 
				if(!two[i]){
					ans1=0;break; 
				}
				ans1*=two[i];ans1%=mod;
			}
			for(int i=1;i<=m;++i){//不同 
				if(!one[i]){
					ans2=0;break;
				}
				ans2*=one[i];ans2%=mod;
			}
			int ss=k*(k-1);
			sum=(ans1*k%mod)+(ans2*ss%mod);
			sum%=mod; 
			printf("%lld\n",sum);
			continue;
		}
		dfs(1);
		wr(sum);puts("");
	}
	return 0;
}
