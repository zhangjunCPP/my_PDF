#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){
x=0;/*T fl=-1;*/char c=getchar();while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int sum=0;
	int nw=1;
	int N=100000;
	for(int i=1;i<=30;i++){
		if(N>nw)sum+=nw,nw*=26;
		else sum+=N;
	}
	cout<<sum<<endl;
	return 0;
}

