#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
char a[N][35],b[35];
void solve(int n,int q){
	while(q--){
		int ans=0;scanf("%s",b+1);
		int lb=strlen(b+1);
		for(int i=1;i<=n;i++){
			ans++;
			int la=strlen(a[i]+1);int flag=1;
			for(int j=1;j<=la;j++)if(a[i][j]==b[j])ans++;
			else {flag=0;break;}
			//cout<<ans<<"*\n";
			if(flag&&la==lb)break;
		}
		printf("%d\n",ans);
	}
}
int fi[30][35];
int s[30][35],c[30],sc[30][35];
void add(int ch,int len,int val){
	for(int i=len;i<=30;i+=(i&-i))s[ch][i]+=val,sc[ch][i]++;
}
pair<int,int> qu(int ch,int len){
	int ans=0,cnt=0;
	for(int i=len-1;i;i-=(i&-i))ans+=s[ch][i],cnt+=sc[ch][i];
	return make_pair(ans,cnt);
}
vector<int>t[30][35];
int ans[N];
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	scanf("%d",&q);
	if(n<=10&&q<=10){
		solve(n,q);return 0;
	}
	for(int i=1;i<=q;i++){
		scanf("%s",b+1);
		int len=strlen(b+1),ch=b[1]-'a'+1;
		t[ch][len].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int ch=a[i][1]-'a'+1,len=strlen(a[i]+1);
		if(!fi[ch][len]){
			auto X=qu(ch,len);
			int sum=X.first+i+len*(c[ch]-X.second+1);
			for(int id:t[ch][len]){
				ans[id]=sum;
			}
			fi[ch][len]=i;
		}
		add(ch,len,len);
		c[ch]++;
	}
	for(int ch=1;ch<=26;ch++)for(int len=1;len<=30;len++)if(!fi[ch][len]&&t[ch][len].size()){
		auto X=qu(ch,len);
		int sum=X.first+n+len*(c[ch]-X.second);
		for(int id:t[ch][len]){
			ans[id]=sum;
		}
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}
