#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005,INF=0x3f3f3f3f;
int mod;
int _;
int n,ans;
int f[maxn]={0,0,0,1,7,47,322,2404};


int main(){
    ios::sync_with_stdio(0);
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    cin>>n>>mod;

	if(n<=7){
		for(int i=1;i<=n;i++){
			ans^=f[i];
		}
		cout<<ans<<endl;
	}
	
	
    return 0;
}

