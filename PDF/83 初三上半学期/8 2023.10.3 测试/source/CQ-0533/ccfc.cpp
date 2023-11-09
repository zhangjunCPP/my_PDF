#include<bits/stdc++.h>
#define int unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 100005
using namespace std;
int n,hs[N],mi[N],ans;
char s[N];
bool check(int l1,int r1,int l2,int r2){
	if(r1-l1!=r2-l2)return 0;
	int x=hs[r1]-hs[l1-1]*mi[r1-l1+1],y=hs[r2]-hs[l2-1]*mi[r2-l2+1];
	return x==y;
}
signed main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n<4){
		for(int i=1;i<=n;i++)printf("0 ");
		return 0;
	}
	mi[0]=1;
	for(int i=1;i<=n;i++){
		mi[i]=mi[i-1]*137;
		hs[i]=hs[i-1]*137+s[i]-'a'+1;
	}
	for(int i=1;i<=n-3;i++){
		int ans=0;
		for(int len=1;len*3<n-i+1;len++){
			if(check(i,i+len-1,i+len,i+len*2-1)&&check(i,i+len-1,n-len+1,n)){
				ans++;
			}
		}
		printf("%llu ",ans);
	}
	printf("0 0 0");
	return 0;
}

