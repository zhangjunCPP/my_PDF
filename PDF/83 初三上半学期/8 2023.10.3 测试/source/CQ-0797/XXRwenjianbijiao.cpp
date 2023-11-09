#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){
x=0;char c=getchar();/*T fl=1;*/while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}/*x*=fl*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define N 100005
#define INF 1145141919
int main(){
	system("fc ex_segment2.ans segment.out"); 
	return 0;
}

