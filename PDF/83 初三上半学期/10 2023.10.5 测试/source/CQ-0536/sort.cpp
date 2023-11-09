#include<stdio.h>
#include<vector>

using std::vector;
const int N=7e5+5;
int cnt;
int sor(vector<int> a,int n){
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);
//	printf("\n");
	if(n==1) return a[1];
	if(n==0) return 0;
	int mid=a[(n+1)/2];
	int cl=0,cr=0;vector<int> l,r;
	l.push_back(0);r.push_back(0);
	for(int i=1;i<=n;i++){
		cnt++;
		if(a[i]<mid) l.push_back(a[i]),cl++;
		if(a[i]>mid) r.push_back(a[i]),cr++;
	}
	return sor(l,cl)+mid+sor(r,cr);
}
int n;
vector<int> a(N);
bool check(){
	int ci=0;
	for(int i=1;i<=n/2;i++) if(a[++ci]!=i*2) return 0;
	for(int i=1;i<=(n+1)/2;i++) if(a[++ci]!=n-(!(n&1))-i*2+2) return 0;
	return 1;
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(check()){
		printf("%lld\n",(long long)n*(n+1)/2ll-1ll);
		return 0;
	}
	sor(a,n);
	printf("%d\n",cnt);
	return 0;
}

