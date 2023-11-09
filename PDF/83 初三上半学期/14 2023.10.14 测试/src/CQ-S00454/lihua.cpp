#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mid ((l+r)>>1)
typedef unsigned long long ull;
const int N=1e5+5;
ull h[40005][31];
int len[N],n;
char s[31];
void bf() {
	for(int i=1;i<=n;i++) {
		scanf("\n%s",s+1);
		len[i]=strlen(s+1);
		for(int j=1;j<=len[i];j++)h[i][j]=h[i][j-1]*131+s[j]-'a';
	}
	int q;
	scanf("\n%d",&q);
	while(q--) {
		scanf("\n%s",s+1);
		int Len=strlen(s+1),ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=Len;j++)h[n+1][j]=h[n+1][j-1]*131+s[j]-'a';
			int l=0,r=min(Len,len[i]);
			while(l<=r) {
				if(h[i][mid]==h[n+1][mid]) l=mid+1;
				else r=mid-1;
			}
			int res=l-1;
			ans+=res+1;
//			printf("%d %d %d\n",i,res,n);
			if(res==Len&&Len==len[i]) break;
		}
		printf("%d\n",ans);
	}
}
int tong[26][N];
int tot[26],id[26][30];
void solve() {
	for(int i=1;i<=n;i++) {
		scanf("\n%s",s+1);
		int c=s[1]-'a';
		int Len=strlen(s+1);
		tong[c][Len]++;
		if(!id[c][Len]) {
			for(int j=1;j<=30;j++) id[c][Len]+=tong[c][j]*min(j,Len);
			id[c][Len]+=i;
		}
	}
	for(int c=0;c<26;c++) {
		for(int i=1;i<=30;i++) {
			if(!id[c][i]) {
				for(int j=1;j<=30;j++) id[c][i]+=tong[c][j]*min(j,i);
				id[c][i]+=n;
			}
		}
	}
	int q;
	scanf("\n%d",&q);
	while(q--) {
		scanf("%s",s+1);
		int c=s[1]-'a';
		int Len=strlen(s+1);
		printf("%d\n",id[c][Len]);
	}
}
signed main() {
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	scanf("%d",&n);
	if(n<=3e4) bf();
	else solve();
	return 0;
}
