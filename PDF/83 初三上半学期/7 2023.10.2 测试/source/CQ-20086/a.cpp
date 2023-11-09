#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
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
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
int n,m,q;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read();
	m=read();
	q=read();
	while(q--){
		work(1);
		putchar('\n');
	}
	return 0;
}
