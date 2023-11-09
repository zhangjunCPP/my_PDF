#include<bits/stdc++.h>
using namespace std;
int n,a[500010],mxdp[500010],blk;
//考虑用b(4k+1)与b(4k+3)来upd b(4k+2),因为b(4k+3)肯定越靠后越好 
//....算了不会了上个根号分治吧
//更新统一
//次数<=sqrt(n)的询问暴力做，O(sqrt(n))-O(1)分块upd
//否则种类数<=sqrt(n),可以在upd的时候让别人多跑跑
//记得考虑相等情况 
//case1&2:
vector<int>pos[500010];
int in[500010];
void pos_init(){for(int i=1;i<=n;i++)pos[a[i]].push_back(i),in[i]=(int)pos[a[i]].size()-1;}
//case1:
namespace qwq1{
	int pmx[500010],bmx[1010],bl[500010],st[1010],ed[1010];
	void init(){
		int t=n/blk+(n%blk>0);
		for(int i=1;i<=t;i++)st[i]=(i-1)*blk+1,ed[i]=i*blk;ed[t]=n;
		fill_n(pmx+1,n,-1e8),fill_n(bmx,t+5,-1e8);
		for(int i=1,p=1;i<=n;i++)bl[i]=(p+=ed[p]<i);
	}
	void upd(int l,int r,int v){
		if(l>r)return;
		int p=bl[l],q=bl[r];
		if(p==q){for(int i=l;i<=r;i++)pmx[i]=max(pmx[i],v);return;}
		for(int i=l;i<=ed[p];i++)pmx[i]=max(pmx[i],v);
		for(int i=st[q];i<=r;i++)pmx[i]=max(pmx[i],v);
		for(int i=p+1;i<q;i++)bmx[i]=max(bmx[i],v);
	}
	auto query=[](int p){return max(pmx[p],bmx[bl[p]]);};
}
//case2:
int las[500010],ansof[500010];
vector<int>bigc;
void upd_bigc(int l,int v){for(int x:bigc)if(l<=las[x])ansof[x]=max(ansof[x],v);}
//end
int main(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	cin>>n;blk=sqrt(n)+1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	pos_init(),qwq1::init();
	for(int i=1;i<=n;i++)if((int)pos[i].size()>blk)bigc.push_back(i);
	for(int i=1;mxdp[i]=mxdp[i-1],i<=n;las[a[i]]=i,i++)
	if(las[a[i]]){
		mxdp[i]=max(mxdp[i],ansof[a[i]]);
		if((int)pos[i].size()<=blk)for(int j=0;j<in[i];j++)mxdp[i]=max(mxdp[i],qwq1::query(pos[a[i]][j])); 
		//先不考虑a....a....a的情况 
		qwq1::upd(las[a[i]]+1,i-1,mxdp[las[a[i]]-1]+1);
		upd_bigc(las[a[i]]+1,mxdp[las[a[i]]-1]+1);
		//a.....a.....a的情况
		if(in[i]>1){
			int laslas=pos[a[i]][in[i]-2];
			ansof[a[i]]=max(ansof[a[i]],mxdp[laslas-1]+1);
		}
	}cout<<mxdp[n]*4;
	return 0;
}
