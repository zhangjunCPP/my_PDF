#include<bits/stdc++.h>

using namespace std;
char a[222222],b[222222];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int k;
	cin>>k;
	cin>>a+1;
	int n=strlen(a+1);
	int q;
	cin>>q;
	while(q--){
		cin>>b+1;
		int m=strlen(b+1);
		int ans=0;
		for(int i=1;i+m-1<=n;i++){
			int l=0x3f3f3f3f;
			int r=0;
			for(int j=i;j<=i+m-1;j++){
				if(a[j]!=b[j-i+1]){
					l=min(l,j);
					r=max(r,j);
				}
			}
			if(r-l<k){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
