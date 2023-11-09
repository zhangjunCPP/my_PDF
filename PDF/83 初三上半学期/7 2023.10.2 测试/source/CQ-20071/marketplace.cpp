/*
暴力就不能给慷慨点？
分段就不能分多点？
可恶的Chimata，怕不是个奸商（恼） 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],use[N],b[N],mem;
int calc(int x,int f){//不会买x，返回结束下标 
	if(x==0&&mem)return mem;
	while(1){
		for(int i=1;i<=n;++i){
			if(a[i]!=x&&use[a[i]]!=f)use[a[i]]=f;
			else if(b[i]!=x&&use[b[i]]!=f)use[b[i]]=f;
			else return x==0?(mem=i):i;
		}
	}
}
int m,i,x,ans[N];
bool vis[N];
int main(){
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d%d",a+i,b+i);
//		if(a[i]>b[i])swap(a[i],b[i]);
		vis[a[i]]=vis[b[i]]=1;
	}
	for(x=1;x<=m;++x){
		if(!vis[x])++ans[calc(0,x)];
		else ++ans[calc(x,x)];
	}
	for(i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}

