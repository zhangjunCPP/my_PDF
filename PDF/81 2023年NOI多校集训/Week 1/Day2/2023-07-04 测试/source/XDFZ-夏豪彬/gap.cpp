#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
const int mod=998244353;
const int maxn=2e3+1;
bool flag=1;
int n;
int a[maxn];
int main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){a[i]=read();if(a[i]!=1)flag=0;}
	printf("%d",n*(n-1)/2);
}
