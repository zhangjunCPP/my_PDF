#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=1e5+10;
char a[N];
int ans[N],nxt[N];
ull ha[N],pw[N];
ull get(int l,int r){
	return ha[r]-ha[l-1]*pw[r-l+1];
}
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",a+1);int n=strlen(a+1);
	for(int i=1;i<=n/2;i++)swap(a[i],a[n-i+1]);
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*131;
	for(int i=1;i<=n;i++)ha[i]=ha[i-1]*131+a[i];
	for(int i=2,j=0;i<=n;i++){
		while(j&&a[i]!=a[j+1])j=nxt[j];
		if(a[i]==a[j+1])j++;
		nxt[i]=j;
	}
	for(int i=4;i<=n;i++){
		int now=nxt[i],lim=(i-1)/3;
		while(now&&now>lim)now=nxt[now];
		while(now){
			if(get(1,now)==get(i-now*2+1,i-now))ans[i]++;
			now=nxt[now];
		}
	}
	for(int i=n;i;i--)printf("%d ",ans[i]);
	return 0;
}
