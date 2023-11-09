#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=5e5+5;
int c[maxn],dp[maxn],pre[maxn];
int cnt[maxn][21];
set< pair<int,int> > st;
struct Tree{
	int l,r;
	int maxx,id;
}T[maxn<<2];
inline void push_up(int rt){
	if(T[rt<<1].maxx>=T[rt<<1|1].maxx){
		T[rt].maxx=T[rt<<1].maxx;
		T[rt].id=T[rt<<1].id;
	}
	else{
		T[rt].maxx=T[rt<<1|1].maxx;
		T[rt].id=T[rt<<1|1].id;
	}
}
inline void build(int rt,int l,int r){
	T[rt].l=l,T[rt].r=r;
	T[rt].maxx=T[rt].id=0; 
	if(l==r){
		T[rt].id=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r); 
	push_up(rt);
}
inline void up_data(int rt,int pos,int val){
	if(T[rt].l==T[rt].r){
		T[rt].maxx+=val;
		return ;
	}
	int mid=(T[rt].l+T[rt].r)>>1;
	if(pos<=mid) up_data(rt<<1,pos,val);
	else up_data(rt<<1|1,pos,val);
	push_up(rt); 
}
inline pair<int,int> query(int rt,int l,int r){
	if(l<=T[rt].l && T[rt].r<=r){
		return make_pair(T[rt].maxx,T[rt].id);
	}
	int mid=(T[rt].l+T[rt].r)>>1;
	pair<int,int> ans;
	if(l<=mid) ans=max(ans,query(rt<<1,l,r));
	if(r>mid) ans=max(ans,query(rt<<1|1,l,r));
	return ans;
}
inline void add(int pos,int val,int op){
	if(op>20) return ;
	pos++;
	for(int i=pos;i<=n+1;i+=i&-i){
		cnt[i][op]+=val;
	}
}
inline int query2(int pos,int op){
	if(op>20) return 0;
	pos++;
	int ret=0;
	for(int i=pos;i;i-=i&-i){
		ret+=cnt[i][op];
	}
	return ret;
}
stack<int> ans;
int main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	build(1,0,n);
	dp[0]=0; st.insert(make_pair(0,0)); 
	for(int i=1;i<=n;i++){
		add(0,1,c[i]); add(i,-1,c[i]);
		set< pair<int,int> >::iterator it=st.lower_bound(make_pair(c[i],0));
		while(it!=st.end() && (*it).first==c[i]){
			int id=(*it).second,mex=(*it).first;
			while(query2(id,mex)){
				mex++;
			}
			up_data(1,id,mex-c[i]);
			st.erase(it);
			st.insert(make_pair(mex,id));
			it=st.lower_bound(make_pair(c[i],0));
		}
		pair<int,int> sum=query(1,0,i-1);
		pre[i]=sum.second;
		dp[i]=sum.first;
		up_data(1,i,dp[i]);
		st.insert(make_pair(0,i));
	}
	int i=n,sum=0;
	for( ; i ;i=pre[i]){
		sum++;
		ans.push(pre[i]+1);
	} 
	printf("%d %d\n",dp[n],sum);
	while(!ans.empty()){
		int x=ans.top(); ans.pop();
		printf("%d ",x);
	}
	return 0;
} 
