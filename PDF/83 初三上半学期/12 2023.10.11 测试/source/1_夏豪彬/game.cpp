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
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
}
int T,n,m,k;
char a[100005];
int main(){
	FRE();
	T=rd();
	while(T--){
		n=rd(),m=rd(),k=rd();
		for(int i=1;i<=k;++i){
			cin>>a[i];
		}
		for(int i=1;i<=m;++i){
			int x=rd(),y=rd();
		}
		int need=m-n+2;
		if(need<=0){
			printf("%c\n",a[1]);
			continue;
		}
		int who=(need-1)%k+1;
		printf("%c\n",a[who]=='G'?'P':'G');
	}
	return 0;
}
/*
3
5 4 1
G
1 2
1 3
2 4
1 5
4 6 1
G
1 2
2 3
1 4
3 1
2 4
3 4
4 4 1
P
1 2
2 3
2 4
1 3

*/

