#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T&x){
x=0;char c=getchar();/*T fl=1;*/while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define N 100005
#define LL long long
int n;
int main(){
	freopen("count.in","r",stdin); 
	freopen("count.out","w",stdout);
	int T;
	read(T);
	while(T--){
		read(n);
		LL cnt=0;
		for(LL a1=1;a1<=n;a1++){
			for(LL a2=1;a2<=n;a2++){
				for(LL b1=1;b1<=n;b1++){
					if(a1*a2%b1==0&&a1*a2/b1<=n){
						cnt++;
					}
				}
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}

