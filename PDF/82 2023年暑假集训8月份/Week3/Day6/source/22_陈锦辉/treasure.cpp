//the code is from chenjh
#include<cstdio>
#include<algorithm>
#include<functional>
using ci=const int;
int n;
struct TS{
	int v,p,q;//价值，原来 id，份数编号。 
	TS(int _v=0,int _p=0,int _q=0):v(_v),p(_p),q(_q){}
	bool operator < (const TS&y)const{return v<y.v||(v==y.v&&p<y.p);}
	bool operator > (const TS&y)const{return v>y.v||(v==y.v&&p<y.p);}
}a[30];
int b[30];
int ans=0;
void dfs(ci pos,ci s1,ci s2,ci s3){
//	if(max({s1,s2,s3})-min({s1,s2,s3})>=ans) return;
	if(pos>n){
		if(std::max({s1,s2,s3})-std::min({s1,s2,s3})<ans){
			ans=std::max({s1,s2,s3})-std::min({s1,s2,s3});
			for(int i=1;i<=n;i++) b[a[i].p]=a[i].q;
		}
		return;
	}
	a[pos].q=1;
	dfs(pos+1,s1+a[pos].v,s2,s3);
	a[pos].q=2;
	dfs(pos+1,s1,s2+a[pos].v,s3);
	a[pos].q=3;
	dfs(pos+1,s1,s2,s3+a[pos].v);
	a[pos].q=0;
}
int main(){
	std::freopen("treasure.in","r",stdin);
	std::freopen("treasure.out","w",stdout);
	std::scanf("%d",&n);
	for(int i=1;i<=n;i++) std::scanf("%d",&a[i].v),a[i].p=i,ans+=a[i].v;
	std::sort(a+1,a+n+1,std::greater<TS>());
	dfs(1,0,0,0);
	for(int i=1;i<=n;i++) std::printf("%d ",b[i]);
	return 0;
}
