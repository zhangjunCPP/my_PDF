#include<bits/stdc++.h>
using namespace std;
int id,op,n,u,v,w,q,l,r,k,p[200001];
vector <pair<int,int> > G[200001];
long long lst;
void decode(int &l,int &r,int &k,long long lst){
	lst%=19260817;
	if(op){
		l^=lst,l=(l%n+n)%n+1;
		r^=lst,r=(r%n+n)%n+1;
		if(l>r) swap(l,r);
		k^=lst,k=(k%min(r-l+1,100))+1;
	}
}
int main(){
	freopen("voidtree.in","r",stdin);
	freopen("voidtree.out","w",stdout); 
	
	scanf("%d%d%d",&id,&op,&n);
	for(int i=2;i<=n;i++){
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&l,&r,&k);
		decode(l,r,k,lst);
		lst=0;
		if(k==1){
			printf("%lld\n",lst=0);
			continue;
		}
		for(int i=l;i<=r;i++){
			for(auto j:G[i]) lst+=j.second;
			k-=G[i].size()/5;
			if(k<=0) break;
		}
		printf("%lld\n",lst);
	}
	return 0;
}
