#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int k,q,n,m;
char s[N],t[N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&k);
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&q);
	while(q--){
		scanf("%s",t+1);
		m=strlen(t+1);
		if(m<k){
			printf("%d\n",n-m+1);
			continue;
		}
		int ans=0;
		for(int l=1,r=m;r<=n;l++,r++){
			int L=0,R=0;
			for(int i=l;i<=r;i++){
				if(s[i]!=t[i-l+1]){
					L=i;
					break;
				}
			}
			for(int i=r;i>=l;i--){
				if(s[i]!=t[i-l+1]){
					R=i;
					break;
				}
			}
			if(R-L<k)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

