/*
A maze
考虑小P和荆棘其实是对立面，类似于一个博弈论
荆棘会考虑从若干条路线进行阻碍，但其实我们可以发现无论如何荆棘的阻碍一定是完全一致的
这其实是说，我们可以确定荆棘怎么堵小P，但这不重要
荆棘是有限的，只有在前面的若干个点都已经确定了堵的方式和到达的距离之后当前点的荆棘才能够做出判断
这很类似于拓扑排序
对于当前点 $u$，它有 $e_u$ 条边能够离开点 $u$，同时有 $d_u$ 个荆棘，那么荆棘自然会选择堵掉走了之后最坏情况最好的那 $d_u$ 条
如果我们先无视荆棘？
此时我们需要找到一条最短路，这显然一个Dij能够搞定
此时由于荆棘的存在，我们不能走最短路了
也就是说，荆棘会选择把最短路ban掉
回去一下，我们是否能够去求解每个点逃出迷宫的最短时间呢？
其实我们是可以的吧？思考一下，我们所有可以逃出去的点距离为 $0$，此时使用Dij尝试寻找最近的可扩展点
所以按照这样，我们可以求出没有荆棘的情况下，所有节点的最优解呢！
那，进一步考虑荆棘
荆棘会ban掉最短的几条
那么我们需要做的是动态维护这东西，显然空间起飞
但...真的么？
准确来说每一条边只会连接两个点，这其实意味着我们一条边带来的空间消耗只有 $2$！
这其实意味着我们完全有能力存储这个东西！
虽然感觉漏洞很多，但貌似确实能做？
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
inline void Relax(int i)//对点i做松弛操作
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
	for(int i=1;i<=k;i++)//从各个终点开始反向走
	{
		way[s[i]].insert(0);
		dis[s[i]]=way[s[i]].begin();
		d[s[i]]=0;
		for(int j=fir[s[i]];j;j=e[j].nex)way[e[j].v].insert(e[j].w);
	}
	for(int i=1;i<=n;i++)if(!fns[i]&&way[i].size()>d[i])Relax(i);//做第一次处理，先把能够逃离迷宫的点找出来
	while(!q.empty())
	{
		int u=q.top().second,ds=-q.top().first;q.pop();
		if(*dis[u]!=ds)continue;
//		printf("Update %d %d\n",u,*dis[u]);
		for(int i=fir[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(way[v].size()<=d[v])//无脑更新
			{
//				printf("Find %d to Insert %d\n",v,*dis[u]+e[i].w);
				way[v].insert(*dis[u]+e[i].w);
				if(way[v].size()==d[v]+1)Relax(v),q.push(make_pair(-*dis[v],v));
			}
			else if(*dis[v]>*dis[u]+e[i].w)
			{
//				printf("Find %d to Update %d\n",v,*dis[u]+e[i].w);
				way[v].insert(*dis[u]+e[i].w);
				dis[v]--;//直接更新
				q.push(make_pair(-*dis[v],v));
			}
		}
	}
	printf("%d",way[1].size()>d[1]?*dis[1]:-1);
	return 0;
}
/*
Corner Cases
#1 无解
3 2 1
3
0 1 0
1 2 2
2 3 2
Answer:-1

#2 绕路
3 3 1
3
1 0 0
1 3 9
1 2 1
2 3 1
Answer:9
*/

//At 16:18 通过所有大样例 & Corner Cases 
