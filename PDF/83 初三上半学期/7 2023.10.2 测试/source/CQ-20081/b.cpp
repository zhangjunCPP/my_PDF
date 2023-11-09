#include<bits/stdc++.h>
#define N 2000005
#define EPS (0.0001)
#define LL long long
using namespace std;
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
int n;
LL a[N];
LL s[N];
int f(int r){//1到r全选的答案 
	double u=s[r]/(double)r;
	int iu=upper_bound(a+1,a+n+1,u+EPS)-a-1;
	return r-iu;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	if(a[1]==a[n]){
		puts("0");
		return 0;
	}
	int ans=0;
	for(int i=2;i<=n;i++)
		ans=Max(ans,f(i));
	printf("%d",ans);
	return 0;
}
