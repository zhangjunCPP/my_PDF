/*
A maze
����СP�;�����ʵ�Ƕ����棬������һ��������
�����ῼ�Ǵ�������·�߽����谭������ʵ���ǿ��Է���������ξ������谭һ������ȫһ�µ�
����ʵ��˵�����ǿ���ȷ��������ô��СP�����ⲻ��Ҫ
���������޵ģ�ֻ����ǰ������ɸ��㶼�Ѿ�ȷ���˶µķ�ʽ�͵���ľ���֮��ǰ��ľ������ܹ������ж�
�����������������
���ڵ�ǰ�� $u$������ $e_u$ �����ܹ��뿪�� $u$��ͬʱ�� $d_u$ ����������ô������Ȼ��ѡ��µ�����֮��������õ��� $d_u$ ��
������������Ӿ�����
��ʱ������Ҫ�ҵ�һ�����·������Ȼһ��Dij�ܹ��㶨
��ʱ���ھ����Ĵ��ڣ����ǲ��������·��
Ҳ����˵��������ѡ������·ban��
��ȥһ�£������Ƿ��ܹ�ȥ���ÿ�����ӳ��Թ������ʱ���أ�
��ʵ�����ǿ��Եİɣ�˼��һ�£��������п����ӳ�ȥ�ĵ����Ϊ $0$����ʱʹ��Dij����Ѱ������Ŀ���չ��
���԰������������ǿ������û�о���������£����нڵ�����Ž��أ�
�ǣ���һ�����Ǿ���
������ban����̵ļ���
��ô������Ҫ�����Ƕ�̬ά���ⶫ������Ȼ�ռ����
��...���ô��
׼ȷ��˵ÿһ����ֻ�����������㣬����ʵ��ζ������һ���ߴ����Ŀռ�����ֻ�� $2$��
����ʵ��ζ��������ȫ�������洢���������
��Ȼ�о�©���ܶ࣬��ò��ȷʵ������
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
struct edge{
	int v,w,nex;
}e[N*2];
int fir[N],ent;
inline void add(int u,int v,int w)
{
	e[++ent]={v,w,fir[u]};
	fir[u]=ent;
	return;
}
int s[N],d[N];
bool fns[N];
multiset<int>way[N];
multiset<int>::iterator dis[N];
priority_queue<pair<int,int>>q;
inline void Relax(int i)//�Ե�i���ɳڲ���
{
	dis[i]=way[i].begin();
	for(int j=0;j<d[i];j++)dis[i]++;
	q.push(make_pair(-*dis[i],i));
	return;
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)scanf("%d",s+i),fns[s[i]]=true;
	for(int i=1;i<=n;i++)scanf("%d",d+i);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	for(int i=1;i<=k;i++)//�Ӹ����յ㿪ʼ������
	{
		way[s[i]].insert(0);
		dis[s[i]]=way[s[i]].begin();
		d[s[i]]=0;
		for(int j=fir[s[i]];j;j=e[j].nex)way[e[j].v].insert(e[j].w);
	}
	for(int i=1;i<=n;i++)if(!fns[i]&&way[i].size()>d[i])Relax(i);//����һ�δ����Ȱ��ܹ������Թ��ĵ��ҳ���
	while(!q.empty())
	{
		int u=q.top().second,ds=-q.top().first;q.pop();
		if(*dis[u]!=ds)continue;
//		printf("Update %d %d\n",u,*dis[u]);
		for(int i=fir[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(way[v].size()<=d[v])//���Ը���
			{
//				printf("Find %d to Insert %d\n",v,*dis[u]+e[i].w);
				way[v].insert(*dis[u]+e[i].w);
				if(way[v].size()==d[v]+1)Relax(v),q.push(make_pair(-*dis[v],v));
			}
			else if(*dis[v]>*dis[u]+e[i].w)
			{
//				printf("Find %d to Update %d\n",v,*dis[u]+e[i].w);
				way[v].insert(*dis[u]+e[i].w);
				dis[v]--;//ֱ�Ӹ���
				q.push(make_pair(-*dis[v],v));
			}
		}
	}
	printf("%d",way[1].size()>d[1]?*dis[1]:-1);
	return 0;
}
/*
Corner Cases
#1 �޽�
3 2 1
3
0 1 0
1 2 2
2 3 2
Answer:-1

#2 ��·
3 3 1
3
1 0 0
1 3 9
1 2 1
2 3 1
Answer:9
*/

//At 16:18 ͨ�����д����� & Corner Cases 
