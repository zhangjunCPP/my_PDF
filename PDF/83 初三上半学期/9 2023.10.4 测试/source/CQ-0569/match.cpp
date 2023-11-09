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
/*
盲猜AC自动机或者KMP
暴力比较好 
*/
int k,q,n;
char s[200005],t[200005];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	k=read();
	scanf("%s",s+1);
	n=strlen(s+1);
	q=read();
	while(q--){
		scanf("%s",t+1);
		int len=strlen(t+1),ans=0;
		for(int i=1;i+len-1<=n;i++){
			int f=0,fir=0;
			for(int j=i;j<=i+len-1;j++){
				if(s[j]!=t[j-i+1]){
					if(!fir)
						fir=j;
					else{
						if(j-fir>=k){
							f=1;
							break;
						}
					}
				}
			}
			ans+=(!f);
		}
		work(ans);
		putchar('\n');
	}
	return 0;
}
