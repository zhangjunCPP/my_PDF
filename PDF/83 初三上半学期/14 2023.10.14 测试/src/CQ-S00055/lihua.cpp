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
T1���ˣ���Ӧ���Ǻ�����������������Ŀ�˰ɡ�
�ȿ���ԭ���в���������� 
�൱������lcp֮�ͼ�n��
������־��ҵ���һ�����ֵ�λ�ã�Ȼ���൱��1��ǰ׺��lcp֮�͡�
ǰ׺��AC�Զ���ά���ɡ�
��һ�������
��ֱ�ӽ�trie���ϵ�ÿ����++
���ϱ�ǡ�
Ȼ��������·�ߣ��ѱ�Ǽ��Ͼ����ˡ�
�ڶ���������Ǻܺô���
Ҳ���Ǳ���ߵ��׿��ܻᷢ�ֱ�������
����Ҳ�ܼ򵥡� 
����һ�� vector ��ÿ���ߵ�ʱ����ֲ���һ�±�Ǿ����ˡ� 
��Ȼ��T1�򵥣� 
����ֻ���� 32 MB
Ϊʲô�ⶼ���� 
�Ҳ���ֱ�Ӱ�ͼ��������û�£��ø�map�� 
�����ʱ�̶����������˼��
�ǻ����Ǻܺø㡣
��ΪҪ 33mb
ֱ�ӿ�����Щ�ò�������vector���� 
��һ vector ���ҷ��˸���ʲô����G�ˡ�
��ľ��� 
���������������ֱ���� vector ���ұ����ʹ���һ�� MB 
*/ 
