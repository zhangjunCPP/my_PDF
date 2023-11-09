#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+19;
struct inty{
	int pls,col;
};
inty lft[N],rit[N];
int top1,top2,n,k,l;
char str[1+1+4+5+1+4];
double ans[N];
bool comp(inty a,inty b){
	return a.pls>b.pls;
}
signed main(){
//	freopen("D:\\down1014\\chameleon\\ex_chameleon4.in","r",stdin);
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.in","w",stdout);
	scanf("%d%d%d",&n,&k,&l);
	for(int i=1;i<=n;i++){
		inty pos;
		scanf("%d%d%s",&pos.pls,&pos.col,str+1);
		if(str[1]=='L'){
			lft[++top1]=pos;
		}else{
			rit[++top2]=pos;
		}
	}
	sort(rit+1,rit+top2+1,comp);
	for(int i=1;i<=top1;i++){
		double nowpls=lft[i].pls;
		int nowcol=lft[i].col;
		double nowtime=0;
		for(int i=1;i<=top2;i++){
			if(rit[i].pls+nowtime>nowpls)continue;
			double dis=(nowpls-(rit[i].pls+nowtime))/2.0;
			double deltatime=dis;
			ans[nowcol]+=dis;
			nowpls-=dis;
			nowtime+=deltatime;
			nowcol=(nowcol+rit[i].col)%k;
		}
		ans[nowcol]+=nowpls;
	}
	for(int i=1;i<=top2;i++){
		ans[rit[i].col]+=(l-rit[i].pls);
	}
	for(int i=0;i<k;i++){
		printf("%.1lf\n",ans[i]);
	}
} 
