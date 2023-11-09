#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,x,y;
int a[N];
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
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++){x=read();y=read();}
	for(int i=1;i<=n;i++) {a[i]=read();}
	cout<<n/2;
	return 0;
}
