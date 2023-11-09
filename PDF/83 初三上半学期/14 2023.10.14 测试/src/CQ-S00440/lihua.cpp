#include<bits/stdc++.h>
#define N 1005
using namespace std;
int n,q,len[N];
char s[N][N],str[N];
signed main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		len[i]=strlen(s[i]+1);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%s",str+1);
		int l=strlen(str+1),ans=0;
		for(int j=1;j<=n;j++){
			int fg=1;
			for(int k=1;k<=len[j]&&k<=l;k++){
				ans++;
				if(str[k]!=s[j][k]){
					fg=0;
					break;
				}
			}
			if(fg){
				ans++;
				if(l==len[j])break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
5
jiarandaxiaojie
jiarenmensheidonga
jiangshuaisanjun
beimingningxiao
fenbenglixi
4
jianghua
jiaruo
beiguan
feng
*/

/*
8
majmunica
majmun
majka
malina
malinska
malo
maleni
malesnica
3
krampus
malnar
majmun
*/
