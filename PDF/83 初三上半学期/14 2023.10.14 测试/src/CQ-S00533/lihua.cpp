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
		k=-k;
		putchar('-');
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
其实就是查询t,和S的所有字符串的公共前缀长度和+n 
感觉可以直接用SA?
第1个捆绑直接暴力就行 
有一个很明显的思路 
*/
int n,q,len[100005],sum[55][100005];
char a[100005][35],b[35];
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
		len[i]=strlen(a[i]+1);
	}
	q=read();
	while(q--){
		int ans=0,len1=0;
		scanf("%s",b+1);
		len1=strlen(b+1);
		for(int i=1;i<=n;i++){
			int flag=0;
			ans++;
			for(int j=1;j<=len[i]&&j<=len1;j++){
				if(a[i][j]!=b[j]){
					flag=1;
					break;
				}
				ans++;
			}
			if(!flag&&len[i]==len1)
				break;
		}
		work(ans);
		putchar('\n');
	}
	return 0;
}
