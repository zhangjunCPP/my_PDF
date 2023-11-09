#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} 
int n,v[30],choose[30],res=INT_MAX,out[30],s;
inline int max(const int &x,const int &y){ return x>y ? x:y; }
inline int min(const int &x,const int &y){ return x<y ? x:y; }
inline int cheak(const int &x,const int &y,const int &z){
	int mx=-1,mn=INT_MAX;
	mx=max(x,max(y,z));
	mn=min(x,min(y,z));
	return mx-mn;
}
void dfs(int k,int a,int b,int c){
	if (res==0) return ;
	if (k>n){
		if (cheak(a,b,c)>=res) return ;
		if (a+b+c==0) return ;
		res=cheak(a,b,c);
		memcpy(out,choose,sizeof(out));
		return ;
	}
	choose[k]=1;
	dfs(k+1,a+v[k],b,c);
	choose[k]=2;
	dfs(k+1,a,b+v[k],c);
	choose[k]=3;
	dfs(k+1,a,b,c+v[k]);
}
void bdfs(int k,int a,int b,int c){
	if (a>s||b>s||c>s) return ;
	if (k>n){
		if (a<s||b<s||c<s) return ;
		for (int i=1;i<=n;i++)
			printf("%d ",choose[i]);
		exit(0);
	}
	choose[k]=1;
	bdfs(k+1,a+v[k],b,c);
	choose[k]=2;
	bdfs(k+1,a,b+v[k],c);
	choose[k]=3;
	bdfs(k+1,a,b,c+v[k]);
}
signed main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++)
		v[i]=read(),s+=v[i];
	s/=3;
	if (n<=15){
		dfs(1,0,0,0);
		for (int i=1;i<=n;i++)
			printf("%d ",out[i]); 
	} else bdfs(1,0,0,0);
	return 0;
}
