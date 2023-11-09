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
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
}
const int N=1e6+5;
const int mod=998244353;
int n;
bool fl=1,f2=1,vis[N];
int x[N],y[N];
int ans;
inline void dfs(){
	int sum=0;
	for(int i=1;i<n;++i){
		int l=x[i],r=y[i];
		if(!vis[l]&&!vis[r]){
			vis[l]=1;dfs();vis[l]=0;
			vis[r]=1;dfs();vis[r]=0;
			sum++;
			break;
		}
	}	
	if(sum==0){
		ans++;
		return;
	}
}
int main(){
	FRE();
	n=rd();
	for(int i=1;i<n;++i){
		x[i]=rd(),y[i]=rd();
		if(x[i]!=1)fl=0; 
		if(x[i]!=i||y[i]!=i+1)f2=0;
	}
	if(fl){
		printf("%d",n);
		return 0;
	}
//	if(f2){
//		
//		return 0; 
//	}
	dfs();
	wr(ans);
	return 0;
}
/*
5
1 2
1 3
1 4
1 5
*/
/*
7
7 2
7 6
1 2
7 5
4 7
3 5
*/
