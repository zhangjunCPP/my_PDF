#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5;
int n;
ll cst[N],cnt[N];
ll l[N],r[N],c[N];
vector<int> id;
bool cmp1(int a,int b){
	return cst[a]+cnt[a]>cst[b]+cnt[b];
}
bool cmp2(int a,int b){
	return cst[a]+cnt[a]<cst[b]+cnt[b];
}
bool cmp3(int a,int b){
	return cst[a]-cnt[a]>cst[b]-cnt[b];
}
bool cmp4(int a,int b){
	return cst[a]-cnt[a]<cst[b]-cnt[b];
}
bool cmp5(int a,int b){
	return cst[a]<cst[b];
}
bool cmp6(int a,int b){
	return cnt[a]>cnt[b];
}
ll solve(auto cmp){
	id.clear();
	for(int i=1;i<=n;i++)
		cst[i]=0;
	for(int i=1;i<=n;i++)
		for(int j=l[i];j<=r[i];j++)
			if(i!=j) cst[j]+=c[i];
	for(int i=1;i<=n;i++)
		id.push_back(i);
	sort(id.begin(),id.end(),cmp);
	ll ans=0;
	for(int i=1;i<=n;i++)
		cnt[i]=c[i]*(r[i]-l[i]),ans+=cnt[i];
	for(vector<int>::iterator it=id.begin();it!=id.end();it++){
		int p=*it;
		ans-=cst[p];
		for(int i=1;i<=n;i++)
			if(i!=p&&l[i]<=p&&r[i]>=p)
				cnt[i]-=c[i];
		for(int i=l[p];i<=r[p];i++)
			if(i!=p) cst[i]-=c[p];
		sort(it,id.end(),cmp);
	}
	return ans;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i]>>c[i];
	ll ans=0;
	ans=max(ans,solve(cmp1));
	ans=max(ans,solve(cmp2));
	ans=max(ans,solve(cmp3));
	ans=max(ans,solve(cmp4));
	ans=max(ans,solve(cmp5));
	ans=max(ans,solve(cmp6));
	cout<<ans;
	return 0;
}
/*
5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5
*/
