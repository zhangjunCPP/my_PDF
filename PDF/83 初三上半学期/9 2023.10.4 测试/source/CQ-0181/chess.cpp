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
const int N=2e3+5;
bitset<N> vis[N];
int a[N][N];
int cnt,ss; 
int n,p,k;
inline int qpow(int a,int b){
	int sum=1;
	while(b){
		if(b&1)sum=sum*a;
		b>>=1;
		a=a*a;
	}
	return sum;
}
inline void FRE(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
}
int main(){
	FRE();
	p=rd(),k=rd();
	n=qpow(p,k);
	for(int i=1;i<n;++i){
		for(int j=i+1;j<n;++j){
			vis[i][j]=1;
		} 
	}
	cnt=0,ss=0;
	while(1){
		int sum=1;
		++ss;
		a[ss][1]=0;
		while(sum<p){
			a[ss][++sum]=++cnt;
		}
		if(cnt==n-1)break; 
	}
	for(int i=1;i<=ss;++i){
		for(int j=2;j<=p;++j){
			for(int z=1;z<=p;++z){
				if(j==z)continue;
				vis[a[i][j]][a[i][z]]=0;
			}
		}
	}
	for(int i=1;i<n;++i){
		bool fl=0;
		while(1){
			bitset<N> ff=vis[i];
			int sum=1;
			a[++ss][1]=i;
			while(sum<p){
				int xx=ff._Find_first();
				if(xx>=n){
					fl=1;
					break; 
				}
				a[ss][++sum]=xx;
				ff&=vis[xx];
			}
			if(fl){
				--ss;
				break;
			}
			for(int j=1;j<=p;++j){
				for(int z=1;z<=p;++z){
					if(j==z)continue;
					vis[a[ss][j]][a[ss][z]]=0;
				}
			}
		}
	}
	printf("%d\n",ss);
	for(int i=1;i<=ss;++i){
		for(int j=1;j<=p;++j){
			printf("%d ",a[i][j]);
		}
		puts("");
	}
} 
/*
2 2
*/
