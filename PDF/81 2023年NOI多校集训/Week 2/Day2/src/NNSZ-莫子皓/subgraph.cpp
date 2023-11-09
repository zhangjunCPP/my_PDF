#include <bits/stdc++.h>
using namespace std;
int n,m,M,N,B,x,y;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main()
{
	freopen("subgraph.in","r",stdin);
	freopen("subgraph.out","w",stdout);
	n=read();m=read();M=read();N=read();B=read();
	for(int i=1;i<=m;i++){
		x=read();y=read();
	}
	cout<<n-1<<' '<<(M-N)*(n-1)+B*n;
	return 0;
}
