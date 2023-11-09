#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=7e5+5;
int n,a[N],pos[N],L[N],R[N];
ll ans;
void solve(int l,int r,int p){
	if(r<=l) return;
	ans+=r-l+1;
	int now=p,len=r-l+1,lenl=a[p]-l,lenr=r-a[p];
	R[L[now]]=R[now],L[R[now]]=L[now],L[0]=R[0]=0;
	if(len&1) now=L[now]; else now=R[now];
	--len;
	set<int> s;
	if(lenr<lenl) for(int i=a[p]+1;i<=r;++i) s.insert(pos[i]);
	else for(int i=l;i<a[p];++i) s.insert(pos[i]);
	int las=0,x,other,t=0;
	for(auto it=s.begin();it!=s.end();++it){
		x=(*it),++t;
		if((lenr<lenl&&t==((lenr+1)>>1))||(lenr>=lenl&&t==((lenl+1)>>1))) other=x;
		R[L[x]]=R[x],L[R[x]]=L[x],L[0]=R[0]=0;
		if(x==now){
			if(len&1) now=L[now]; else now=R[now];
		}else if((x<now)==!(len&1)){
			if(x>now) now=L[now]; else now=R[now];
		}
		--len,L[x]=las,R[x]=0,R[las]=x,las=x,L[0]=R[0]=0;
	}
	solve(l,a[p]-1,(lenr>=lenl)?other:now),solve(a[p]+1,r,(lenr<lenl)?other:now);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),pos[a[i]]=i,R[i]=i+1,L[i]=i-1;
	L[1]=0,R[n]=0;
	solve(1,n,(n+1)>>1);
	printf("%lld\n",ans);
	return 0;
}
