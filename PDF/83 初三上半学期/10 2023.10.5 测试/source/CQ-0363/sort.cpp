#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e5+17;
int s1[N],s2[N],a[N];
int ans,n;
void sol(int l,int r){
	if(l>=r)return;
	int stand=a[(r-l)/2+l];
	ans+=(r-l+1);
	int top1=0,top2=0;
	for(int i=l;i<=r;i++){
		if(a[i]<stand){
			s1[++top1]=a[i];
		}
		if(a[i]>stand){
			s2[++top2]=a[i];
		}
	}
	for(int i=1;i<=top1;i++){
		a[l+i-1]=s1[i];
	}
	a[l+top1]=stand;
	for(int i=1;i<=top2;i++){
		a[l+top1+i]=s2[i];
	}
	sol(l,l+top1-1);
	sol(l+top1+1,r);
}
signed main(){
//	freopen("D:\\down\\sort\\sort5.in","r",stdin);
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sol(1,n);
	printf("%d",ans);
}
