#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e6+2;
ll n,P,f[N],a[N],b[N],c[N],ans,T,cc[N];
void dfs(int pos){//wozhenfulecaifaxianjiale ccccccccc
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		f[i]=1;a[pos]=i;
		dfs(pos+1);
		f[i]=0;a[pos]=0;
	}
	if(pos==n+1){
		int B=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]+1){
				b[++B]=a[i]; 
				c[B]=a[i];
			}
		}
		sort(c+1,c+1+B);
		for(int i=1;i<=B;i++){
			b[i]=lower_bound(c+1,c+1+B,b[i])-c;
		}
		int cnt=0;
		for(int i=1;i<=B;i++){
			if(b[i]>i)cnt+=b[i]-i;
		}
		if(cnt>2){
			cnt=0;
			for(int i=1;i<=B;i++){
				if(b[i]>B-i+1)cnt+=b[i]-(B-i+1);
			}
			if(cnt>2){
				int B=0;
				for(int i=1;i<=n;i++){
					if(a[i]!=a[i-1]-1){
						b[++B]=a[i]; 
						c[B]=a[i];
					}
				}
				sort(c+1,c+1+B);
				for(int i=1;i<=B;i++){
					b[i]=lower_bound(c+1,c+1+B,b[i])-c;
				}
				int cnt=0;
				for(int i=1;i<=B;i++){
					if(b[i]>i)cnt+=b[i]-i;
				}
				if(cnt>2){
					cnt=0;
					for(int i=1;i<=B;i++){
						if(b[i]>B-i+1)cnt+=b[i]-(B-i+1);
					}
					if(cnt>2){
						ans=(ans+1)%P;
						cc[B]++;
					}
				} 
			}
		} 
	}
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&P);
		for(int i=1;i<=n;i++){
			cc[i]=0;
		}
		ans=0;
		dfs(1);//fAke!!!!!!±©Á¦¼ÙÁËwandanlehehe¡£¡£¡£ 
		printf("%lld\n",ans);
	}
	return 0;
}

