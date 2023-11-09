#include<iostream>
#include<algorithm>
using namespace std;

int n,ans,other,p[21],q[21],mod;

bool check(){
	for(int i=1;i<=n;i++){
		if(p[i]>q[i]) return false;
		if(p[i]<q[i]) return true;
	}
	return false;
}

int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	cin>>n>>mod;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=k;i++) p[i]=i;
		do{
			for(int i=1;i<=k;i++) q[p[i]]=i;
			if(check()) ans++;
			ans%=mod;
		}while(next_permutation(p+1,p+k+1));
		other^=ans;
//		cout<<other<<" ";
		ans=0;
	}
	cout<<other;
	return 0;
} 
