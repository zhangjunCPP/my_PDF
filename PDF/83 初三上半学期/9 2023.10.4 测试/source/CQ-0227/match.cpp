#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+10;
ull ha[N],pw[N],hb[N];
char a[N],b[N];
ull get(ull *c,int l,int r){
	return c[r]-c[l-1]*pw[r-l+1];
}
int lcp(int L,int R){
	int l=0,r=R-L+1,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(get(ha,L,L+mid-1)==get(hb,1,mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int lcs(int L,int R){
	int l=0,r=R-L+1,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(get(ha,R-mid+1,R)==get(hb,R-L+1-mid+1,R-L+1))ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int k;
	scanf("%d%s",&k,a+1);int n=strlen(a+1);
	pw[0]=1;
	for(int i=1;i<=n;i++)ha[i]=ha[i-1]*131+a[i],pw[i]=pw[i-1]*131;
	int q;scanf("%d",&q);
	while(q--){
		scanf("%s",b+1);int m=strlen(b+1);
		if(m>n){printf("0\n");continue;}
		for(int i=1;i<=m;i++)hb[i]=hb[i-1]*131+b[i];
		int ans=0;
		for(int i=1;i+m-1<=n;i++){
			int l=lcp(i,i+m-1)+i,r=i+m-1-lcs(i,i+m-1);
			if(r-l<k)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
