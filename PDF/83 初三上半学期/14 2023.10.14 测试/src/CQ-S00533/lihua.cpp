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
��ʵ���ǲ�ѯt,��S�������ַ����Ĺ���ǰ׺���Ⱥ�+n 
�о�����ֱ����SA?
��1������ֱ�ӱ������� 
��һ�������Ե�˼· 
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
