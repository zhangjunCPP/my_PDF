#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int s=0,w=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
    return s*w;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
inline void FRE(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
}
int T;
int main(){
	FRE();
	T=read();
	while(T--){
		int k=read();
		int x,y;
		for(int i=1;i<=k;++i){
			x=read(),y=read();
		}
		printf("%d\n",x);
	} 
	return 0;
}

