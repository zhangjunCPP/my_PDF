#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){
x=0;/*T fl=-1;*/char c=getchar();while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
int check(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0)return 0;
	return 1;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//int cnt=0;
//	for(int i=100000;;i++){
//		if(check(i)){
//			cout<<i<<endl;
//			if(++cnt>=2)break;
//		}
//	}
	short x=0;
	for(int i=1;i<=1000000;i++){
		cout<<x<<' ';
		if(x<0)return 0;
		x++;
	}
	return 0;
}

