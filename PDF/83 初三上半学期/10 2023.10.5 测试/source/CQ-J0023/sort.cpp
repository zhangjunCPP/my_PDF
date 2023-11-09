#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=700000;
int n;
int a[N];
ll ans=0;

void dfs1(int l,int r){
	if(l==r||l>r) return;
	int mid=(l+r)>>1;
	ans+=(ll)(r-l+1);
	dfs1(l,mid-1);
	dfs1(mid+1,r);
}

void solve_3(){
	dfs1(1,n);
	cout<<ans<<endl; 
}

void dfs2(vector<int> q){
	if(q.size()<=1) return;
	ans+=q.size();
	int mid=q[((q.size()+1)>>1)-1];
	vector<int> q1,q2;
	for(int i=0;i<q.size();i++){
		if(q[i]<mid) q1.push_back(q[i]);
		else if(q[i]>mid) q2.push_back(q[i]);
	}
	if(q1.size()>1)dfs2(q1);
	if(q2.size()>1)dfs2(q2);
}

int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d",&n);
	bool flag=1;
	vector<int> q;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q.push_back(a[i]);
		if(a[i]!=i) flag=0;
	}
	if(flag){
		solve_3();
		return 0;
	}
	dfs2(q);
	cout<<ans;
	return 0;
} 


