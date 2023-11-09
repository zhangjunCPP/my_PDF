/*
Sakurajima Mai,
Eriri Spencer,
Izumi Sagiri,
Keqing,
Hu tao,
Ganyu
say,"With our sincere wishes to HHX: never to debug code"
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
}
int p,s,a,b;
inline void cheak_hl(int x){
	for (int i=1;i*i<=x;i++)
		if (x%i==0){
			a=i,b=x/i;
			if (p-2*a-2*b==0){
				for (int i=1;i<=a;i++) printf("2");
				printf("3");
				for (int i=1;i<b;i++) printf("2");
				printf("3");
				for (int i=1;i<a;i++) printf("2");
				printf("3");
				for (int i=1;i<b;i++) printf("2");
				exit(0);
			}
		}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	p=read(),s=read();
	if (p&1){ printf("Impossible"); return 0; }
	cheak_hl(s);
	printf("Impossible");
	return 0;
}
