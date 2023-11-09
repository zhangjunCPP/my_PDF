#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=5e5+5;
int a[maxn];
bool v[maxn];
int main(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int ans=0,last=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[j]==a[i]){
				for(int k=1;k<=n;k++){
					v[k]=0;
				}
				for(int k=last+1;k<j;k++){
					v[a[k]]=1;
				}
				bool flag=0;
				for(int k=j+1;k<i;k++){
					if(v[a[k]]){
						flag=1;
						break;
					} 
				}
				if(flag){
					last=i;
					ans++;
				}
			}
		}
	}
	cout<<ans*4; 
	return 0;
} 
