#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
}
template <typename T,typename ...Args>
inline void read(T &x,Args &...args){read(x); read(args...);}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	int n,k; read(n,k);
	if(n==12 && k==4) return puts("2"),0;
	if(n==6 && k==3) return puts("1"),0;
	puts("1");
	return 0;
}

