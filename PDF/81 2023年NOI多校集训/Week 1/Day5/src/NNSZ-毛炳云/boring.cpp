#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=1e5+5;
int a[N],b[N];
int n,q;
int qu[N*2];
int main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	while(q--){
		int k; 
		memset(b,0,sizeof(b));int cnt=0;
		int ma=0;
		scanf("%d",&k);
		for(int i=1;i<=2*k;i++){
			scanf("%d",&qu[i]);
		}
		for(int i=1;i<=2*k;i+=2){
			int l=qu[i],r=qu[i+1];
			for(int j=l;j<=r;j++){
				b[++cnt]=a[j];
				ma=max(ma,a[j]);
			}
		}
		
		int bi=1;int ans=0;
		for(int i=ma;;i=ma*bi){
			int f=0;
			for(int j=1;j<=cnt;j++){
				if(b[j]%i!=0){
					f=1;break;
				}
			}
			if(f){
				bi++;
				continue;	
			}
			else{
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
