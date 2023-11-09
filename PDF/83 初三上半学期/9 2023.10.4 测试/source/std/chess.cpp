#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e3+10;
int n,p,k,pw[N];
int stk[30],tp;
void write(int x){
	do stk[++tp]=x%10,x/=10;while(x);
	while(tp)putchar(stk[tp--]^48);
}
void solve(int l,int r,int len){
	For(i,l,l+len-1){
		For(d,0,len-1){
			For(j,0,p-1)write(l+j*len+(i-l+d*j)%len),putchar(' ');puts("");
		}
	}
	if(len>1)For(i,0,p-1)solve(l+i*len,l+(i+1)*len-1,len/p);
}
signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	p=read(),k=read(),pw[0]=1;For(i,1,k)pw[i]=pw[i-1]*p;
	n=pw[k];int ans=(n*(n-1)/2)/(p*(p-1)/2);
	cout<<ans<<endl;solve(0,n-1,pw[k-1]);
	return 0;
}
