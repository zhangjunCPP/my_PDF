#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(int k){
	if(k<0){
		k=-k;
		putchar('-');
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
const int mod=998244353;
int n,m,id,cnt,first[100005],val[100005],q;
struct q1{
	int u,w,nex;
}a[200005];
void add(int u1,int w1){
	a[++cnt]={u1,w1,first[u1]};
	first[u1]=cnt;
}
int main(){
	freopen("umi.in","r",stdin);
	freopen("umi.out","w",stdout);
	srand(time(0));
	n=read();
	m=read();
	id=read();
	for(int i=1;i<=n;i++){
		val[i]=read();
	}
	for(int i=1,x,y;i<n;i++){
		x=read();
		y=read();
		add(x,y);
		add(y,x);
	}
	q=read();
	while(q--){
		int s,t;
		s=read();
		t=read();
		work(rand());
		putchar('\n');
	}
	return 0;
}
