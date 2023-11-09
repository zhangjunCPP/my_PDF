#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=100005,INF=0x3f3f3f3f,mod=998244353;
int _;
int n;
int a[maxn];

int fac(int x){
	int res=1;
	for(int i=2;i<=x;i++){
		(res*=i)%=mod;
	}
	return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin>>n;
    
    cout<<fac(n);
    return 0;
    
    bool f1=1,f2=1;
    
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=1)f1=0;
    	if(a[i]!=n)f2=0;
	}
    
    if(f1){
    	cout<<fac(n)<<endl;
	}
	else if(f2){
		cout<<2<<endl;
	}
    
    return 0 ^ _ ^ 0;
}

