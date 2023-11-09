#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	char c=getchar();
	bool f=0;
	while(c<'0' || c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}
const int maxn=1e5*30;
int tot=0;
vector< vector<int> > v;
vector<int> e;
vector<map<char,int> > trie;
int n;
char s[30];
inline void Insert(int id){
	int u=0;
	int len=strlen(s+1);
	for(int i=1;i<=len;i++){
		v[u].push_back(id);
		if(trie[u].find(s[i])==trie[u].end()){
			v.push_back({});
			trie.push_back({});
			e.push_back(-1);
			++tot;
			trie[u][s[i]]=tot;
		}
		u=trie[u][s[i]];
	}
	v[u].push_back(id);
	if(e[u]==-1) e[u]=id;
}
inline int find(){
	int u=0;
	int len=strlen(s+1);
	for(int i=1;i<=len;i++){
		if(trie[u].find(s[i])==trie[u].end()) return n+1;
		u=trie[u][s[i]];
	}
	if(e[u]==-1) return n+1;
	return e[u];
}
inline int ask(){
	int lmit=find();
	int len=strlen(s+1);
	int ans=0,u=0;
	for(int i=1;i<=len;i++){
//		cout<<s[i]<<" "; 
		if(lmit==n+1) ans+=(int)v[u].size();
		else ans+=lower_bound(v[u].begin(),v[u].end(),lmit)-v[u].begin()+1;
//		cout<<ans<<endl;
		if(trie[u].find(s[i])==trie[u].end()) return ans;
		u=trie[u][s[i]];
	}
	if(lmit==n+1) ans+=(int)v[u].size();
	else ans+=lower_bound(v[u].begin(),v[u].end(),lmit)-v[u].begin()+1;
	return ans; 
} 
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	v.push_back({});
	e.push_back(-1);
	trie.push_back({});
	read(n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		Insert(i);
	}
	int q;
	read(q);
	while(q--){
		scanf("%s",s+1);
		write(ask()),putchar('\n');
	} 
	return 0;
}
/*
T1挂了，这应该是后三题中最能做的题目了吧。
先考虑原串中不含这个串。 
相当于所有lcp之和加n。
如果出现就找到第一个出现的位置，然后相当于1个前缀的lcp之和。
前缀用AC自动机维护吧。
第一种情况。
我直接将trie树上的每个点++
打上标记。
然后我沿着路走，把标记加上就行了。
第二种情况不是很好处理。
也就是标记走到底可能会发现被包含。
不，也很简单。 
我用一个 vector 我每次走的时候二分查找一下标记就行了。 
居然比T1简单？ 
靠，只给了 32 MB
为什么这都卡。 
我不能直接把图存下来，没事，用个map。 
在这个时刻懂了密码的意思。
那还不是很好搞。
因为要 33mb
直接开，有些用不到，用vector开？ 
万一 vector 给我翻了个倍什么还是G了。
真的纠结 
他大概率拉不满，直接用 vector ，我本来就大了一个 MB 
*/ 
