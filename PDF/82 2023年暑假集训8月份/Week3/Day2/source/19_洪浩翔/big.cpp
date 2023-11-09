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
const int mod=998244353;
const int QWQ=405;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} bool can[QWQ],choose[QWQ]; int in[QWQ];
int n,m,q,res; pair<int,int> a[QWQ]; char ch[20];
void dfs(int k){
	if (k>m){
		for (int i=1;i<=n;i++) in[i]=0;
		for (int i=1;i<=m;i++)
			if (choose[i])
				in[a[i].first]++,++in[a[i].second];
		for (int i=1;i<=n;i++)
			if (can[i]&&in[i]<2) return ;
		res++; return ;
	} if (can[a[k].first]&&can[a[k].second]){
		choose[k]=1;
		dfs(k+1);
	} choose[k]=0;
	dfs(k+1);
}
int main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=m;i++)
		a[i].first=read(),a[i].second=read();
	q=read(); 
	if (n>5){
		while (q--)
			puts("Sagiri_is_cute");
		exit(0);
	}
	while (q--){
		scanf("%s",ch+1); res=0;
		for (int i=1;i<=n;i++)
			if (ch[i]=='1') can[i]=1;
			else can[i]=0;
		dfs(1); printf("%d\n",res);
	}
	return 0;
}

