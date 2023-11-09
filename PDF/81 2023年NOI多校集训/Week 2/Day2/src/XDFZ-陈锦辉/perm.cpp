//the code is from chenjh
#include<bits/stdc++.h>
using namespace std;
int n,mod;
int solve(int x){
	int a[101],q[101];
	for(int i=1;i<=x;i++) a[i]=i;
	int ret=0;
	do{
		for(int i=1;i<=x;i++)q[a[i]]=i;
//		for(int i=1;i<=x;i++) printf("%d ",a[i]);
//		puts("");
//		for(int i=1;i<=x;i++) printf("%d ",q[i]);
//		puts("\n");
		int i=1;
		for(;i<=n && a[i]==q[i];i++);
		if(i<=n && a[i]<q[i])
			++ret,ret=ret>=mod?ret-mod:ret;
	}while(next_permutation(a+1,a+x+1));
//	printf("%d\n",ret);
	return ret;
}
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	scanf("%d%d",&n,&mod);
	int ans=0;
	for(int i=1;i<=n;i++) ans^=solve(i);
	printf("%d\n",ans);
	return 0;
}

