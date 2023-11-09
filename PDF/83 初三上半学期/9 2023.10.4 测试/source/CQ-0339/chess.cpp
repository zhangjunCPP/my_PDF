/*
满足条件=任意两组集合最多只有一个数相同 
k=1 也就是直接输出 0~p-1
p=2 {a,b} => a<b =>a \in 1~n-1 , b \in a+1~n l=(p^k)*(p^k)/2
其它的gun,Cnmmp,先跳 
经过爆枚举，k=2 时存在明显规律，好~ 
l=(p+1)+p*(p-1)+(p-1)

人类智慧再次闪光）70pts ,这次真跑了 
*/

#include<bits/stdc++.h>
using namespace std;
int out[1<<10],buf;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
}
inline void write(int x,bool f){
	if (x<0){ putchar('-'); x=-x; }
	if (x==0) out[buf++]=0;
	while (x) out[buf++]=x%10,x/=10;
	while (buf--) putchar(out[buf]+'0');
	f ? putchar('\n'):putchar(' '),buf=0;
} 
int p,k;
int kkk(int a,int b){
	int res=1;
	for (;b;b>>=1,a=a*a)
		if (b&1) res=res*a;
	return res;
}
void sol1(){
	write(1,1);
	for (int i=0;i<p;i++)
		write(i,0);
}
void sol2(){
	int n=kkk(p,k);
	write(n*(n-1)/2,1);
	for (int i=1;i<n;i++)
	for (int j=i+1;j<=n;j++)
		write(i-1,0),write(j-1,1);
}
void sol3(){
	int l=(p+1)+p*(p-1)+(p-1);
	int n=kkk(p,k)-1;
	write(l,1);
	for (int i=1;i<=n;i+=(p-1)){
		write(0,0);
		for (int j=0;j<p-1;j++)
			write(i+j,0);
		putchar('\n');
	} int off=p;
	for (int o=1;o<=p-1;o++){
		write(o,0);
		int tot=p,pot=tot;
		write(tot,0);
		for (int i=2;i<=p-1;i++){
			tot+=off;
			while (tot>n) tot-=p*(p-1);
			write(tot,0);
		} putchar('\n'); pot+=p-1;
		for (int tt=2;tt<=p;tt++){
			write(o,0);
			tot=pot;
			write(tot,0);
			for (int i=2;i<=p-1;i++){
				tot+=off;
				while (tot>n) tot-=p*(p-1);
				write(tot,0);
			} putchar('\n');
			pot+=p-1;
		} off+=p-1;
	} int roro=1+2*(p-1);
	for (int i=1;i<=p-1;i++,roro++){
		int tk=roro;
		write(p,0);
		write(tk,0);
		for (int j=2;j<=p-1;j++)
			tk+=p-1,write(tk,0);
		putchar('\n');
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	p=read(),k=read();
	if (k==1){ sol1(); return 0; }
	if (p==2){ sol2(); return 0; }
	if (k==2){ sol3(); return 0; }
	puts("I love Hutao very much");
	return 0;
} 
/*
TheProblem'sNotEasy
*/
