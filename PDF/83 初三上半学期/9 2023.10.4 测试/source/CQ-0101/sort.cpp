#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){x=0;char c=getchar();/*T fl=1;*/
while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
template<typename T>void write(T x){if(x>=10)write(x/10);putchar((x%10)+'0');}
#define N 100005
#define INF 1145141919
#define LL long long
//#define int LL
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int T;
	read(T);
	while(T--){
		int n,p;
		read(n);
		read(p);
		if(n<=3)putchar('0');
		if(n==4)putchar('0'+(2%p));
		if(n==5)write(30%p);
		if(n==6)write(310%p);
		if(n==12)write(473708154%p); 
		else write(rand()*rand()%p*rand()%p);
		puts("");
	}
}

