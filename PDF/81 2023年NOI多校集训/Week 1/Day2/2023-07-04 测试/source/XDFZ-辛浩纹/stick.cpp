#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int q,n[100004],m[100004],maxx;bool ans[504][100004];
struct node{
	int vis[504]={0};//有i条边平行在vector中的编号
	int cnt=0;//交点个数
	vector<pair<int,int/*平行的条数 组数*/> >a;//平行 范围504
	void init(){
		memset(vis,-1,sizeof(vis));
		cnt=0;a.clear();		
	}
};
map<vector<pair<int,int> >,bool>mm;
vector<node>v;//记录全部情况
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	node x;x.init();
	x.vis[1]=0;x.a.push_back({1,1});x.cnt=0;
	ans[1][0]=1;v.push_back(x);
	scanf("%d",&q);
	for(int i=1;i<=q;++i)scanf("%d%d",&n[i],&m[i]),maxx=max(maxx,n[i]);
	vector<node>hutao;node jk;
	for(int i=2;i<=maxx;++i){//500
		hutao.clear();mm.clear();
		for(int j=0;j<(int)v.size();++j){//?
			jk.init();
			jk.cnt=v[j].cnt+(i-1);
			jk.a=v[j].a;
			for(int k=1;k<=500;++k)jk.vis[k]=v[j].vis[k];
			if(mm[jk.a]!=1){
				if(jk.vis[1]<0){
					jk.a.push_back({1,1});
					jk.vis[1]=jk.a.size()-1;
				}
				else{
					jk.a[jk.vis[1]].se++;
				}
//				for(int ii=1;ii<=500;++ii)
//					for(int jj=0;jj<(int)jk.a.size();++jj){
//					if(jk.a[jj].fi==ii)jk.vis[i]=jj;
//				}
				sort(jk.a.begin(),jk.a.end());
				if(mm[jk.a]!=1){
					mm[jk.a]=1;
					hutao.push_back(jk);
				}
			}
			else{
				jk.a[jk.vis[1]].se++;
			}
		}
		for(int j=0;j<(int)v.size();++j){//?
			for(int k=0;k<(int)v[j].a.size();++k){//500
				jk.init();
				jk.cnt=v[j].cnt+(i-1-v[j].a[k].fi);
				jk.a=v[j].a;
				for(int k=1;k<=500;++k)jk.vis[k]=v[j].vis[k];
				if(jk.a[k].se==1){
					jk.vis[jk.a[k].fi]=-1;
					if(jk.vis[jk.a[k].fi+1]==-1){//可以直接在这个位置弄 
						jk.vis[jk.a[k].fi+1]=k;
						jk.a[k].fi=v[j].a[k].fi+1;
						jk.a[k].se=1;
					}
					else{//把这个搬过去
						jk.a[jk.vis[jk.a[k].fi+1]].se++;
					}
				}
				else{
					jk.a[k].se--;
					if(jk.vis[jk.a[k].fi+1]==-1){
						jk.a.push_back({jk.a[k].fi+1,1});
						jk.vis[jk.a[k].fi+1]=jk.a.size()-1;
					}
					else
						jk.a[jk.vis[jk.a[k].fi+1]].se++;
				}
				sort(jk.a.begin(),jk.a.end());
//				for(int ii=1;ii<=500;++ii)
//					for(int jj=0;jj<(int)jk.a.size();++jj){
//						if(jk.a[jj].fi==ii)jk.vis[i]=jj;
//					}
				if(mm[jk.a]!=1){
					mm[jk.a]=1;
					hutao.push_back(jk);
				}				
			}
		}
		v=hutao;
//		cout<<v.size()<<"\n";
		for(int j=0;j<(int)v.size();++j)ans[i][v[j].cnt]=1;
	}
	for(int i=1;i<=q;++i){
		if(ans[n[i]][m[i]])puts("1");
		else puts("0");
	}
	return 0;
}
