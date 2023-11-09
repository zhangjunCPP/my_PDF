#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
int n,m;
vector<int> trie[26],ed;
int la[26],lb,tot=1;
void insert(string a){
	int len=a.size();
	int p=1;
	for(int i=0;i<len;i++){
		int ch=a[i]-'a';
		if(la[ch]<=p) trie[ch].resize(p+1),la[ch]=p+1;
		if(!trie[ch][p]) trie[ch][p]=++tot;
		p=trie[ch][p];
		if(lb<=p) ed.resize(p+1),lb=p+1;
		ed[p]++;
	}
}
string s[N];
map<string,int> f;
struct Query{
	string s;
	int r,id;
	bool operator < (const Query &x) {
		return r < x.r;
	}
}q[N];
int ans[N];
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(!f[s[i]]) f[s[i]]=i;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		cin>>q[i].s;
		q[i].id=i;
		if(f.find(q[i].s)==f.end()) q[i].r=n-1;
		else q[i].r=f[q[i].s];
	}
	sort(q,q+m);
	int r=-1;
	for(int i=0;i<m;i++){
		while(r<q[i].r) insert(s[++r]);
		int len=q[i].s.size();
		int p=1,id=q[i].id;
		ans[id]=q[i].r+1;
		for(int j=0;j<len;j++){
			int ch=q[i].s[j]-'a';
			if(la[ch]<=p) trie[ch].resize(p+1),la[ch]=p+1;
			p=trie[ch][p];
			if(lb<=p) ed.resize(p+1),lb=p+1;
			ans[id]+=ed[p];
		}
	}
	for(int i=0;i<m;i++) printf("%d\n",ans[i]);
	return 0;
}
