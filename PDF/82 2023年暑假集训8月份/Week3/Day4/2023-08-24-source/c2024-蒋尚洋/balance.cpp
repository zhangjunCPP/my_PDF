//������:
//1.u->v������
//2.u���������� 
//3.v����������
//���ֻ���ʲôЧ��?
//����������?
//����������>v������ֱ�ӿ���
//���û��>v������������������ֱ�����
//���ǡ��һ��>v��������Ҫ����Եĵ�������ǿ�������
//��һ��x,һ��y
//1.x��y������:sz(go_forward(x,y))-sz(y)
//2.x��y����ֱϵѪ��:n-sz(x)-sz(y)
//checkһ�¾ͺ�?
//ϸ��һ��:
//�Ƚ����� 
//���ȵ����ֱ��dfs��ȥʱ���Ϳ���
//case 2������ʽ�ϲ�ʱ��ô������Сֵ
//11:09:���԰�
//A��B��B��һ����A��!
//������
//���ڿ������check?
//ʹ���߶�����������ֱϵѪ�׵�
//���������Ⱥ��ӵ�,��һ���������޿���ƥ���,�ٲ�һ���������޿�ƥ���?
//�ȹ����������Ĳ���check��������
//��������������?
//��ô���� 
#include<bits/stdc++.h>
using namespace std;
int n,sz[300010],fa[300010][25],dep[300010],ans[300010],in[300010],out[300010],tot;
vector<int>G[300010];
//auto calcs=[](int u,int son){return son==fa[u][0]?n-sz[u]:sz[son];};
//namespace pathquery{
//	int in[300010],out[300010],sum[600010],tot;
//	void dfs(int u){
//		in[u]=++tot;
//		for(int v:G[u])if(v!=fa[u][0])dfs(v);
//		out[u]=++tot;
//	}
//	auto addp=[](int p,int v){for(;p<=tot;p+=p&-p)sum[p]+=v;};
//	void add(int u,int v){addp(in[u],v),addp(out[u],-v);}
//	int qpath(int u){int ret=0;for(int p=in[u];p;p>>=1)ret+=sum[p];}
//}
//namespace subtquery{
//	int in[300010],out[300010],sum[300010],tot;
//	auto addp=[](int p,int v){for(;p<=tot;p+=p&-p)sum[p]+=v;};
//	auto askp=[](int p){int ret=0;for(;p;p-=p&-p)ret+=sum[p];return ret;};
//	void dfs(int u){
//		in[u]=++tot;
//		for(int v:G[u])if(v!=fa[u][0])dfs(v);
//		out[u]=tot;
//	}
//	auto add=[](int u,int v){addp(in[u],v);};
//	auto ask=[](int u){return ask(out[u])-ask(in[u]-1);}; 
//}
//void dfs(int u,int dad){
//	in[u]=++tot,sz[u]=1,fa[u][0]=dad;
//	dep[u]=dep[dad]+1;
//	for(int i=1;i<=20;i++)
//	fa[u][i]=fa[fa[u][i-1]][i-1];
//	for(int v:G[u])if(v!=fa)dfs(v,u),sz[u]+=sz[v];
//	sort(begin(G[u]),end(G[u]),[rt=u](int x,int y){return calcs(rt,x)>calcs(rt,y);});
//	out[u]=tot;
//}
//void solve(vector<int>node,int l,int r){
//	if(l==r||node.empty()){
//		for(int x:node)ans[x]=l;
//		return;
//	}int mid=l+r>>1;
//	vector<int>sm,bg,wtck;
//	for(int x:node)
//	if(G[x].size()>1&&calcs(x,G[x][1])>mid)bg.push_back(x);
//	else wtck.push_back(x);
//	for(int x:wtck)if(calcs(x,G[x][0])>mid){
//		if(G[x][0]==fa[x][0])subtquery::add(x);
//	}
//}
//int goup[3010][3010];
//void dfs2(int rt,int up,int u){
//	goup[u][rt]=sz[up];
//	for(int v:G[u])if(v!=fa[u][0])dfs2(rt,up,v);
//}
//int bf(int u){
//	for(int i=1;i<=n;i++)
//	if(i!=u)
//	if(in[u]<=in[i]&&out[i]<=out[u]){
//		int s=goup[i][u]-sz[i];
//		
//	}
//}
using pii=pair<int,int>;
void calcsz(int u,int fa){
	sz[u]=1;
	for(int v:G[u])if(v!=fa)
	calcsz(v,u),sz[u]+=sz[v];
}
pii dfs(int s,int u,int fa){
	int mxsz=0;pii res{(int)1e9,0};
	for(int v:G[u])if(v!=fa)res=min(dfs(s,v,u),res),mxsz=max(mxsz,sz[v]);
	return min(res,pii{max(s-sz[u],mxsz),u});
}
int calc(int u){
	pii ret{(int)2e9,0};
	calcsz(u,0);
	sort(begin(G[u]),end(G[u]),[](int x,int y){return sz[x]>sz[y];});
	for(int v:G[u]){
		auto x=dfs(sz[v],v,u);
		x.first=max(x.first,v==G[u][0]?(G[u].size()==1?0:sz[G[u][1]]):sz[G[u][0]]);
		ret=min(ret,x);
	}return ret.second;
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	cin>>n;
	bool flag1=true,flag2=true;
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u),flag1=flag1&&u==i&&v==i+1,flag2=flag2&&u==1&&v==i+1;
	if(flag2){
		for(int i=1;i<=n;i++)
		printf("%d\n",i==1?2:1);
		return 0;
	}
	for(int i=1;i<=n;i++)printf("%d\n",calc(i));
	return 0;
}
