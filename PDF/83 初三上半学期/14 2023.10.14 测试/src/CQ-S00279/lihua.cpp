#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+2,M=32;
unordered_map<ll,ll>mp;
ll n,q,m[N],h1[N][M],h2[N][M],H1[M],H2[M],S[N],res[N],trie[N][30],tot,ed[N];
char s[N][M],t[N][M];
void Hash(char s[]){
	ll m=strlen(s+1);
	for(ll i=1;i<=m;i++){
		H1[i]=(H1[i-1]*29+(s[i]-'a'));
		H2[i]=(H2[i-1]*29+(s[i]-'a'));
	}
}
void insert(char ch[N]){
	int m=strlen(ch+1),p=0;
	for(int i=1;i<=m;i++){
		int c=ch[i]-'a';
		if(!trie[p][c]){
			trie[p][c]=++tot;
		}
		p=trie[p][c];
		ed[p]++;
	}
	ed[p]++;
}
int query(char ch[N]){
	int m=strlen(ch+1),p=0,res=0;
	for(int i=1;i<=m;i++){
		int c=ch[i]-'a';
		if(!trie[p][c])break;
		p=trie[p][c];
		res+=ed[p];
	}
	return res;
}
int main(){//30
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	scanf("%lld",&n);
	bool A=1;
	for(ll i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		m[i]=strlen(s[i]+1);
		for(ll j=1;j<=m[i];j++){
			h1[i][j]=(h1[i][j-1]*29+(s[i][j]-'a'));
			h2[i][j]=(h2[i][j-1]*29+(s[i][j]-'a'));
		}
	}
	char C=s[1][1];
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m[i];j++){
			if(s[i][j]!=C){
				A=0;
				break;
			}
		}
	}
	scanf("%lld",&q);
	for(ll i=1;i<=q;i++){
		scanf("%s",t[i]+1);
		ll mt=strlen(t[i]+1);
		for(ll j=1;j<=mt;j++){
			if(t[i][j]!=C){
				A=0;
				break;
			}
		}
	}
	if(A){
		for(ll i=1;i<=30;i++){
			for(ll j=1;j<=n;j++){
				res[i]+=min(m[j],i)+1;
				if(m[j]==i)break;
			}	
		}
		for(ll i=1;i<=q;i++){
			ll mt=strlen(t[i]+1);
			printf("%lld\n",res[mt]);
		}
		return 0;
	}
	if(n<=10){
		for(ll i=1;i<=q;i++){
			Hash(t[i]);
			ll ans=0;
			for(ll i=1;i<=n;i++){
				bool fg=0;
				for(ll j=1;j<=m[i];j++){
					if(h1[i][j]==H1[j]&&h2[i][j]==H2[j])continue;
					fg=1;
					ans+=j;
					break;
				}
				if(!fg){
					ans+=m[i]+1;
					break;
				}
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		insert(s[i]);
	}
	for(int i=1;i<=q;i++){//pipeidaojiujieshudechulibuliao
		printf("%lld\n",query(t[i])+n);
	}
	return 0;
}

