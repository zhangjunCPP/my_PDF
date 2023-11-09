#include<bits/stdc++.h>
using namespace std;
int n,a[700050],s[700050],cnt;
void gs(int l,int r){
	if(r<=l){
		return;
	}
	int mid=(l+r)>>1;
	gs(l,mid);
	gs(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		cnt++;
		if(a[i]<a[r]){
			s[k++]=a[i++];
		}
		else{
			s[k++]=a[j++];
		}
	}
	while(i<=mid){
		cnt++;
		s[k++]=a[i++];
	}
	while(j<=r){
		cnt++;
		s[k++]=a[j++];
	}
	for(i=1;i<=n;i++){
		a[i]=s[i];
	}
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	gs(1,n);
	cout<<cnt;
	return 0;
}
