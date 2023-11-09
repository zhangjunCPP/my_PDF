#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int s=0,w=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
    return s*w;
}
inline void fre(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
} 
int a,b;
int main(){
	fre();
	a=read(),b=read(); 
	if(a*b-1<=2e5){                          
		for(int i=1;i<=a*b-1;++i)printf("0");
		return 0;
	}
	if(a*b-1<=3e5){
		int len=a*b/2;
		if(a*b%2==0){
			for(int i=1;i<len;++i)printf("0");
			printf("1"); 
			return 0;
		}
		else{
			int len=(a*b-3)/2;
			for(int i=1;i<=len-2;++i)printf("0");
			printf("10");
			return 0;
		}
	}
	return 0;
}

