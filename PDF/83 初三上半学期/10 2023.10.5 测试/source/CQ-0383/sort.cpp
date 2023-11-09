#include<bits/stdc++.h> 
using namespace std;
int n,ans;
int a[700005],la[700005],ra[700005];
void mysort(int st,int ed){
	if(st>=ed)return;
	int mid=a[(st+ed)/2],l=0,r=0;
	for(int i=st;i<=ed;i++){
		++ans;
		if(a[i]<mid)la[++l]=a[i];
		if(a[i]>mid)ra[++r]=a[i];
	}
	for(int i=1;i<=l;i++)a[st+i-1]=la[i];
	for(int i=1;i<=r;i++)a[st+l+i-1]=ra[i];
	mysort(st,st+l-1);
	mysort(st+l,ed-1);
}
void Freopen(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	mysort(1,n);
	printf("%d\n",ans);
}
/*
5
4 3 5 1 2

*/
