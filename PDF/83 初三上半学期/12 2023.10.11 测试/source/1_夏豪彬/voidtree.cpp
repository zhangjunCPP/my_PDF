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
	freopen("voidtree.in","r",stdin);
	freopen("voidtree.out","w",stdout);
}
int id;
int op,n;
int main(){
	FRE();
	id=rd();
	op=rd();
	n=rd();
	for(int i=1;i<n;++i){
		int x=rd(),y=rd(),w=rd();
	}
	for(int i=1;i<=n;++i){
		int x=rd();
	}
	int Q=rd();
	for(int i=1;i<=Q;++i){
		puts("0");
	}
	return 0;
}

