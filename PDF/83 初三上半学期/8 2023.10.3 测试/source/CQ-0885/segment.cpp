/*
直接贪心，我们先求出整个序列的均值，
然后对于每个a[i]，我们看a[i]和a[i]+a[i+1]两者谁离均值更近就选谁 
然后大样例直接WA 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const double eps=0.1;
const int N=2e5+10;
int n,a[N],ans,s;
int ch(double p){
	int mi=s+1,mx=-1;
	for(int i=1;i<=n;i++){
		if(i==n){
			mi=min(mi,a[i]);
			mx=max(mx,a[i]);
			break;
		}
		double x=a[i],y=a[i]+a[i+1];
		if(fabs(p-x)<fabs(p-y)){
			mi=min(mi,a[i]);
			mx=max(mx,a[i]);
		}
		else{
			mi=min(mi,a[i]+a[i+1]);
			mx=max(mx,a[i]+a[i+1]);
			i++;
		}
	}
	return mx-mi;
}
void sol1(){
	s=0;
	for(int i=1;i<=n;i++)s+=a[i];
	ans=s;
	int st=clock();
	for(double p=0;p<=s&&clock()-st<=950;p+=eps){
		ans=min(ans,ch(p));
	}
	printf("%lld",ans);
}
void dfs(int i,int mi,int mx){
	if(i>n){
		ans=min(ans,mx-mi);
		return;
	}
	if(i>2&&mx-mi>ans)return;
	dfs(i+1,min(mi,a[i]),max(mx,a[i]));
	if(i<n)dfs(i+2,min(mi,a[i]+a[i+1]),max(mx,a[i]+a[i+1]));
}
void sol2(){
	s=0;
	for(int i=1;i<=n;i++)s+=a[i];
	double p=s;p/=1.0*n;
	ans=ch(p);
	dfs(1,s,0);
	cout<<ans;
}
bool check(int mid){
	for(int l=1;l<=s;l++){
		int r=l+mid;
		int fl=1;
		for(int i=1;i<=n;i++){
			if(i==n){
				if(a[i]>r||a[i]<l){
					fl=0;
				}
				continue;
			}
			if(a[i]>r||a[i]<l){
				int x=a[i]+a[i+1];
				if(x>r||x<l){
					fl=0;
					break;
				}
				else{
					i++;
				}
			}
		}
		if(fl){
			return 1;
		}
	}
	return 0;
}
void sol3(){
	s=0;
	for(int i=1;i<=n;i++)s+=a[i];
	int ans=0;
	for(int i=log2(s);i>=0;i--){
		int mid=ans+(1<<i);
		if(mid>s)continue;;
		if(!check(mid))ans=mid;
	}
	cout<<ans+1;
}
signed main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=18)sol2();
	else sol3();
	return 0;
}

