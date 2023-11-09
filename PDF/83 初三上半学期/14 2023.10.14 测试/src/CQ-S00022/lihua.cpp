#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int Maxn=1e5+5;
char s[Maxn][32];int lens[Maxn];
char t[Maxn][32];int lent[Maxn];
namespace sol1{
	using ull=unsigned long long;
	const int Maxm=3e4+5;
	const ull Pri=1789;
	ull P[32]={1};
	ull H[Maxm][32];
	ull T[32];
	int match(int i,int j){
		int l=0,r=min(lent[i],lens[j]);
		int res=0;
		while(l<=r){
			int mid=l+r>>1;
			if(T[mid]==H[j][mid])res=mid,l=mid+1;
			else r=mid-1;
		}
		return res+1;
	}
	void solve(int n,int q){
		for(int i=1;i<=30;++i)P[i]=P[i-1]*Pri;
		for(int i=1;i<=n;++i){
			lens[i]=strlen(s[i]+1);
			for(int j=1;j<=lens[i];++j)H[i][j]=H[i][j-1]*Pri+s[i][j];
		}
		for(int i=1;i<=q;++i){
			lent[i]=strlen(t[i]+1);
			for(int j=1;j<=lent[i];++j)T[j]=T[j-1]*Pri+t[i][j];
			int ans=0;
			for(int j=1;j<=n;++j){
				int res=match(i,j);ans+=res;
				if(lent[i]==lens[j]&&res==lent[i]+1)break; 
			}
			cout<<ans<<'\n';
		}
	}
}
namespace sol2{
	int cnt[28][32];
	int ans[28][32];
	void solve(int n,int q){
		for(int i=1;i<=n;++i){
			int x=s[i][1]-'a';lens[i]=strlen(s[i]+1);
			++cnt[x][lens[i]];
			if(ans[x][lens[i]])continue;
			for(int j=1      ;j<lens[i];++j)ans[x][lens[i]]+=cnt[x][j]*j;
			for(int j=lens[i];j<=30    ;++j)ans[x][lens[i]]+=cnt[x][j]*lens[i];
			ans[x][lens[i]]+=i;
		}
		for(int i=1;i<=q;++i){
			int x=t[i][1]-'a';lent[i]=strlen(t[i]+1);
			if(ans[x][lent[i]])cout<<ans[x][lent[i]]<<'\n';
			for(int j=1      ;j<lent[i];++j)ans[x][lent[i]]+=cnt[x][j]*j;
			for(int j=lent[i];j<=30    ;++j)ans[x][lent[i]]+=cnt[x][j]*lent[i];
			ans[x][lent[i]]+=n;
			cout<<ans[x][lent[i]]<<'\n';
		}
	}
}
int main(){
//	freopen("ex_lihua/ex_lihua2.in","r",stdin);
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n;cin>>n;
	for(int i=1;i<=n;++i)cin>>(s[i]+1);
	int q;cin>>q;
	for(int i=1;i<=q;++i)cin>>(t[i]+1);
	if(n<=3e4&&q<=3e4)sol1::solve(n,q);
	else sol2::solve(n,q);
	return 0;
}
