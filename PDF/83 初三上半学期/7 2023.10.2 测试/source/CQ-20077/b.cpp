//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
typedef long long LL;
int n,a[MAXN];
LL s;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	LL s=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		s+=a[i];
		ans=max(ans,i-int(upper_bound(a+1,a+i+1,s/i)-a)+1);
	}
	printf("%d\n",ans);
	return 0;
}

