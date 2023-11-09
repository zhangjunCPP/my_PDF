#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
const int MAXM=1e3+10;
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int a[MAXN],b[MAXN],len; 
int mex[MAXM][MAXM];
bool vis[MAXN];
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	int n; read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int l=1;l<=n;l++){
		mex[l][l]=(a[l]==0?1:0);
		int mx=a[l]; vis[a[l]]=1;
		for(int r=l+1;r<=n;r++){
			if(a[r]>mx) mx=a[r]; 
			vis[a[r]]=1; bool flag=false;
			for(int i=0;i<=mx;i++){
				if(!vis[i]){
					flag=true;
					mex[l][r]=i;
					break;
				}
			}
			if(!flag) mex[l][r]=mx+1;
		}
		memset(vis,0,sizeof(vis));
	}
//	printf("mex: %d\n",mex[1][6]);
	int q; read(q);
	while(q--){
		int k; read(k);
		int ans=0;
		for(int l=1;;l++){
			int r=k+l-1; if(r>n) break;
			ans=max(ans,mex[l][r]);
		}
		write(ans); putchar('\n');
	}
	return 0;
}

