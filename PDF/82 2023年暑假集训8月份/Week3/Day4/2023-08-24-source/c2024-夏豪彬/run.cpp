#include<bits/stdc++.h>
#define int long long
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
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
}
int p,s;
signed main(){
	FRE();
	p=read(),s=read();
	if(p%2==1)return puts("Impossible"),0;
	int dx=p/2-1,dy;
	if(s<dx)return puts("Impossible"),0;
	dx=p/4,dy=p/2-dx;
	if(dx*dy<s)return puts("Impossible"),0;
	for(int i=1;i<=p/2;++i){
		int x=i,y=p/2-x;
		swap(x,y);
		int cha=x*y-s;
		if(cha<0)continue;
		if((cha<x&&y>1&&cha!=0)||cha==0){
			for(int i=1;i<=y;++i)printf("2");
			printf("1");
			for(int i=1;i<x;++i)printf("2");
			printf("1");
			for(int i=1;i<y-1;++i)printf("2");
			if(cha==0){
				if(y>1)printf("21");
				else printf("1");
				for(int i=1;i<x;++i)printf("2"); 
			}
			else{
				printf("1");
				for(int i=1;i<cha;++i)printf("2");
				printf("31");
				for(int i=1;i<x-cha;++i)printf("2");
			}
			return 0;
		}
	}
	puts("Impossible");
	return 0;
}
