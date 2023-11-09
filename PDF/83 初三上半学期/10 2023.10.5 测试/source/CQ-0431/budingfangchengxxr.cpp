#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T&x){
x=0;char c=getchar();/*T fl=1;*/while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
//template<typename T>T Gcd(T x,T y){while(y^=x^=y^=x%=x);return x;}
#define N 100005
#define LL long long
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	#define X 20
	for(int x=-X;x<=X;x++){
		for(int y=-X;y<=X;y++){
			for(int z=1;z<=X;z++){
				if(__gcd(__gcd(x,y),z)!=1)continue; 
				if(a*x+b*y==c*z){
					cout<<a<<'*'<<x<<'+'<<b<<'*'<<y<<'='<<c<<'*'<<z<<endl;
				}
			} 
		}
	} 
	return 0;
}

