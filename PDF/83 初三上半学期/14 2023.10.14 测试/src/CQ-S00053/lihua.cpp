#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,len[N],m,ans;
char s[N][35],t[35];
bool check(int id){
	for(int i=1;i<=min(m,len[id]);++i){
		++ans;
		if(s[id][i]!=t[i]) return false;
	}
	++ans;
	return m==len[id];
}
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%s",s[i]+1),len[i]=strlen(s[i]+1);
	int q; scanf("%d",&q);
	while(q--){
		scanf("%s",t+1),m=strlen(t+1),ans=0;
		for(int i=1;i<=n;++i) if(check(i)) break;
		printf("%d\n",ans);
	}
	
	return 0;
}
