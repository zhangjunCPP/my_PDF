/*
�е��ѡ�
1�����ѡ�
4��l=i=r���ǿ϶����0��
5��l=i=r�Ĳ����ǡ��� 
�ţ�����������ѡ�
��ͼ���𣬿����������ߣ�ÿ���������ܹ��׵ĵ㽨�ߡ� 
��ô����һ�������ɾ���������Լ����ɾ�����󽫶�ʧ���ٹ��ס�
�����ÿ�����ʧȥ����ֵ�������ֵ��С�ĵ�ɾ�����ټ�������ˡ� 
woc�����񲻼٣��������Ӷȣ�ÿ��ö��n��������г��ߣ�����14n��
��n�ξ��� 14n^2���ܹ�������
�ٴ�����û�������ˣ����ˡ� 
*/ 
#include<bits/stdc++.h>
#define int long long
const int N=1e5+10,M=1e5+10,inf=1e9+7;
void Freopen();
void Ftest();
int rd();
using namespace std;
int n,len,ans;
int l[N],r[N],c[N],vis[N];
int head[N],to[N],nxt[N],w[N];
int sum[N],val[N],tot[N];
void add( int u, int v, int z) {
	to[++len]=v;
	nxt[len]=head[u];
	w[len]=z;
	head[u]=len;
}
int a[N],tag[N],b[N];
int t;
void dfs( int k) {
	if (k==n+1) {
		int res=0;
		for ( int i=1; i<=n; i++) tag[i]=0;
		for ( int i=1; i<=n; i++) {
			int x=a[i];
			tag[x]=1;
			for ( int j=l[x]; j<=r[x]; j++) 
				if (!tag[j]) res+=c[x];
		}
		if (ans<res) {
			ans=res;
			for ( int i=1; i<=n; i++) b[i]=a[i];
		}
		return ;
	}
	for ( int i=1; i<=n; i++) {
		if (vis[i]) continue ;
		vis[i]=1;
		a[k]=i;
		dfs(k+1);
		vis[i]=0;
	}
}
signed main() {
	Freopen();
	n=rd();
	for ( int i=1,l,r,c; i<=n; i++) {
		l=rd(),r=rd(),c=rd();
		::l[i]=l,::r[i]=r,::c[i]=c;
		for ( int j=l; j<=r; j++) 
			if (i!=j) add(i,j,c);
		t=max(t,max(i-l,r-i));
	}
	if (!t) {
		cout<<0<<endl;
		return 0;
	}
	if (n<=10) {
		dfs(1);
		cout<<ans;	
		return 0;	
	}
	for ( int tim=1; tim<=n; tim++) {
		for ( int u=1; u<=n; u++) val[u]=sum[u]=tot[u]=0;
		for ( int u=1; u<=n; u++) {
			if (vis[u]) {
				sum[u]=-1;
				continue ;
			}
			for ( int i=head[u]; i; i=nxt[i]) {
				if (vis[to[i]]) continue ;
				sum[to[i]]+=w[i];
				val[u]+=w[i];
				tot[to[i]]++;
			} 
		}
		set<pair< int , int > >s;
		for ( int u=1; u<=n; u++) 
			if (sum[u]!=-1){
				if (!tot[u]) s.insert({(val[u]-sum[u]),u});
				else s.insert({(val[u]-sum[u])/tot[u],u});
			}
		auto it=s.end();
		it--;
		int p=it->second;
		vis[p]=1;
		ans+=val[p];
//		cout<<p<<" "<<ans<<endl;
	}
	cout<<ans;
}
void Freopen() {
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
}
void Ftest() {
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
}
int rd() {
	int x; scanf("%lld",&x);
	return x;
}
/*
5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5

25

12
1 3 861
2 4 822
1 3 286
2 4 236
5 6 335
4 9 837
3 11 469
7 12 846
9 12 258
6 12 139
7 12 932
12 12 411

18831

9
1 3 861
2 4 822
1 3 286
2 4 236
5 6 335
4 9 837
3 9 469
7 9 846
9 9 258

*/


