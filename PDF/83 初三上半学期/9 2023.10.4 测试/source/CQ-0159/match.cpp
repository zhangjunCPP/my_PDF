#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
int k;
const int N=1e5+5;
char s[N],p[N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	k=rd();scanf("%s",s+1);int q=rd();
	int n=strlen(s+1);
	while(q--){
		scanf("%s",p+1);
		int len=strlen(p+1),cnt=0;
		for(int i=1;i+len-1<=n;i++){
			int mn=n,mx=0;
			for(int j=1;j<=len;j++)if(s[i+j-1]!=p[j])mn=min(j,mn),mx=max(mx,j);
			if(mx-mn<k)cnt++;
		}printf("%d\n",cnt);
	}
	return 0;
}

