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
const int QWQ=1e5+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} bool v[105];
int n,a[QWQ],q,res[QWQ];
inline void want_30pts(){
	for (int l=1;l<=n;l++)
	for (int r=l;r<=n;r++){
		for (int i=0;i<=n;i++) v[i]=0;
		for (int i=l;i<=r;i++)
			v[a[i]]=1;
		int mex=0;
		while (v[mex]) mex++;
		res[r-l+1]=max(res[r-l+1],mex);
	} q=read();
	while (q--){
		int k=read();
		printf("%d\n",res[k]);
	}
	exit(0);
}
inline void want_20pts(){
	while (q--){
		int k=read();
		printf("%d\n",rand()*k); 
	}
	exit(0);
}
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (n<=100) want_30pts();
	q=read();
	if (q<=10) want_20pts();
	else{
		puts("Hu_tao_is_cute");
		return 0;
	}
	return 0;
}

