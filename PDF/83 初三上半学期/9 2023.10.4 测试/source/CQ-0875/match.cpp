#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+5,P=131;
int k,n,m,id[N];
char s[N],t[N];
ull h[N],p[N],ha[N];
ull get(int l,int r){
	return h[r]-h[l-1]*p[r-l+1];
}
ull gt(int l,int r){
	return ha[r]-ha[l-1]*p[r-l+1];
}
int lcp(int l1,int r1,int l2,int r2){
	int l=0,r=min(r1-l1+1,r2-l2+1),mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(get(l1,l1+mid-1)==get(l2,l2+mid-1)) l=mid;
		else r=mid-1;
	}
	return l;
}
bool cmp(int x,int y){
	int t=lcp(x,n,y,n);
	return s[x+t]<=s[y+t];
}
int lp(int l1,int r1,int l2,int r2){
	int l=0,r=min(r1-l1+1,r2-l2+1),mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(gt(l1,l1+mid-1)==get(l2,l2+mid-1)) l=mid;
		else r=mid-1;
	}
	return l;
}
int find1(int x){
	if(!x) return 1;
	int l=1,r=n,mid,now,len;
	while(l<r){
		mid=(l+r)>>1,now=id[mid],len=lp(1,x,now,n);
		if(len==x||t[len+1]<=s[now+len]) r=mid;
		else l=mid+1;
	}
	return l;
}
int find2(int x){
	if(!x) return n;
	int l=1,r=n,mid,now,len;
	while(l<r){
		mid=(l+r+1)>>1,now=id[mid],len=lp(1,x,now,n);
		if(len==x||t[len+1]>=s[now+len]) l=mid;
		else r=mid-1;
	}
	return r;
}
bool flag[N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);	
	scanf("%d",&k);
	scanf("%s",s+1),n=strlen(s+1),s[n+1]='%';
	p[0]=1; for(int i=1;i<=n;++i) p[i]=p[i-1]*P,h[i]=h[i-1]*P+(s[i]-'a'),id[i]=i;
	sort(id+1,id+n+1,cmp);
	int q,ans; scanf("%d",&q);
	while(q--){
		scanf("%s",t+1),m=strlen(t+1);
		if(m<=k){ printf("%d\n",n); continue; }
		for(int i=1;i<=m;++i) ha[i]=ha[i-1]*P+(t[i]-'a');
		for(int l=0,r,t1,t2;l<=m-k;++l){
			r=l+k+1,ans=0,t1=find1(l);
			if(lp(1,l,id[t1],n)!=l) continue;
			t2=find2(l);
			if(r>m){
				for(int i=t1;i<=t2;++i) flag[id[i]]=true;
				continue;
			}
			for(int i=t1;i<=t2;++i) if(id[i]+m-1<=n&&lp(r,m,id[i]+r-1,id[i]+m-1)==m-r+1) flag[id[i]]=true;
		}
		for(int i=1;i<=n;++i) ans+=(flag[i]&&i+m-1<=n),flag[i]=false;
		printf("%d\n",ans);
	}
	
	return 0;
}
