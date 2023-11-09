#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w; 
} 
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0');
}
inline void FRE(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
}
const int N=2e5+5;
int n;
int a[N];
bool vis[N];
int ans=1e9;
inline void dfs(int pos){
	if(pos==n+1){
		int pos=1,sum=0;
		int Min=1e9,Max=0;
		while(pos<=n){
			sum+=a[pos];
			if(vis[pos]){
				Min=min(Min,sum);
				Max=max(Max,sum);
				sum=0;
			}
			pos++;
		}
		ans=min(ans,Max-Min);
		return;
	}
	vis[pos]=1;
	dfs(pos+1);
	if(vis[pos-1]==1){
		vis[pos]=0;
		if(pos<n)dfs(pos+1); 
	}
}
int main(){
	FRE(); 
	n=rd();
	for(int i=1;i<=n;++i)a[i]=rd();
	vis[0]=1;
	dfs(1);
	wr(ans);
	return 0;
} 
