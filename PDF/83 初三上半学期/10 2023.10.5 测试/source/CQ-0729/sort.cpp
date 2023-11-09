#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define N 700010
#define ll long long
#define pb push_back
int n,ans,a[N],q1[N],q2[N];
void _(int n,int*a){
	if(n<=1)return;
	int mid=a[(n+1)/2],p1=0,p2=0;
	For(i,1,n){
		++ans;
		if(a[i]<mid){
			q1[++p1]=a[i];
		}else if(a[i]>mid){
			q2[++p2]=a[i];
		}
	};
	For(i,1,p1)a[i]=q1[i];
	a[p1+1]=mid;
	For(i,1,p2)a[p1+i+1]=q2[i];
	_(p1,a);
	_(p2,a+p1+1);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	For(i,1,n){
		cin>>a[i];
	};
	_(n,a);
	cout<<ans;
	return 0;
}
