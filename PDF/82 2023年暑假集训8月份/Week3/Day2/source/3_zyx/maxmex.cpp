#include<bits/stdc++.h>
using namespace std;
int n,q,k,mx,tot,a[100001],st[100001][18],lg[100001],res[101][101],cnt[200001],er[101];
int query(int l,int r){
	int k=lg[r-l+1],s=st[l][k]|st[r-(1<<k)+1][k];
	for(int i=0;;i++) if(!(s>>i&1)) return i;
}
bool check(int mex,int len){
	for(int i=len;i<=n;i++) if(query(i-len+1,i)==mex) return true;
	return false;
}
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
	scanf("%d",&q);
	if(n<=100){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int l=i;l<=j;l++) cnt[a[l]]++;
				while(cnt[res[i][j]]) res[i][j]++;
				for(int l=i;l<=j;l++) cnt[a[l]]--;
			}
		}
		while(q--){
			scanf("%d",&k);
			int ans=0;
			for(int i=k;i<=n;i++) ans=max(ans,res[i-k+1][i]);
			printf("%d\n",ans);
		}
	}
	else if(mx<=10){
		for(int i=1;i<=n;i++) st[i][0]=(1<<a[i]);
		for(int k=1;k<=lg[n];k++) for(int i=1;i+(1<<k)-1<=n;i++) st[i][k]=st[i][k-1]|st[i+(1<<(k-1))][k-1];
		int len=1;
		for(int i=0;i<=mx+1;i++){
			while(1){
				if(check(i,len)) break;
				len++;
			}
			er[i]=len;
		}
		er[mx+2]=1e9;
		while(q--){
			scanf("%d",&k);
			int id=upper_bound(er+1,er+2+mx,k)-er-1;
			printf("%d\n",id);
		}
	}
	else{
		while(q--){
			scanf("%d",&k);
			int ans=0;
			for(int i=k;i<=n;i++){
				for(int l=i-k+1;l<=i;l++) cnt[a[l]]++;
				int now=0;
				while(cnt[now]) now++;
				ans=max(ans,now);
				for(int l=i-k+1;l<=i;l++) cnt[a[l]]--;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
