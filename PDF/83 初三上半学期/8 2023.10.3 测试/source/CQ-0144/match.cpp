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
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}
const int N=1e6+5;
int n,m;
bool vis[N];
int a[5][N];
int G[5][N];
int k[5];
int main(){
	FRE();
	n=rd(),m=rd()+1;
	if(n==2){
		bool flag=0;
		int id=1,Max=0;
		for(int i=1;i<=n;++i){
			k[i]=rd();
			for(int j=1;j<=k[i];++j){
				int x=rd();
				G[i][j]=x;
				a[i][x]=1;
				if(vis[x])flag=1;
				vis[x]=1;
				if(j==k[i]){
					if(i==1){
						Max=x;
					}
					else{
						if(x>Max)id=2;
					}
				}
			}
		}
		if(flag){
			if(id==2){
				swap(k[1],k[2]);
				swap(G[1],G[2]);
				swap(a[1],a[2]);
			} 
			bool mark=0;
			for(int i=a[2][k[2]];i<=a[1][k[1]];++i){
				if(!G[1][i]){
					G[1][i]=1;
					mark=1;
					break;
				}
			}
			if(!mark){
//				for(int i=m;i>=1;--i){
//					if(i==)
//				}
			}
			else{
				for(int i=m;i>=1;--i)printf("%d",G[1][i]);
			}
		}
		else{
			for(int i=m;i>=1;--i)printf("%d",vis[i]);
		}
	}
	else{
		bool flag=0;
		for(int i=1;i<=n;++i){
			int k=rd();
			for(int j=1;j<=k;++j){
				int x=rd();
				if(vis[x])flag=1;
				vis[x]=1;
			}
		}
		if(!flag){
			for(int i=m;i>=1;--i)printf("%d",vis[i]);
		}
		puts("-1");
	}
	return 0;
} 
