/*
注意到题目给的碰撞可以进行转化
我们不妨假设变色龙们相遇后并不会转向
而是各自继续沿着原来的方向走
从左往右的龙颜色不变
从右往左的龙颜色+=左边龙的颜色
可以发现这和原题目等价

因而，我们只关心从右往左的龙的颜色
据此写出暴力
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct B{
	double wz;
	int col,op,i;
}a[N];
bool cmp1(B x,B y){
	return x.wz<y.wz;
}
bool cmp2(B x,B y){
	return x.op<y.op;
}
int n,k,l,i,cn,j;
char op;
double ans[50];
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	scanf("%d%d%d",&n,&k,&l);//kkkkkkkkkkkk
	for(i=1;i<=n;++i){
		scanf("%lf%d",&a[i].wz,&a[i].col);
		cin>>op;
		if(op=='L')a[i].op=2;//从右往左
		else if(op=='D'){
			a[i].op=1;//从左往右
			ans[a[i].col]+=l-a[i].wz;
		}
		else assert(0);
	}
	sort(a+1,a+1+n,cmp1);
	for(i=1;i<=n;++i){
		if(a[i].op==1)a[i].i=++cn;
		else a[i].i=cn;
	}
	stable_sort(a+1,a+1+n,cmp2);
	for(i=n;i&&a[i].op==2;--i){
		double now=a[i].wz,plu=0;
		int col=a[i].col;
		for(j=a[i].i;j;--j){
			double ajwz=a[j].wz+plu;
			ans[col]+=(now-ajwz)/2;
			plu+=(now-ajwz)/2;
			now=(now+ajwz)/2;
			col=(col+a[j].col)%k;
		}
		ans[col]+=now;
	}
	for(i=0;i<k;++i)printf("%.1lf\n",ans[i]);
	return 0;
}
/*
2 3 10
0 0 D
10 1 L
*/
