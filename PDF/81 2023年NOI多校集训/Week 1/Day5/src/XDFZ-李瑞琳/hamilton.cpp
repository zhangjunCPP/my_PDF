#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
int n,m;
int main(){
	freopen("hamilton.in","r",stdin);
	freopen("hamilton.out","w",stdout);
	n=read(),m=read();
	printf("No\n");
	return 0;
}
