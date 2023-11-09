#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,K;
char s[N];
int f[N];
bitset<N> st[26],base,ans;
void prework(){
	for(int i=1;i<=n;i++)
		st[s[i]-'a'].set(i-1,1);
	return ;
}
void show(bitset<N> vc){
	for(int i=0;i<n;i++)
		cout<<vc[i];cout<<'\n';
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>K;
	cin>>s+1;
	n=strlen(s+1);
	prework();
	cin>>m;
	while(m--){
		string qs;
		cin>>qs;
		if(qs.size()<K) cout<<n<<'\n';
		else if(qs.size()>n) cout<<0<<'\n';
		else{
			ans.reset();
			for(int i=0;i+K-1<qs.size();i++){
				base.reset();
				for(int j=0;j<n;j++)
					base.set(j,1);
				for(int j=0;j<qs.size();j++)
					if((j<i||j>i+K-1)){
//						show((st[qs[j]-'a']>>j)),
						auto u=st[qs[j]-'a']>>j;
						base=(base&u);
					}
				for(int k=n-qs.size()+1;k<n;k++)
					base[k]=0;
//				show(base);
				ans|=base;
			}
			cout<<ans.count()<<'\n';
		}
	}
	return 0;
}
/*
2
baccbcbabc
7
a
abc
aaa
bbb
abbb
acbbc
iamasuperlongstring

*/
