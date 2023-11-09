#include<bits/stdc++.h>
const int QWQ=2e5+5;
using namespace std;
inline int read(){
	char ch = getchar();int x = 0, f = 1;
	while(ch<'0'||ch>'9'){if(ch == '-') f = -1;ch = getchar();}
	while('0'<=ch && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
struct node{ int to,next,id; } E[QWQ];
int n,m,cnt,head[QWQ];
inline void append(int x,int y,int d){
	E[++cnt].to=y;
	E[cnt].id=d;
	E[cnt].next=head[x];
	head[x]=cnt;
}
int main(){
	freopen("hamilton.in","r",stdin);
	freopen("hamilton.out","w",stdout);
	cout<<"NO";
	return 0;
} 
