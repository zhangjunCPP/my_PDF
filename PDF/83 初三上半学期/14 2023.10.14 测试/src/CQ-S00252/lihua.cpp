#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e5+10;
int n,q,trie[N][30],tot=1,word[N];
char s[N][30],t[30];
map<string,int> mp;
void insert(char w[],int len){
	int p=1;
	for(int i=1;i<=len;++i){
		int c=w[i]-'a';
		if(!trie[p][c])trie[p][c]=++tot;
		p=trie[p][c],++word[p];
	}
}
int query(char w[],int len){
	int p=1,res=0,r1,r2;
	for(int i=1;i<=len;++i){
		int c=w[i]-'a';
		if(!trie[p][c]){r2=word[p];break;}
		if(p==1)r1=word[trie[p][c]];
		p=trie[p][c],res+=word[p];
	}
	return res+n;
}
void solve(){
	int res=0;
	for(int i=1;i<=n;++i){
		int l=strlen(s[i]+1),l2=strlen(t+1),flag=1;
		for(int j=1;j<=min(l,l2);++j){
			++res;
			if(t[j]!=s[i][j]){flag=0;break;}
		}
		++res;
		if(flag&&l==l2)break;
	}
	printf("%d\n",res);
}
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1),insert(s[i],strlen(s[i]+1)),mp[s[i]+1]=1;
	q=read();
	while(q--){
		scanf("%s",t+1);
		if(!mp[t+1])printf("%d\n",query(t,strlen(t+1)));
		else solve();
	}
	return 0;
}
