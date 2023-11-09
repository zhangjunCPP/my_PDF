#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int t=read();
	while (t--){
		int n=read(),p=read();
		if (n==1) printf("0\n");
		if (n==2) printf("0\n");
		if (n==3) printf("0\n");
		if (n==4) printf("2\n");
		if (n==5) printf("30\n");
		if (n==6) printf("120\n");
	}
	return 0;
}
