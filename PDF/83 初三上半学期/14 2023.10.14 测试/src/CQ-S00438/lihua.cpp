#include<bits/stdc++.h>
using namespace std;
int n,m,k,q,len[100001];
char s[100001][31],t[31];
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1),len[i]=strlen(s[i]+1);
	scanf("%d",&q);
	while(q--){
		scanf("%s",t+1),k=0,m=strlen(t+1);
		for(int i=1,j=0;i<=n;i++){
			k++;
			for(j=1;j<=m&&j<=len[i];j++){
				if(s[i][j]==t[j]) k++;
				else break;
			}
			if(j-1==m&&j-1==len[i]) break;
		}
		printf("%d\n",k);
	}
	return 0;
}
