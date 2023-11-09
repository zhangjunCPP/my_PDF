//the code is from chenjh
#include<cstdio>
#include<cstring>
#define MAXN 200005
using namespace std;
int k,n,q,m;
char s[MAXN],t[MAXN];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d %s %d",&k,s+1,&q);
	n=strlen(s+1);
	while(q--){
		scanf(" %s",t+1);
		m=strlen(t+1);
		if(m<=k){printf("%d\n",n-m+1);continue;}
		int ans=0;
		for(int i=1,mi=n-m+1,l,r;i<=mi;i++){
			r=i+m-1;
			for(l=i;l+k<=r&&s[l]==t[l-i+1];l++);
			for(;(l<r&&r-l>=k)&&s[r]==t[r-i+1];--r);
			if(r-l<k)++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}

