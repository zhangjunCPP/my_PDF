#include<bits/stdc++.h>
using namespace std;
inline int read(){
    char ch=getchar();int sum=0,f=1;
    while(!isdigit(ch))f=(ch=='-')?-1:1,ch=getchar();
    while(isdigit(ch))sum=(sum<<1)+(sum<<3)+(ch^48),ch=getchar();
    return sum*f;
}
int n,b[500004],dp[500004],op[500004][30];
int a[500004][20],lo[500004],ans[500004];
void init(){//处理a 
	lo[0]=-1;
	for(int i=1;i<=n;++i)lo[i]=lo[i/2]+1,a[i][0]=(1<<b[i]);
	for(int j=1;j<=lo[n];++j)
		for(int i=1;i+(1<<j)-1<=n;++i){
			a[i][j]=a[i][j-1]|a[i+(1<<(j-1))][j-1];
		}
}
int ask(int l,int r){
    int p=lo[r-l+1];
    return a[l][p]|a[r-(1<<p)+1][p];
}
int query(int l,int r){
	int jk=ask(l,r);
	for(int i=0;i<=21;++i){
		if(((jk>>i)&1)==0)return i;
	}
	return 114514;
}
int find(int i,int j){//寻找最后一个出现j的 
	int l=1,r=i,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		int kl=query(mid,i);
		if(kl==j){
			ans=mid;
			l=mid+1;
		}
		if(kl>j)l=mid+1; 
		if(kl<j)r=mid-1;
	}
	return ans;
}
int cnt=0,flag;
void write(int x){
	if(x==0){
		flag=1;
		printf("%d\n1 ",cnt);
		return;
	}
	cnt++;
	write(ans[x]);
	if(flag){
		if(x!=n)printf("%d ",x+1);
		return;
	}	
}
int main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)b[i]=read();
	init();
	for(int i=1;i<=n;++i)
		for(int j=0;j<=21;++j)
			op[i][j]=find(i,j);	
	ans[0]=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=21;++j)
			if(op[i][j]!=-1){
				if(dp[op[i][j]-1]+j>dp[i]){
					dp[i]=dp[op[i][j]-1]+j;
					ans[i]=op[i][j]-1;
				}
			}
	printf("%d ",dp[n]);
	write(n);
	return 0;
}
