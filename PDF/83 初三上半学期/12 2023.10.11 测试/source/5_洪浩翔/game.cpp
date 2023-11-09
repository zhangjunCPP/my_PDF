#include<bits/stdc++.h>
const int QWQ=1e5+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} 
char op[QWQ];
int t,n,m,k;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout); 
	t=read();
	while (t--){
		n=read(),m=read(),k=read();
		scanf("%s",op+1);
		for (int i=1;i<=m;i++) int x=read(),y=read();
		int tik=m-n+2;
		while (tik>k) tik-=k;
		if (op[tik]=='P') puts("G");
		else puts("P");
	} 
 	return 0;
}

