#include<bits/stdc++.h>
using namespace std;
#define ls rt<<1
#define rs rt<<1|1
namespace seg{
	int tr[400100],cnt[100100];
	void build(int rt,int l,int r){
		if(l==r){
			cnt[l]=0;
			tr[rt]=l;
			return;
		}
		int m=(l+r)>>1;
		build(ls,l,m),build(rs,m+1,r);
		tr[rt]=min(tr[ls],tr[rs]);
	}
	void update(int rt,int l,int r,int x,int delta){
		if(l==r){
			cnt[l]+=delta;
			tr[rt]=cnt[l]?0x7fffffff:l;
			return;
		}
		int m=(l+r)>>1;
		if(m>=x)update(ls,l,m,x,delta);
		else update(rs,m+1,r,x,delta);
		tr[rt]=min(tr[ls],tr[rs]);
	}
	int ask(){
		return tr[1];
	}
}//0 - n
void Freopen(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
}
int n,m,q;
int a[100005];
bool check(){
	if(n<=100)return 1;
	else if(q<=10)return 2;
	else return 3;
}
void Subtask1(){
	static bool mark[105];
	while(q--){
		int ans=0;
		scanf("%d",&m);
		for(int l=1,r=m;r<=n;l++,r++){
			memset(mark,0,sizeof(mark));
			for(int i=l;i<=r;i++)mark[a[i]]=1;
			int mex=0;
			while(mark[mex])++mex;
			ans=max(ans,mex);
		}
		printf("%d\n",ans);
	}
}
void Subtask2(){
	while(q--){
		int ans=0;
		scanf("%d",&m);
		seg::build(1,0,n);
		for(int i=0;i<m;i++)seg::update(1,0,n,a[i],1);
		for(int i=1;i+m-1<=n;i++){
			seg::update(1,0,n,a[i-1],-1);
			seg::update(1,0,n,a[i+m-1],1);
			ans=max(ans,seg::ask());
		}
		printf("%d\n",ans);
	}
}
void Subtask3(){
	static int ans[100005],cnt[100005];
	for(int mex=1;mex<=11;mex++){//求解mex为mex的最小区间 我直接双指针 
		int mn=0x7fffffff,now=0;
		for(int l=1,r=0;l<=n;l++){
			while(r<n&&now<mex)now+=(!cnt[a[++r]]++&&a[r]<mex);
			if(now==mex&&!cnt[mex])mn=min(mn,r-l+1);
			now-=(!--cnt[a[l]]&&a[l]<mex);
		}
		if(mn!=0x7fffffff)ans[mn]=mex;
	}
	for(int i=1;i<=n;i++)ans[i]=max(ans[i-1],ans[i]);
	while(q--){
		scanf("%d",&m);
		printf("%d\n",ans[m]);
	}
}
int main(){
	Freopen();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&q);
	int flag=check();
	if(flag==1)Subtask1();
	else if(flag==2)Subtask2();
	else Subtask3();
}
/*

*/
