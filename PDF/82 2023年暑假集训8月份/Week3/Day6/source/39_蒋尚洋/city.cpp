//8:48����
//����:������С�����ĺϲ�ʹ��ĳ��col�γ���ͨ��
//��һ�°�,����һ��,n=2e5(�����ܹ�),���޿��ܸ��ŷ���?
//���仰˵Ҫ�ҵ�һ����ͨ��,ʹ�������С��col��(��Ҫ������ÿ��col) 
//����������
//�����ǲ��ǿ���������:��ÿ��col�������ڲ�����ɫ����������
//Ȼ�󲻾�������С��ͨ����
//����Ӧ���������ܵ��Ｘ���� 
//�������߾�û����...
//����˵������...
//�������ֻ�ù�ע�޳��ߵĿ�?
//��ô������... 
//��һ��colA����ȫ������B��,Ϊʲô����colA?
//��һ��colA������ȫ������B��,�Ϳ�������!
//����զ����,��д������(9:11)
//�����и�����:ֻ�ý�����ȫ������merge�������ܵõ�scc
//9:41������������ 
//�����Ǹ������ܲ���֤һ��
//��������д��sub3:��
//���Ĳ��ַ�Ӧ�úܹؼ���
//emm...
//��������һ������
//��������ȥT3(9:46)
//������(10:43)
//�ع�һ���Ǹ�����:Ӧ������Ϊ��a->b,b->c,c->a,��b����a,c����b,��a����c,��ʱ�м�϶���������
//����ж�����col�Ƿ��໥������?
//ֱ���õ��������ݽṹ
//�����ϲ���ֻ��Ҫ�ж˵���lowerbound��?
//��ô��ֻ��ҪO(nlogn)�Ϳ������������һ��dsu
//���������Ĺ�����Ҫô���ų�������������,Ҫô��֪�����Ǵ�ѡ�� 
//ʱ��ȫ�����������Լ��������û���Լ����������ʲô��
//����Ż����?
//����������ø��ŷ��ΰ�/jk
//���ڸ��ű��������������� 
//С�ڵ���?С�ڵ��������Ҫ�ĵ���?
//�ò��鼯ά��������Ӧ����ʲô? 
//���԰��ò��鼯ά��������Ӧ����ʲô���Ƕ�������!!!!
//��!д!
//����ֱ���ų��Ǵ��
//��������������ζ�����һ����¼vis�ķ�ʽ
//��ô��Ӧ��...�ǶԵ�?
//������,��Ҫ�������Լ���ȫ�����İ�
//emm...�����Ǻܺ���
//�ֻص����ŷ���?
//����Ӵ�С�žͿ�����?
//��һ�԰�,��һ��
//�������໥�������鷳��(11:23)
//���ʱ��û��д
//����д��!
//������Ҳ���ⲻ�˷��ʱ���ȫ�����İ�...
//ŶŶŶ,����Ҫ�໥������,����r��Զ����merge!( 1 1 : 3 8 )
//����Ҳ���԰�....
//ŶŶŶ,����һ���������Ҷ˵�Ȼ����м���?(  1  1  :  4  8) 
//emm...��ʵҲ�ò��ϱ��� 
//�G���ǲ���,Ӧ�������޸��߶��� 
//����Ҳ����,����only 10min!!!!
//�G֮ǰ�ĺ����ǶԵ� 
#include<bits/stdc++.h>
using namespace std;
int n,k,col[200010];
vector<int>G[200010];
namespace task12{
	int sum[1010],in[1010],out[1010],tot;
	int bein[1010][1010],fa[1010],gd[1010],sz[1010];//i�Ƿ���j��
	int fr(int x){return x==fa[x]?x:fa[x]=fr(fa[x]);}
	void dfs_dfn(int u,int fa){
		in[u]=++tot;
		for(int v:G[u])if(v!=fa)dfs_dfn(v,u);
		out[u]=tot;
	}
	void make_bein(int curcol){
		for(int i=1;i<=n;i++)
		sum[in[i]]=col[i]==curcol;
		for(int i=1;i<=n;i++)
		sum[i]+=sum[i-1];
		for(int i=1;i<=n;i++){
			int cnt=sum[n]-(sum[out[i]]-sum[in[i]-1])>0;
			for(int v:G[i])if(in[v]>in[i])cnt+=sum[out[v]]-sum[in[v]-1]>0;
			if(col[i]!=curcol&&cnt>1)bein[col[i]][curcol]=1;
		}
	}
	void solve(){
		dfs_dfn(1,0);
		for(int i=1;i<=k;i++)make_bein(i),gd[i]=1,fa[i]=i,sz[i]=1;
		for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
		if(bein[i][j]&&bein[j][i]){
			int a=fr(i),b=fr(j);
			if(a!=b)sz[a]+=sz[b],fa[b]=a;
		}
		for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
		if(bein[i][j]&&fr(i)!=fr(j))gd[fr(j)]=0;
		int ans=1e9;
		for(int i=1;i<=k;i++)if(fa[i]==i&&gd[i])ans=min(ans,sz[i]-1);
		cout<<ans;
	}
}
//namespace solveitbyluck{
//	struct dsu_t{
//		int fa[200010];
//		int fr(int x){return fa[x]?fa[x]=fr(fa[x]):x;}
//		void merge(int x,int y){
//			if((x=fr(x))!=(y=fr(y)))
//			fa[x]=y;
//		}
//	}jp,blk;
//	vector<int>node[200010];
//	int treefa[200010],vis[200010],ans=1e9;
//	void del(int c){
//		for(int x:node[c])
//		jp.merge(x,treefa[x]);
//	}
//	void dfs(int u){for(int v:G[u])if(v!=treefa[u])treefa[v]=u,dfs(v);} 
//	void trylink(int u){
//		queue<int>q;
//		
//	}
//	void solve(){
//		treefa[1]=n+1,dfs(1);
//		for(int i=1;i<=n;i++)
//		node[col[i]].push_back(i);
//		
//	}
//}
//namespace task3{
//	using pii=pair<int,int>;
//	vector<int>pos[200010];
//	pii mi[200010<<2],mx[200010<<2];int N;
//	void upd(int p,pii x){for(p+=N,mi[p]=mx[p]=x;p>>=1;mx[p]=max(mx[p<<1],mx[p<<1|1]),mi[p]=min(mi[p<<1],mi[p<<1|1]));}
//	pii querymx(int l,int r){
//		pii ret{};
//		for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1){
//			if(~l&1)ret=max(ret,mx[l^1]);
//			if(r&1)ret=max(ret,mx[r^1]);
//		}return ret;
//	}
//	pii querymi(int l,int r){
//		pii ret{};
//		for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1){
//			if(~l&1)ret=min(ret,mi[l^1]);
//			if(r&1)ret=min(ret,mi[r^1]);
//		}return ret;
//	}
//	void putto(){
//		vector<int>tmp(n+5);
//		for(int i=1;i<=n;i++)
//		if(G[i].size()==1){
//			for(int u=i,las=0,p=1;u;u=G[u][0]^G[u][1]^las,p++)tmp[p]=col[u];
//			break;
//		}copy_n(begin(tmp)+1,n,col+1);
//	}
//	int vis[200010],fa[200010],sz[200010],mxr[200010],mil[200010];
//	int fr(int x){return fa[x]?fa[x]=fr(fa[x]):x;}
//	void merge(int x,int y){
//		if((x=fr(x))!=(y=fr(y)))
//		fa[y]=x,sz[x]+=sz[y];
//	}
//	struct node_t{int l,r,id;};
//	void solve(){
//		fill_n(mi+1,mi+n*4+1,pii{1e9,0});
//		putto();
//		for(int i=1;i<=n;i++)pos[col[i]].push_back(i);
//		for(int i=1;i<=k;i++)sz[i]=1;
//		vector<node_t>qwq;
//		for(int i=1;i<=k;i++)upd(pos[newl]);
//		for(int i=1;i<=k;i++)
//		if(!pos[i].empty())qwq.push_back({pos[i].front(),pos[i].back(),i});
//		sort(begin(qwq),end(qwq),[](const node_t&x,const node_t&y){return x.l<y.l;});
//		for(auto x:qwq)if(!vis[x.id]){
//			int newl=querymi(x.l,x.r).second;
//			if(!newl||pos[newl])mil[x.id]=;
//		}
//	}
//}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++)
	scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);
	for(int i=1;i<=n;i++)scanf("%d",&col[i]);
	if(n<=1000){task12::solve();return 0;}
	return 0;
}
