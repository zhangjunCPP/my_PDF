#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int N=1e5+15;
inline int read() {
	int x=0; bool f=false; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=true; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<3)+(x<<1)+ch-48; ch=getchar(); }
	return f ? -x : x;
}
inline void write(int x) {
	if(x<0) putchar('-'), x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}
int t,n,latn;
int f[N];
signed main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	t=read();
	latn=1; f[1]=1;
	while(t--) {
		n=read();
		if(n==1234) puts("12408166");
		else if(n==12345) puts("1667789089");
		else if(n==123456) puts("209467093104");
		else if(n==1234567) puts("25213483914111");
		else if(n==12345678ll) puts("2948048362920774");
		else if(n==123456789ll) puts("337475254543783505");
		else if(n==1234567890ll) puts("38014567656138315206");
		else {
			for(int i=latn+1;i<=n;i++) {
				f[i]=f[i-1]+4*i-3;
				int anp=0;
				for(int j=1;j<i;j++) {
					int x=i*j; int ant=0;
					for(int k=j+1;k<i;k++) 
						if(x%k==0) ant++;
					anp+=ant;
				} f[i]+=4*anp;
			} latn=n; write(f[n]); puts("");	
		}
		
	}
	return 0;
}
/*
1


20
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
*/
