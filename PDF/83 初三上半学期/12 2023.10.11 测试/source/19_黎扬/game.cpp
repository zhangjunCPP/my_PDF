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
int t,n,m,k;
char a[100005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		m=read();
		k=read();
		scanf("%s",a+1);
		for(int i=1,x,y;i<=m;i++){
			x=read();
			y=read();
		}
		puts((a[(m-(n-1)+1)%k?(m-(n-1)+1)%k:k]=='G')?"P":"G");
	}
	return 0;
}
