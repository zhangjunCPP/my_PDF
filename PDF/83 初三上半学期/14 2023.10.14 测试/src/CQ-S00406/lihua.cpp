#include<bits/stdc++.h>
using namespace std;
int n,m,tot=1,ans[100010],sz[300010],fir[300010];
map<short,int>t[300010];
void work(){
	int qfir[26][35]{},qcnt[26][25]{};
	for(int i=1;i<=n;i++){
		char s[35];
		scanf("%s",s);
		int a=s[0]-'a',b=strlen(s);
		if(!qfir[a][b])qfir[a][b]=i;
		for(int x=1;x<=b;x++)ans[i]+=++qcnt[a][x];
	}for(int i=1;i<=m;i++){
		char s[35];scanf("%s",s);
		int a=s[0]-'a',b=strlen(s);
		if(!qfir[a][b]){
			int res=0;
			for(int x=1;x<=b;x++)res+=qcnt[a][x];
			printf("%d\n",res+n);
		}else printf("%d\n",ans[qfir[a][b]]+qfir[a][b]);
	}
}
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	cin>>n;
	if(n>30000)return work(),0;
	for(int i=1;i<=n;i++){
		char s[35],*p=s;
		scanf("%s",s);
		int u=1;
		for(;*p;){
			int&v=t[u][*p++-'a'];
			if(!v)v=++tot;
			u=v,ans[i]+=++sz[v];
		}if(!fir[u])fir[u]=i;
	}cin>>m;
	for(int i=1;i<=m;i++){
		char s[35],*p=s;
		scanf("%s",s);
		int u=1,x=0;
		for(;*p;){
			if(!t[u].count(*p-'a')){u=0;break;}
			u=t[u][*p++-'a'];x+=sz[u];
		}printf("%d\n",fir[u]?ans[fir[u]]+fir[u]:x+n);
	}
	return 0;
}
