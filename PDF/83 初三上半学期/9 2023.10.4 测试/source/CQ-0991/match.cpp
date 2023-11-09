#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+5;
int n,m,k,q;
char s[N],t[N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&k);
	scanf("%s",(s+1));
	n=strlen(s+1);
	scanf("%d",&q);
	while(q--){
		scanf("%s",(t+1));
		m=strlen(t+1);
		int ans=0;
		if(m<=k) ans=n-m+1;
		else{
			for(int l=1;l<=n-m+1;l++){
				int r=l+m-1;
				int st=r+1,ed=l-1;
				int flag=0;
				for(int i=l;i<=r;i++){
					if(r-i<k){
						flag=1;
						break;
					}
					if(s[i]!=t[i-l+1]){
						st=i;
						break;
					}
				}
				if(flag){
					ans++;
					continue;
				}
				for(int i=r;i>=l;i--){
					if(i-st<k){
						flag=1;
						break;
					}
					if(s[i]!=t[i-l+1]){
						ed=i;
						break;
					}
				}
				if(flag){
					ans++;
					continue;
				}
				if(ed-st<k) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
