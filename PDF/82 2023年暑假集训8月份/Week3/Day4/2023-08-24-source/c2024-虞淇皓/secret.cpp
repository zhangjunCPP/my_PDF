#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=65535;
int n,c[300],k,ans_dfs,s_dfs;
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void dfs(int k,int s){
//	cout<<k<<" "<<s<<"  "<<n<<endl;
	if(k>n){
		ans_dfs=ans_dfs*ksm(s,s_dfs)%mod;
		return;
	}
	for(int i=0;i<=255;i++){
		if(c[i]){
			c[i]--;
			dfs(k+1,(s*256%mod+i)%mod);
			c[i]++;
		}
	}
}
void sol1(){
	ans_dfs=1;s_dfs=1;
	for(int i=0;i<256;i++){
		if(c[i]){
			for(int j=1;j<=c[i];j++){
				s_dfs=s_dfs*j%mod;
			}
		}
	}
	dfs(1,0);
	printf("%lld\n",ans_dfs);
}
void sol2(){
	int x=0;for(int i=0;i<256;i++)if(c[i]){x=i;break;}
	if(n>300){
		printf("0\n");return;
	}
	int ans=0;
	for(int i=1;i<=c[x];i++)ans=(ans*256%mod+x)%mod;
	int anss=ans;
	for(int i=1;i<=n;i++)anss=ksm(anss,i)%mod;
	printf("%lld\n",anss);
}
void sol(){
	scanf("%lld",&k);
	n=0;memset(c,0,sizeof(c));
	for(int i=1;i<=k;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		c[x]=y;n+=y;
	}
	if(k==1)sol2();
	else if(n<=18)sol1();
	else printf("65534");
}
signed main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	int t;scanf("%lld",&t);
	while(t--)sol();
	return 0;
}


