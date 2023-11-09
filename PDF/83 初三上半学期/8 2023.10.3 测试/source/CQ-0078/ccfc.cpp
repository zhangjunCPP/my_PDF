/*
不等式求解
O(n^3) 
*/
#include<bits/stdc++.h>
void read(int &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	if(f)x=-x;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	char stk[14];int tot=0;
	do stk[++tot]=x%10+48,x/=10;while(x);
	for(;tot;tot--)putchar(stk[tot]);
}
const int maxn=1e5+4;
char jk[maxn];
int n,ans;
signed main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",jk+1);n=std::strlen(jk+1);
	for(int i=1,len=n;i<=n;++i,len--){
		ans=0;
		for(int x=1;3*x<len;++x){
			int cnt=1;
			int y=len-3*x;
			for(int j=i,k=i+x;j<=i+x-1;++j,++k)
				if(jk[j]!=jk[k])cnt=0;
			for(int j=i,k=i+x+x+y;j<=i+x-1;++j,++k)
				if(jk[j]!=jk[k])cnt=0;
			ans+=cnt;
		}
		write(ans);putchar(' ');
	}
	return 0;
}
