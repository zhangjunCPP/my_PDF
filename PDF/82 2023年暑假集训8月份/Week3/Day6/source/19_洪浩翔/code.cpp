#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
}
int a,b;
signed main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	a=read(),b=read();
	if (a*b<=200000){
		for (int i=1;i<=a*b-1;i++)
			putchar('1');
		return 0;
	} else{
		a--,--b;
		while (a--) putchar('1');
		while (b--) putchar('0');
	}
	return 0;
}

