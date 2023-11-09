#include<bits/stdc++.h>

using namespace std;
struct node{
	int a,b;
}a[222222];
int main(){
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
	int n;
	cin>>n;
	int fl=0,fll=0;
	for(int i=1;i<n;i++){
		cin>>a[i].a>>a[i].b;
		if(a[i].a>a[i].b) swap(a[i].a,a[i].b);
		if(a[i].a!=1){
			fl=1;
		}
		if(a[i].a!=i||a[i].b!=i+1){
			fll=1;
		}
	}
	if(fl==0){
		cout<<n;
		return 0;
	}
	if(fll==0){
		int ans=2;
		int x=0;
		for(int i=3;i<=n;i++){	
			x++;
			ans+=x;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

