#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=60;
const int M=2510;
int q,n,m;
bool solve(int n,int m){
	if(n==0&&m==0)return 1;
	if(n==1&&m==0)return 1;
	if(n==2&&(m==0||m==1))return 1;
	if(n==3&&(m==0||m==2||m==3))return 1;
	if(n==4&&(m==0||m==3||m==4||m==5||m==6))return 1;
	if(n==5&&(m==0||m==4||m==6||m==7||m==8||m==9||m==10))return 1;
	if(n==6&&(m==0||m==5||m==8||m==9||m==11||m==12||m==13||m==14||m==15)) return 1;
	if(n==7&&(m==0||m==6||m==10||m==11||m==12||m==14||m==15||m==17||m==18||m==19||m==20||m==21))return 1;
	return 0;
}
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	q=read();
	while(q--){
		n=read(),m=read();
		if(m==0||m==n*(n-1)/2){printf("1\n");continue;}
		if(m>n*(n-1)/2){printf("0\n");continue;}
		if(n<=7){
			if(solve(n,m))printf("1\n");
			else printf("0\n");
		}else{
			int c=n*(n-1)/2-m,sum=0,x=1,num=0,flag=1;
			while(sum<c){
				x=1;
				while(sum+x<=c)sum+=x,++x;
				--x;num+=x+1;
				if(num>n){printf("0\n");flag=0;break;}	
			}
			if(flag)printf("1\n");
		}
	}
	return 0;
}
