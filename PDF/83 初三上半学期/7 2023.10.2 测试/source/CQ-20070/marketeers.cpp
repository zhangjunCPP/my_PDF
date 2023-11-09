#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=5e5+10;
const int mod=998244353;
int n,k[N],num[N],ans;
vector<int> s[N],ch,cho;
void dfs(int now){
	if(now>n){
		for(int i=0;i<n;++i){
			int nnum=0;
			for(int j=i+1;j<n;++j)
				if(ch[i]>ch[j])++nnum;
			if(nnum!=num[i])return;
		}
		ans=(ans+1)%mod;return;
	}
	for(int i=0;i<k[now];++i)ch.push_back(s[now][i]),dfs(now+1),ch.pop_back();
}
int main(){
	freopen("marketeers.in","r",stdin);
	freopen("marketeers.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		k[i]=read();
		for(int j=1;j<=k[i];++j){
			int x=read();
			s[i].push_back(x);
		}
		sort(s[i].begin(),s[i].end());
	}
	int last=2e9,flag=0;
	for(int i=1;i<=n;++i){
		flag=0;
		for(int j=k[i]-1;~j;--j){
			if(s[i][j]<last){cho.push_back(s[i][j]),last=s[i][j],flag=1;break;}
		}
		if(!flag)cho.push_back(s[i][0]),last=s[i][0];
	}
//	for(int i=0;i<n;++i)cout<<cho[i]<<" ";
//	cout<<"\n";
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(cho[i]>cho[j])++num[i];
//	for(int i=0;i<n;++i)cout<<num[i]<<" ";
//	cout<<"\n";
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
/*
4
2
2 1
3
5 1 6
1
3
3
6 5 7
*/
