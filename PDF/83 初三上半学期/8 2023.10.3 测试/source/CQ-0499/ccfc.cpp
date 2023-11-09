#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
const ll N=1e6+10;
using namespace std;

int n,m,k;
char a[N];
ll b[N],h[N];
int ans[N];

ll ha(int l,int r){
	return h[r]-b[r-l+1]*h[l-1];
}

int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	
	scanf("%s",a+1);
	n=strlen(a+1);
	b[0]=1;
	For(i,1,n){
		b[i]=b[i-1]*131;
		h[i]=h[i-1]*131+a[i]-'a';
	}
	For(i,n-(n-1)/3+1,n){
		ll h1=ha(i,n);
		int len=n-i+1;
		Rep(j,n-len*3,1){
			if(ha(j,j+len-1)==h1&&ha(j+len,j+len+len-1)==h1)++ans[j];
		}
	}
	For(i,1,n)printf("%d ",ans[i]);
	
	return 0;
}
