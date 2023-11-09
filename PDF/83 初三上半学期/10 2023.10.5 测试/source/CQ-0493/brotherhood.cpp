#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7,N=1e5+10;
struct node{
	ll z[3][3];int tot;
	void init(){
		for(int i=0;i<tot;i++)for(int j=0;j<tot;j++)z[i][j]=0;
	}
	node mul(node x,node y){
		node ans;ans.init();
		for(int i=0;i<tot;i++)for(int j=0;j<tot;j++)for(int k=0;k<tot;k++){
			ans.z[i][j]=(ans.z[i][j]+x.z[i][k]*y.z[k][j]%mod)%mod;
		}
		return ans;
	}
	node pw(node x,int cnt){
		node ans;ans.init();for(int i=0;i<tot;i++)ans.z[i][i]=1;
		while(cnt){
			if(cnt&1)ans=mul(ans,x);
			x=mul(x,x);
			cnt>>=1;
		}
		return ans;
	}
}t1,t2;
int n;
ll ze[N],on[N],oo[N];
char a[N];
string f[15];
void solve(){
	scanf("%s",a+1);int m=strlen(a+1);
	int flag=1;
	for(int i=1;i<=m;i++)if(a[i]!=a[1])flag=0;
	if(flag){
		if(a[1]=='0'&&m==1){
			printf("%lld\n",ze[n]);
			return;
		}
		if(a[1]=='1'&&m==1){
			printf("%lld\n",on[n]);
			return;
		}
		if(a[1]=='1'&&m==2){
			printf("%lld\n",oo[n]);
			return;
		}
		printf("0\n");return;
	}
	if(n==1){printf("0\n");return;}
	if(n<=10){
		int ans=0;
		if((int)f[n].size()<m){printf("0\n");return;}
		for(int i=0;i+m-1<(int)f[n].size();i++){
			int flag=1;
			for(int j=0;j<m;j++)if(f[n][i+j]!=a[j+1]){flag=0;break;}
			ans+=flag;
		}
		printf("%d\n",ans);
		return;
	}
}
int main(){
	freopen("brotherhood.in","r",stdin);
	freopen("brotherhood.out","w",stdout);
	int T;
	scanf("%d%d",&n,&T);
	if(n<=10){
		f[1]+='0',f[2]+='1';
		for(int i=3;i<=n;i++){
			f[i]=f[i-1]+f[i-2];
		}
	}
	ze[1]=1;for(int i=3;i<=n;i++)ze[i]=(ze[i-1]+ze[i-2])%mod;
	on[2]=1;for(int i=3;i<=n;i++)on[i]=(on[i-1]+on[i-2])%mod;
	oo[5]=oo[6]=1;for(int i=7;i<=n;i++)oo[i]=(oo[i-1]+oo[i-2]+(i&1))%mod;
	while(T--)solve();
	return 0;
}
