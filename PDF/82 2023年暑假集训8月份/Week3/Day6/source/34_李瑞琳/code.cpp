#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
int a,b;
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	a=read(),b=read();
	if(a*b<=200000){
		int len=a*b-1;
		for(int i=1;i<=len;++i)printf("0");
	}else{
		int len=a*b-1;
		for(int xs=1;xs<=100000;++xs){
			if(!((len-xs+1)%xs)&&((len-xs+1)/xs<=100000)){
				int x=(len-xs+1)/xs;
//				cout<<xs<<" "<<x<<" "<<xs-1<<endl;
				for(int i=1;i<=x;++i)printf("1");
				for(int i=1;i<xs;++i)printf("0");
				return 0;
			}
		}	
	}
	return 0;
}
