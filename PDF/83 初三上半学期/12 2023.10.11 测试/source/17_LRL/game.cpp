#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e5+10;
/*有多少个简单环就可以在合法前提下删多少条边
怎么求一个无向图简单环的个数?*/
int T,n,m,k,u,v,tmp;
char s[N];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),k=read();
		scanf("%s",s+1);
		for(int i=1;i<=m;++i)u=read(),v=read();
		tmp=(m-n+1+1)%k;
		if(!tmp)tmp=k;
		printf(s[tmp]=='G'?"P\n":"G\n");
	}
	return 0;
}
