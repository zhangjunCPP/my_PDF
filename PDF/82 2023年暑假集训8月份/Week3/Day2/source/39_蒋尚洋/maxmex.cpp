//整体二分,然后双指针check?
//对于跑到>mid的询问,肯定也要满足<=mid里的条件,取max就行? 
//注:想了不到10min?现在8:33
//仔细想想怎么维护left pointer?
//暴力一点我直接sgt维护+二分
//短时间好像想不到啥好做法啊... 
//8:46:等等哈,如果给定mex和r,那l不就是<=mex的所有数上一次出现位置的min 
//更明智的选择肯定是把所有k处理出来 
//但是如果要写这个怎么样都是要写sgt吧...
//如果我用一个node来维护lptr为l的范围呢?
//lptr肯定是传下来的某个数,所以暴力搞没问题? 
//差不多了,就酱吧. 
//8:53:等等等
//如果我利用k大mex大的性质来做整体二分呢?
//这样就是所有长为k的区间中是否有一个含有[l,r]的所有数
//怎么check这个?
//肯定是吧所有[l,r]的pos拉出来,然后按顺序跳
//欸搞错了
//那怎么check这个?这个好像check不动?
//9:03upd:wtm都用node来维护了不是直接做了吗.... 
//再看一眼时间复杂度:只要我每次都只合并必要的那么只合n次 
//9:20:真tm难写
//琢磨一下写法:
//1.暴力的写肯定是可以的
//2.采用odt的split的函数(?)
//9:28:算了等会来写
//10:10:我回来了
//没得的lptr设为0即可,到时候判一判 
//10:35写完过小样例!
//10:37大样例过了
//10:37:开始写对拍 
//10:50开始对拍 
//11:06:数据这么不好造!草!不拍
//还是要拍一下 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],ans[100010];
vector<int>pos[100010];
struct node_t{int l;mutable int r,lptr;bool operator<(const node_t&o)const{return l<o.l;};};
set<node_t>odt;
map<int,int>cnt;
auto upd=[](node_t x,int v){if(x.lptr)if(!(cnt[x.l-x.lptr+1]+=v))cnt.erase(x.l-x.lptr+1);};
auto split(int x){
	if(x==n+1)return end(odt);
	if(!x)return begin(odt);
	auto it=prev(odt.upper_bound({x,0,0}));
	if(x==it->l)return it;
	int r=it->r,ptr=it->lptr;
	it->r=x-1;
	upd({x,r,ptr},1);
	return odt.insert({x,r,ptr}).first;
}
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n+1;i++)pos[i].push_back(0);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]].push_back(i),odt.insert({i,i,i}),upd({i,i,i},1);
	for(int i=0;i<=n+1;i++)pos[i].push_back(n+1);
	for(int mex=1;mex<=n+2;mex++){//加入mex-1
		int ad=mex-1,sz=pos[ad].size();
		for(int i=0;i+1<sz;i++){
			int l=pos[ad][i],r=pos[ad][i+1];
			auto rit=split(r),lit=split(l),pr=rit;
			if(rit!=lit){
				for(;pr!=lit&&prev(pr)->lptr>l;upd(*--pr,-1));
				if(pr!=rit){
					int newl=pr->l; 
					odt.erase(pr,rit),
					upd(*odt.insert({newl,r-1,l}).first,1);
				}
			}
		}if(!cnt.empty())ans[begin(cnt)->first]=mex;
	}for(int i=1;i<=n;i++)ans[i]=max(ans[i],ans[i-1]);
	cin>>m;for(int k;m--;)
	scanf("%d",&k),printf("%d\n",ans[k]);
	return 0;
}
