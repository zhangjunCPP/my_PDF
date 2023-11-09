#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
后缀问题?SA,SAM? 
暴力Hash维护是O(n^2)的,70pts 
*/
const ll p=13331,p1=998244353,mod=1e9+7;
string s; 
ll h[100005],h1[100005],pn[100005],p1n[100005];
int n,ans[100005];
bool same(int l,int r,int x,int y){
	return ((h[r]-h[l-1]*pn[r-l+1]%mod+mod)%mod==(h[y]-h[x-1]*pn[y-x+1]%mod+mod)%mod&&(h1[r]-h1[l-1]*p1n[r-l+1])==(h1[y]-h1[x-1]*p1n[y-x+1]));
} 
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	cin>>s;
	n=s.size();
	pn[0]=p1n[0]=1;
	for(int i=1;i<=n;i++){
		pn[i]=pn[i-1]*p%mod;
		p1n[i]=p1n[i-1]*p1;
	}
	h[0]=h1[0]=s[0];
	for(int i=1;i<n;i++){
		h[i]=(h[i-1]*p+s[i])%mod;
		h1[i]=h1[i-1]*p1+s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i-2;j>=0&&j-2*(n-i)+1>=0;j--){
			int now=j-(n-i)+1,now1=now-1-(n-i)+1;
			if(same(now,j,now1,now-1)&&same(now,j,i,n-1))
				ans[now1]++;
		}
	}
	for(int i=0;i<n;i++){
		work(ans[i]);
		putchar(' ');
	}
	return 0;
}
