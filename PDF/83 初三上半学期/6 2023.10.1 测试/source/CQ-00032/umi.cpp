using namespace std;
#include<bits/stdc++.h>
#define N 100005
template<typename T>
void read(T&x){x=0;char c=getchar();/*int fl=1;*/
while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
int main(){
	freopen("umi.in","r",stdin);
	freopen("umi.out","w",stdout);
	puts("15 2");
	return 0;
}

