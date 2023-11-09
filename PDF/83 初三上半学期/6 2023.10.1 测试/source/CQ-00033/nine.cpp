#include<bits/stdc++.h>
using namespace std;
#define int long long
int k,x,y;
const int xx[5]={1,1,-1,-1};
const int yy[5]={1,-1,1,-1};
namespace sub1{
	bool check(){
		return k<=10&&abs(x)<=10&&abs(y)<=10;
	}
	const int ASD=3;
	vector<pair<int,int> > st;
	std::map<pair<int,int>,bool> vis;
	int lim;
	int xlim,ylim;
	void dfs(int ux,int uy,int step){
//		fprintf(stderr,"%lld %lld %lld %lld\n",lim,ux,uy,step);
		if(ux==x&&uy==y){
			printf("%lld\n",(int)st.size());
			for(auto u:st) printf("%lld %lld\n",u.first,u.second);
			exit(0);
		}
		if(clock()>1980){
			puts("-1");
			exit(0);
		}
		if(x<-xlim||x>xlim||y<-ylim||y>ylim||step>lim||vis.find({ux,uy})!=vis.end()) return ;
		vis[{ux,uy}]=1;
		for(int i=0;i<=k;i++){
			for(int j=0;j<4;j++){
				int vx=ux+i*xx[j],vy=uy+(k-i)*yy[j];
				st.push_back({vx,vy});
				dfs(vx,vy,step+1);
				st.pop_back();
			}
		}
	}
	void work(){
		lim=(abs(x)+abs(y))/k;
		xlim=abs(x)*ASD*k,ylim=abs(y)*ASD*k;
		if(lim>(int)1e6) puts("-1"),exit(0);
//		fprintf(stderr,"lim:%lld\n",lim);
//		return ;
		for(;;lim++){
			vis.clear();
			dfs(0,0,1);
		}
	}
}
namespace sub2{
	vector<pair<int,int> > st;
	int lim;
	map<pair<int,int>,bool> vis;
	void dfs(int ux,int uy,int step){
		if(ux==x&&uy==y){
			printf("%lld\n",(int)st.size());
			for(auto u:st) printf("%lld %lld\n",u.first,u.second);
			exit(0);
		}
		if(clock()>1980){
			puts("-1");
			exit(0);
		}
		if(step>lim||vis.find({ux,uy})!=vis.end()) return ;
		vis[{ux,uy}]=1;
		for(int i=0;i<=k;i++){
			for(int j=0;j<4;j++){
				int vx=ux+i*xx[j],vy=uy+(k-i)*yy[j];
				st.push_back({vx,vy});
				dfs(vx,vy,step+1);
				st.pop_back();
			}
		}
	}
	void work(){
		int ux=0,uy=0;
		if((abs(x)+abs(y))/k>(int)1e6) puts("-1"),exit(0);
		if(x<0){
			do{
				ux-=k;
				st.emplace_back(make_pair(ux,0));
			}while(ux-x>=k);
		}else{
			do{
				ux+=k;
				st.emplace_back(make_pair(ux,0));
			}while(x-ux>=k);
		}
		if(y<0){
			do{
				uy-=k;
				st.emplace_back(make_pair(ux,uy));
			}while(uy-y>=k);
		}else{
			do{
				uy+=k;
				st.emplace_back(make_pair(ux,uy));
			}while(y-uy>=k);
		}
		for(lim=0;;lim++){
			vis.clear();
			dfs(ux,uy,1);
		}
	}
}
signed main(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
	scanf("%lld%lld%lld",&k,&x,&y);
	if(sub1::check()) sub1::work();
	else sub2::work();
	return 0;
}
/*
20 125 135
11 -1 -2
*/
