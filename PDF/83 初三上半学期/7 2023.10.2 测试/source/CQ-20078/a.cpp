#include<bits/stdc++.h>
#define _fre_(file,in,out) { \
	if(in) std::freopen(file".in","r",stdin); \
	if(out) std::freopen(file".out","w",stdout); \
}
namespace IO{
	template<typename _Tp>
	void read(_Tp &x){
		x=0;bool sign=false;char ch=getchar();
		for(;ch<'0'&&ch>'9';ch=getchar()) sign|=ch=='-';
		for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(ch&15);
	}
}
template<typename ...Args>
void read(Args &...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
namespace MAIN{
	constexpr int N=250001;
	using ll=long long;
	struct SegmentTree{
		struct node{
			int tag;
			ll sum;
		};
		node tr[N*4+1];
		void clear(int p,int l,int r){
			tr[p]={0,0ll};
			if(l==r) return;
			int mid=(l+r)>>1;
			clear(p<<1,l,mid),clear(p<<1|1,mid+1,r);
		}
		void pull(int p){tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;}
		void push(int p,int l,int mid,int r){
			if(tr[p].tag){
				tr[p<<1].tag+=tr[p].tag,tr[p<<1].sum+=tr[p].tag*(mid-l+1);
				tr[p<<1|1].tag+=tr[p].tag,tr[p<<1|1].sum+=tr[p].tag*(r-mid);
				tr[p].tag=0;
			}
		}
		void modify(int p,int l,int r,int L,int R,int V){
			if(L<=l&&r<=R) return tr[p].tag+=V,tr[p].sum+=(r-l+1ll)*V,void();
			int mid=(l+r)>>1;
			push(p,l,mid,r);
			if(L<=mid) modify(p<<1,l,mid,L,R,V);
			if(R>mid) modify(p<<1|1,mid+1,r,L,R,V);
			pull(p);
		}
		int query(int p,int l,int r,int X){
			if(l==r) return tr[p].sum;
			int mid=(l+r)>>1;
			push(p,l,mid,r);
			if(X<=mid) return query(p<<1,l,mid,X);
			return tr[p<<1].sum+query(p<<1|1,mid+1,r,X);
		}
	};
	struct Rec{int x1,y1,x2,y2,d;};
	constexpr int dx[]{1,1,0,-1,-1,-1,0,1},dy[]{0,1,1,1,0,-1,-1,-1};
	Rec move(int v,Rec r,int d=1){return {r.x1+dx[v]*d,r.y1+dy[v]*d,r.x2+dx[v]*d,r.y2+dy[v]*d,r.d};}
	Rec zt[N*3+1],base[N+1];
	struct Point{int x,y,id;};
	Point pt[N+1];
	std::vector<int> cs[8];
	int n,m,q,tot;
	std::vector<std::pair<int,int>> line[N+1];
	int pl[N*3+1];
	ll ans[N+1];
	SegmentTree sgt;
	void work_(std::vector<int> &cs){
		int t=0;
		auto get_id=[&t](int x){return std::lower_bound(pl+1,pl+t+1,x)-pl;};
		for(int id:cs) pl[++t]=zt[id].x1,pl[++t]=zt[id].x2+1;
		for(int i=1;i<=q;++i) pl[++t]=pt[i].x;
		std::sort(pl+1,pl+t+1);
		t=std::unique(pl+1,pl+t+1)-pl-1;
		for(int i=1;i<=t;++i) line[i].clear();
		for(int id:cs){
			line[get_id(zt[id].x1)].emplace_back(id,1);
			line[get_id(zt[id].x2+1)].emplace_back(id,-1);
		}
		for(int i=1;i<=q;++i) line[get_id(pt[i].x)].emplace_back(i,0);
		sgt.clear(1,1,N);
		for(int i=1;i<=t;++i)
			for(auto it:line[i]){
				if(it.second==0) ans[pt[it.first].id]+=sgt.query(1,1,N,pt[it.first].y)-(pt[it.first].y==1?0:sgt.query(1,1,N,pt[it.first].y-1));
				else sgt.modify(1,1,N,zt[it.first].y1,zt[it.first].y2,it.second);
			}
	}
	void work0(std::vector<int> &cs){//down
		int t=0;
		auto get_id=[&t](int x){return std::lower_bound(pl+1,pl+t+1,x)-pl;};
		for(int id:cs) pl[++t]=zt[id].y1,pl[++t]=zt[id].y2+1;
		for(int i=1;i<=q;++i) pl[++t]=pt[i].y;
		std::sort(pl+1,pl+t+1);
		t=std::unique(pl+1,pl+t+1)-pl-1;
		for(int i=1;i<=t;++i) line[i].clear();
		for(int id:cs){
			line[get_id(zt[id].y1)].emplace_back(id,1);
			line[get_id(zt[id].y2+1)].emplace_back(id,-1);
		}
		for(int i=1;i<=q;++i) line[get_id(pt[i].y)].emplace_back(i,0);
		sgt.clear(1,1,N);
		for(int i=1;i<=t;++i)
			for(auto it:line[i]){
				if(it.second==0) ans[pt[it.first].id]+=sgt.query(1,1,N,pt[it.first].x);
				else{
					int l=zt[it.first].x1,r=zt[it.first].x2,d=zt[it.first].d;
					sgt.modify(1,1,N,l,r,it.second),sgt.modify(1,1,N,l+d+1,r+d+1,-it.second);
				}
			}
	}
	void work2(std::vector<int> &cs){//right
		int t=0;
		auto get_id=[&t](int x){return std::lower_bound(pl+1,pl+t+1,x)-pl;};
		for(int id:cs) pl[++t]=zt[id].x1,pl[++t]=zt[id].x2+1;
		for(int i=1;i<=q;++i) pl[++t]=pt[i].x;
		std::sort(pl+1,pl+t+1);
		t=std::unique(pl+1,pl+t+1)-pl-1;
		for(int i=1;i<=t;++i) line[i].clear();
		for(int id:cs){
			line[get_id(zt[id].x1)].emplace_back(id,1);
			line[get_id(zt[id].x2+1)].emplace_back(id,-1);
		}
		for(int i=1;i<=q;++i) line[get_id(pt[i].x)].emplace_back(i,0);
		sgt.clear(1,1,N);
		for(int i=1;i<=t;++i)
			for(auto it:line[i]){
				if(it.second==0) ans[pt[it.first].id]+=sgt.query(1,1,N,pt[it.first].y);//,std::printf("%d %d\n",pl[i],pt[it.first].y);
				else{
					int l=zt[it.first].y1,r=zt[it.first].y2,d=zt[it.first].d;
//					std::printf("%d %d %d %d\n",l,r,d,it.second);
					sgt.modify(1,1,N,l,r,it.second),sgt.modify(1,1,N,l+d+1,r+d+1,-it.second);
				}
			}
	}
//	int calc(Point p,Rec r,int v){
//		Rec _=move(v,r,r.d);
//		int d=0;
//		if(v==3||v==5){
//			if(r.x1-p.x<0) return 0;
//			else d=r.x1-p.x;
//		}
//		else{
//			if(p.x-r.x1<0) return 0;
//			else d=p.x-r.x1;
//		}
//		if(v==5||v==7){
//			if(r.y1-p.y<0) return 0;
//			else d=std::min(d,r.y1-p.y);
//		}
//		else{
//			if(p.y-r.y1<0) return 0;
//			else d=std::min(d,p.y-r.y1);
//		}
//		--d;
//		int all=0;
//		if(v==1) all=_.x2-r.x1+1+_.y2-r.y1+1;
//		else if(v==3) all=r.x2-_.x1+1+_.y2-r.y1+1;
//		else if(v==5) all=-(_.x2-r.x1+1+_.y2-r.y1+1);
//		else all=-(r.x2-_.x1+1+_.y2-r.y1+1);
//		if(d)
//		else return std::max(r.x2-r.x1,r.y2-r.y1);
//	}
	void _main_(){
		read(n,m,q);
		for(int i=1,x1,y1,x2,y2;i<=n;++i) read(x1,y1,x2,y2),base[i]={x1,y1,x2,y2,1};
		std::vector<int> bs={};
		for(int i=1,v,r,d;i<=m;++i)
			read(v,r,d),(d!=1?(zt[++tot]=base[r],cs[v].emplace_back(tot),zt[tot].d=d-1):(bs.emplace_back(++tot),zt[tot]=base[r],0)),base[r]=move(v,base[r],d);
		for(int i=1,x,y;i<=q;++i) read(x,y),pt[i]={x,y,i};
		for(int i=1;i<=n;++i) bs.emplace_back(++tot),zt[tot]=base[i];
		work_(bs);
		for(int it:cs[4]){
			auto r=move(4,zt[it],zt[it].d);
			zt[it]=r,cs[0].emplace_back(it);
		}
		cs[4].clear();
		work0(cs[0]);
		for(int it:cs[6]){
			auto r=move(6,zt[it],zt[it].d);
			zt[it]=r,cs[2].emplace_back(it);
		}
		cs[6].clear();
		work2(cs[2]);
		bool f=true;
		for(int i=1;i<=q;++i) f&=pt[i].x<=1000&&pt[i].y<=1000;
		if(f){
			static int cnt[1005][1005];
			static auto col=[](Rec r){
				if(r.x2>1000) r.x2=1000;
				if(r.y2>1000) r.y2=1000;
				for(int i=r.x1;i<=r.x2;++i)
					for(int j=r.y1;j<=r.y2;++j)
						++cnt[i][j];
			};
			for(int v:{1,3,5,7}){
				for(int id:cs[v]){
					col(zt[id]);
					while(zt[id].d--) move(v,zt[id],1),col(zt[id]);
				}
			}
			for(int i=1;i<=q;++i) ans[pt[i].id]+=cnt[pt[i].x][pt[i].y];
		}
		else{
//			for(int i=1;i<=q;++i){
//				for(int v:{1,3,5,7}){
//					for(int id:cs[v]){
//						ans[pt[i].id]+=calc(pt[i],zt[id],v);
//					}
//				}
//			}
		}
		for(int i=1;i<=q;++i) std::printf("%lld\n",ans[i]);
		return;
	}
}
signed main(){
	_fre_("a",1,1);
	return MAIN::_main_(),0;
}
/*
1 1 2
1 3 2 4
2 1 2
1 4
2 6
*/
