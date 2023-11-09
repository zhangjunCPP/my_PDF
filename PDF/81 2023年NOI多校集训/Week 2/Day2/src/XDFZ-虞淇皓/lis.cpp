//最大值最小，应该是二分最大值 
// 设dp1[i][j]表示从i到i的j级祖先(x)的的序列的最长上升子序列长度，且选x 
// dp1[i][j]=max(dp1[i][k])(k<j&&w[k]<w[j])+1;
//从每个节点往上跳，更新dp1时用树状树状维护max，复杂度O(nlogn 树的深度) 
// 设dp2[i][j]表示从i的j级祖先(x)到i的的序列的最长上升子序列长度，且选i 
// dp2[i][j]=max(dp2[i][k])(k<j&&w[k]<w[i])+1;
//从每个节点往上跳，更新dp2，复杂度O(nlogn 树的深度) 
// 则链(u,v)的权值s(u,v)=max(dp1[u][d1]+dp2[v][d2])(d1<=deep[u]-deep[lca],d2<= ,w[x]<w[y],x为u的d1级祖先,y同理)
//用树状数组优化，可以将O(n^2+logn)降为O(nlogn+nlogn) 
//我们发现任何一条链都会被一条两端点为叶子节点的链包含，所以我们只需要看两端点为叶子节点的链 
//设我们二分的最大值为mid，那么我们可以处理出不满足要求的链 （所有链，不能只找两端点为叶子节点的链 ） 
//我们发现对于一个点i，如果s(i,j)<=mid,那么s(i,k)<=mid(k在i到j的路径上)，所以我们可以先去找从i出发的距离i很远的点集S(i)
//我们可以暴力求出S(1),则对于S(i)，S(i)=S(1)， 如果i在S(1)中，则S(i)为S(1)去掉i的集合
//如果S(i)中的点x满足s(i,x)<=mid就不管，否则在i到x的路径上跑一次二分，求出路径上距离i最远的y满足s(i,y)<=mid,将y往x跳1条边；
//将(i,x)提成序列，跑双指针，可以少一个log 
//我们设d[i]表示树上差分的值 ，再假设y在i到lca(i,x)的路径上（在x到lca同理），那么设(p,q)表示p到q的路径，设o为(y,lca)的点数，p为(lca,x)的点数-1（不算lca）那么：
//d[i]+=o+p,d[(y,lca)]-=2,d[(lca,x)(不算lca)]+=1,d[lca]-=p,d[fa[lca]]-=2+2*p 我们可以树剖用线段树维护d，
//我们使用树上差分，每次将一条非法链上的点权值加1 ，只要有至少1个点被所有链经过，mid就是可行的 
//时间复杂度O(n*叶子数*logn*nlogn*logn)=O(n^2log^3n叶子数)左右 但我没时间打了！！！
// 
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out,","w",stdout);
	return 0; 
}
/* 
*/
