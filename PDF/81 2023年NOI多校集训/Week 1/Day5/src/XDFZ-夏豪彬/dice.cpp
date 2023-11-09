#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void FRE(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
}
const int maxn=1e6;
int n,k;
int a[101][7];
int main(){
	FRE();
	n=read(),k=read();
	if(n==1){
		for(int i=1;i<=6;++i){
			a[1][i]=(i-1)*k;
			if(a[1][1]>maxn){
				puts("No");
				exit(0);
			}
		}
		puts("Yes");
		for(int i=1;i<=6;++i)printf("%d ",a[1][i]);
		exit(0);
	}
	else if(k==2){
		puts("Yes");
		for(int i=1;i<=n;++i){
			for(int j=1;j<=6;++j){
				printf("%d ",2*(j-1));
			}
			puts("");
		}
	}
	else{
		puts("No");
	}
}
