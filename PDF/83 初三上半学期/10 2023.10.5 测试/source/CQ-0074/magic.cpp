/*
二分最后的总和，然后发现不好判定
我们建出n个四元组{i,li,ri,ci}，我们先按照(ri-li+1)*ci递减排序
然后我们依次插入每个四元组，算出当前四元组在插入进每对四元组中间时对答案的影响，取最优的地方
时间复杂度O(n^2logn)，正确性不保证
一会写个暴力对拍一下
完了，贪心假了
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
int n;
struct as{
	int id,l,r,c;
	int s1,s2;
}a[N];
int ans;
bool cmp(as x,as y){
	return x.c>y.c;
}
bool cmp2(as x,as y){
	return x.s1>y.s1;
}
bool cmp3(as x,as y){
	return x.s1-x.s2>y.s1-y.s2;
}
bool cmp4(as x,as y){
	return x.s2<y.s2;
}
bool cmp5(as x,as y){
	return x.id>y.id;
}
int cz[N];
int an[N];
void cl(){
	for(int i=1;i<=n;i++){
		a[i].s1=(a[i].r-a[i].l+1-(a[i].l<=a[i].id&&a[i].r>=a[i].id))*a[i].c;
		for(int j=a[i].l;j<=a[i].r;j++){
			a[j].s2+=a[i].c;
		}
	}
	int lans=0;
	memset(cz,0,sizeof(cz));
	for(int i=1;i<=n;i++){
		if(i==1){
			cz[i]=1;
			lans=(a[1].r-a[1].l+1-(a[1].l<=a[1].id&&a[1].r>=a[1].id))*a[1].c;
			continue;
		}
		for(int j=0;j<i;j++){
			an[j]=0;
		}
		int x=0;
		for(int j=0;j<i;j++){
			if(a[cz[j]].id>=a[i].l&&a[cz[j]].id<=a[i].r)x++;
			an[j]=(a[i].r-a[i].l+1-(a[i].l<=a[i].id&&a[i].r>=a[i].id)-x)*a[i].c;
			// if(i==2)cout<<x<<" "<<a[cz[j]].id<<"  ";
		}
		// if(i==2)cout<<endl;
		x=0;
		for(int j=i-1;j>=0;j--){
			an[j]-=x;
			if(a[i].id<=a[cz[j]].r&&a[i].id>=a[cz[j]].l)x+=a[cz[j]].c;
		}
		x=0;
		for(int j=0;j<i;j++){
			if(an[j]>=an[x]){
				x=j;
			}
		}
		for(int j=i;j>x+1;j--){
			cz[j]=cz[j-1];
		}
		cz[x+1]=i;
		lans+=an[x];
		// for(int j=0;j<i;j++){
		// 	cout<<an[j]<<" ";
		// }
		// cout<<"   "<<x<<endl;
		// for(int i=1;i<=n;i++){
		// 	cout<<a[cz[i]].id<<" ";
		// }
		// cout<<endl;
	}
	ans=max(ans,lans);
	// cout<<lans<<endl;
}
void sol1(){
	ans=0;
	sort(a+1,a+n+1,cmp);
	cl();
	// cout<<endl;
	sort(a+1,a+n+1,cmp2);
	cl();
	sort(a+1,a+n+1,cmp3);
	cl();
	sort(a+1,a+n+1,cmp4);
	cl();
	sort(a+1,a+n+1,cmp5);
	cl();
	printf("%lld",ans);
}
int vis[N],dis[N];
int ch(){
	memset(dis,0,sizeof(dis));
	int sum=0;
	for(int i=1;i<=n;i++){
		int x=cz[i];
		dis[a[x].id]=1;
		for(int j=a[x].l;j<=a[x].r;j++){
			sum+=a[x].c*(1-dis[j]);
		}
	}
	return sum;
}
void dfs(int k){
	if(k>n){
		ans=max(ans,ch());
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;cz[k]=i;
			dfs(k+1);
			cz[k]=0;vis[i]=0;
		}
	}
}
void sol2(){
	ans=0;
	dfs(1);
	cout<<ans;
}
void sol3(){
	printf("0");
	return;
}
void sol4(){
	int l=1,r=n,k=1,tot=0;;
	while(l<r){
		if(k==1)cz[++tot]=l,l++,k=0;
		else cz[++tot]=r,r--,k=1;
	}
	int ans=ch();
	printf("%lld",ans);
}
signed main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	int mx=-1,fl1=1,fl2=1;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].c);
		a[i].id=i;
		mx=max(mx,max(i-a[i].l,a[i].r-i));
		if(a[i].l!=max(i-6,1ll)||a[i].r!=min(i+6,n))fl1=0;
		if(a[i].l!=max(i-7,1ll)||a[i].r!=min(i+7,n))fl2=0;
	}
	if(n<=10)sol2();
	else if(mx<=0)sol3();
	else if(fl1)sol4();
	else if(fl2)sol4();
	else sol1();
	return 0;
}
/*
g++ magic.cpp -o magic -std=c++14 -O2 -Wall
./magic
*/