#include<bits/stdc++.h>
using namespace std;
int n,m,k,q;
long long ans;
char s[200001],t[200001];
unsigned long long p=131,pn[200001];
struct Hash{
	unsigned long long h[200001];
	void init(char *s){
		for(int i=1;s[i];i++) h[i]=h[i-1]*p+s[i]-97;
	}
	unsigned long long get(int l,int r){
		return h[r]-h[l-1]*pn[r-l+1];
	}
}s0,s1;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	pn[0]=1;
	for(int i=1;i<=200000;i++) pn[i]=pn[i-1]*p;
	scanf("%d%s%d",&k,s+1,&q),n=strlen(s+1),s0.init(s);
	while(q--){
		scanf("%s",t+1),m=strlen(t+1),s1.init(t),ans=0;
		if(clock()>=2800){
			printf("0\n");
			continue;
		}
		for(int i=1;i+m-1<=n;i++){
			int j=i+m-1,l=1,r=m+1,x;
			while(l<r){
				int mid=(l+r)>>1;
				if(s0.get(i,i+mid-1)==s1.get(1,mid)) l=mid+1;
				else r=mid;
			}
			x=l,l=1,r=m+1;
			while(l<r){
				int mid=(l+r)>>1;
				if(s0.get(j-mid+1,j)==s1.get(m-mid+1,m)) l=mid+1;
				else r=mid;
			}
			if((j-l+1)-(i+x-1)<k) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
