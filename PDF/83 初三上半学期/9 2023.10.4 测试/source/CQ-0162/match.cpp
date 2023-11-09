#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,k,q,len,ans;
char s[N],p[N];
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%s%d",&k,s+1,&q);
	n=strlen(s+1);
	for(int i=1;i<=q;i++){
		scanf("%s",p+1);
		len=strlen(p+1);
		ans=0;
		for(int j=1;j<=n-len+1;j++){
			int l=0,r=0;
			for(int k=1;k<=len;k++){
				if(s[j+k-1]!=p[k]){
					if(!l)l=k;
					r=k;
				}
			}
			if(r-l<k)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
2
baccbcbabc
7
a
abc
aaa
bbb
abbb
acbbc
iamasuperlongstring
*/
