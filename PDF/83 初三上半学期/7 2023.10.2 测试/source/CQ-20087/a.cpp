//���ǰ�ÿ�����εĹ켣���ߺ���ɨ����
//���������ƶ���,���Էֽ�Ϊ(i-j+1)*1 C(C=���) C-(i-j+1)�����׶�,��״���鼴��
//б�ŵ�...
//��,wc,ʱ��7s???��������ʾ�ֿ���?
//Ҫ���ȷֽ�������ߺ������ߵĹ���?
//��ô����ľͺ�������
//б�ŵ���?
//������һ��,����ӿ��Ա�Ϊ��׺��1��-1
//Ȼ�������������˺ܶ����Ͻǵľ��μ�??
//��������,һ��(x,y)�յ�(a,b)�Ĺ��׿϶���max(min(x-a+1,y-b+1),0)
//����������һ��min...
//��һ��:x-a+1<=y-b+1 <=> x-y<=a-b
//Ҳ����a<=x,b<=y,x-y<=a-b��a<=x,b<=y,x-y>a-b�������?
//��ôʵ�ʵĹ��׾���x*cnt+sum(-a+1)��y*cnt+sum(-b+1),��ô����?�����ⶼ���˼��ι�����?
//����ǿ�7s��ԭ����.../(������������...)
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int U=250000;
struct mv_t{int xl,xr,yl,yr,d;}ipt[U+10];//ͳһΪ��(0),��(2),����(1),����(7)���� 
struct node_t{int x,y,v,id;};
using mstr=basic_string<mv_t>;
using nstr=basic_string<node_t>;
int n,m,q;
ll ans[U+10];
mstr op0,op1,op2,op7;
nstr pnt;
struct BIT{
	ll s[U+10];bool vis[U+10];int stk[1000010],tp;
	void add(int p,int v){for(!vis[p]&&(vis[stk[++tp]=p]=true);p<=U+5;p+=p&-p)s[p]+=v;}
	void add(int l,int r,int v){add(l,v),add(r+1,-v);}
	ll ask(int p){ll res=0;for(;p;p-=p&-p)res+=s[p];return res;}
	void clr(){for(;tp;){int p=stk[tp--];vis[p]=false;for(;p<=U+5;p+=p&-p)s[p]=0;}}
}A,B;
namespace solve1{
	nstr ques[U+10];//�ǵ��޸ķ�ǰ��
	void work(){
		mstr op=op0;nstr qpnt=pnt;
		auto calc=[&](){
			for(auto u:op)
			ques[u.xl]+={u.yl,u.yr,1,0},ques[u.xl+u.d]+={u.yl,u.yr,-1,0},
			ques[u.xr+1]+={u.yl,u.yr,-1,0},ques[u.xr+u.d+1]+={u.yl,u.yr,1,0};
			for(auto u:qpnt)ques[u.x]+=u;
			for(int i=1;i<=U;i++)
			for(auto u:ques[i])
			if(u.id)ans[u.id]+=A.ask(u.y)*(i+1)+B.ask(u.y);
			else A.add(u.x,u.y,u.v),B.add(u.x,u.y,u.v*(-i));
			A.clr(),B.clr();
			for(int i=1;i<=U+1;i++)ques[i]={};
		};
		calc();op={},qpnt={};
		for(auto u:op2)op+={u.yl,u.yr,u.xl,u.xr,u.d};
		for(auto u:pnt)qpnt+={u.y,u.x,0,u.id};
		calc();
	}
}
namespace solve2{
	int tot,tp;
	node_t a[U*20+10],tmp[U*20+10];
	void cdq(int l,int r){
		if(l==r)return;
		int mid=l+r>>1;
		cdq(l,mid),cdq(mid+1,r);//��x�ź�����
		for(int i=mid+1,j=l;i<=r;i++){
			for(;j<=mid&&a[j].x<=a[i].x;j++)
			if(!a[j].id)A.add(a[j].y,a[j].v),B.add(a[j].y,tp?-a[j].v*a[j].x:-a[j].v*a[j].y);
			ll ra=A.ask(a[i].y),rb=B.ask(a[i].y);
			ans[a[i].id]+=tp?(a[i].x+1)*ra+rb:(a[i].y+1)*ra+rb;
		}A.clr(),B.clr();
		inplace_merge(a+l,a+mid+1,a+r+1,[](auto x,auto y){return x.x<y.x;});
	}
	mstr op;nstr qpnt;
	void calc(){
		tot=0;
		auto addp=[](int x,int y,int v,int d){a[++tot]={x,y,v,0},a[++tot]={x+d,y+d,-v,0};};
		auto addl=[&](int x,int l,int r,int v,int d){addp(x,l,v,d),addp(x,r+1,-v,d);};
		for(auto u:op)addl(u.xl,u.yl,u.yr,1,u.d),addl(u.xr+1,u.yl,u.yr,-1,u.d);
		for(auto u:qpnt)a[++tot]=u;
		auto cmp=[](auto x,auto y){return x.x-x.y==y.x-y.y?x.id<x.id:x.x-x.y<y.x-y.y;};
		sort(a+1,a+tot+1,cmp),copy_n(a+1,tot,tmp+1),tp=0,cdq(1,tot);
		for(int i=1;i<=tot;i++)a[tot-i+1]=tmp[i];tp=1,cdq(1,tot);
	}
	void work(){
		op=op1,qpnt=pnt,calc(),op={},qpnt={};
		for(auto u:op7)op+={u.xl,u.xr,U-u.yr+1,U-u.yl+1,u.d};
		for(auto u:pnt)qpnt+={u.x,U-u.y+1,0,u.id};calc();
	}
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)scanf("%d%d%d%d",&ipt[i].xl,&ipt[i].yl,&ipt[i].xr,&ipt[i].yr),ipt[i].d=1,op0.push_back(ipt[i]);
	for(int i=1,v,r,d;i<=m;i++){
		scanf("%d%d%d",&v,&r,&d);
		auto&o=ipt[r];
		switch(v){
			case 0:op0+={o.xl+1,o.xr+1,o.yl,o.yr,d},o.xl+=d,o.xr+=d;break;
			case 1:op1+={o.xl+1,o.xr+1,o.yl+1,o.yr+1,d},o.xl+=d,o.xr+=d,o.yl+=d,o.yr+=d;break;
			case 2:op2+={o.xl,o.xr,o.yl+1,o.yr+1,d},o.yl+=d,o.yr+=d;break;
			case 3:o.xl-=d,o.xr-=d,o.yl+=d,o.yr+=d,op7+={o.xl,o.xr,o.yl,o.yr,d};break;
			case 4:o.xl-=d,o.xr-=d,op0+={o.xl,o.xr,o.yl,o.yr,d};break;
			case 5:o.xl-=d,o.xr-=d,o.yl-=d,o.yr-=d,op1+={o.xl,o.xr,o.yl,o.yr,d};break;
			case 6:o.yl-=d,o.yr-=d,op2+={o.xl,o.xr,o.yl,o.yr,d};break;
			case 7:op7+={o.xl+1,o.xr+1,o.yl-1,o.yr-1,d},o.xl+=d,o.xr+=d,o.yl-=d,o.yr-=d;break;
		}
	}for(int i=1,x,y;i<=q;i++)scanf("%d%d",&x,&y),pnt+={x,y,0,i};
	solve1::work(),solve2::work();
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}
/*
.....
.11..
1..1.
1..1.
.21..
*/ 
