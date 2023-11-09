#include<bits/stdc++.h>
#define ll long long
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
const ll mod=1e9+7;
int n,flag,sum,fir;
ll jc[1005],inv[1005];
char a[505];
ll C(int n,int m){
	if(n<m)
		return 0;
	return jc[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
	n=read();
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		if((a[i]=='1'&&a[i+1]=='0')||a[i]=='?')
			flag++;
		sum+=(a[i]-'0');
		if(sum==1&&!fir)
			fir=i;
	}
	jc[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=n+n;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	for(int i=2;i<=n+n;i++){
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=1;i<=n+n;i++){
		inv[i]=inv[i-1]*inv[i]%mod;
	}
	if(flag<=1){
		work(C(n-sum+1+sum/2-1,sum/2));
		return 0;
	}
	return 0;
}
