#include<bits/stdc++.h>
using namespace std;
int n,ans,a[2001],vis[2001],b[2001],len[2001];
void dfs(int pos){
	if(pos==n+1){
		for(int i=1;i<=n;i++){
			int now=1,k=-1,ks=i;
			if(i<n&&b[i]==b[i+1]-1) k=0;
			else if(i<n&&b[i]==b[i+1]+1) k=1;
			else len[i]=1;
			if(k==0){
				while(1){
					if(i<n&&b[i]==b[i+1]-1) now++,i++;
					else break;
				}
				for(int j=ks;j<=i;j++) len[j]=now;
			}
			else if(k==1){
				while(1){
					if(i<n&&b[i]==b[i+1]+1) now++,i++;
					else break;
				}
				for(int j=ks;j<=i;j++) len[j]=now;
			}
		}
		for(int i=1;i<=n;i++) if(len[i]!=a[i]) return;
		ans++;
		if(ans>=998244353) ans-=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(pos!=1&&a[pos]==1&&abs(b[pos-1]-i)<=1) continue;
			vis[i]=1;
			b[pos]=i;
			dfs(pos+1);
			vis[i]=0;
		}
	}
}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	dfs(1);
	printf("%d",ans);
	return 0;
}
