#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[1000001],t[2000001];
long double c[2000001];
long long sum1,sum2;
void add(int x){
	for(int i=x;i<=m;i+=i&-i) t[i]++;
}
int ask(int x){
	int res=0;
	for(int i=x;i>=1;i-=i&-i) res+=t[i];
	return res;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),c[++m]=a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum1+=a[i],c[++m]=(long double)sum1/i;
	sort(c+1,c+1+m);
	m=unique(c+1,c+1+m)-c-1;
	for(int i=1;i<=n;i++){
		sum2+=a[i];
		add(lower_bound(c+1,c+1+m,(long double)a[i])-c);
		ans=max(ans,i-ask(lower_bound(c+1,c+1+m,(long double)sum2/i)-c));
	}
	printf("%d",ans);
	return 0;
}
