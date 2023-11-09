#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,a[N],s[N];
int c[N],sz;
void upd(int x,int v){for(;x<=sz;x+=(x&-x))c[x]+=v;}
int ask(int x,int r=0){for(;x;x-=(x&-x))r+=c[x];return r;}
int f[12];
int check(int k){
	int ans=0;sz=11;
	for(int i=0;i<=10;i++)s[i]=c[i]=0;
	for(int i=1;i<k;i++)if(s[a[i]]++==0)/*upd(a[i]+1,1)*/;
	for(int i=k;i<=n;i++){
		if(s[a[i]]++==0)/*upd(a[i]+1,1)*/;
		int /*l=0,r=n,*/now=0;
		/*while(l<=r){
			int mid=(l+r)>>1;
			if(ask(mid+1)==mid+1)now=mid+1,l=mid+1;
			else r=mid-1;
		}*/
		while(s[now])now++;
		ans=max(ans,now);
		if(--s[a[i-k+1]]==0)/*upd(a[i-k+1]+1,-1)*/;
	}
	return ans;
}
void solve(){
	int pp=clock();
	f[0]=0;
	for(int i=1;i<=10;i++){
		int l=f[i-1],r=n,ans=n+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)>=i)ans=mid,r=mid-1;
			else l=mid+1;
		}f[i]=ans;
	}
	scanf("%d",&q);
	while(q--){
		int k;
		scanf("%d",&k);
		int tmp=upper_bound(f,f+11,k)-f-1;
		printf("%d\n",tmp);
	}
//	cout<<clock()-pp<<endl;
}
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	scanf("%d",&n);
	int f=1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),f&=(a[i]<=10);
	if(f)return solve(),0;
	scanf("%d",&q);
	while(q--){
		int k;scanf("%d",&k);
		int ans=0;sz=n+1;
		for(int i=0;i<=n;i++)s[i]=c[i]=0;
		for(int i=1;i<k;i++)if(s[a[i]]++==0)upd(a[i]+1,1);
		for(int i=k;i<=n;i++){
			if(s[a[i]]++==0)upd(a[i]+1,1);
			int l=0,r=n,now=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if(ask(mid+1)==mid+1)now=mid+1,l=mid+1;
				else r=mid-1;
			}
			ans=max(ans,now);
			if(--s[a[i-k+1]]==0)upd(a[i-k+1]+1,-1);
		}
		printf("%d\n",ans);
	}
//	cout<<endl<<clock()-pp;
	return 0;
}

