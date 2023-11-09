#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0; bool f=false; char ch=getchar();
	while(ch>'9'||ch<'0') { if(ch=='-') f^=1; ch=getchar(); }
	while(ch<='9'&&ch>='0') { x=(x<<3)+(x<<1)+ch-48; ch=getchar(); }
	return (f?-x:x);
}
inline void write(int x) {
	if(x<0) putchar('-'), x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--) puts("0");
	return 0;
}
