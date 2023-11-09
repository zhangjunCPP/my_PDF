#include<bits/stdc++.h>
const int N=1e5+5;
int n,k;
double l;
struct point{
	double x;
	int c,w;
	friend bool operator < (const point &a,const point &b){
		return a.x<b.x;
	}
};
point st[N];
double ans[N];
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	scanf("%d%d%lf",&n,&k,&l);
	for(int i=1;i<=n;i++){
		double x; int c; char w[2]; scanf("%lf%d%s",&x,&c,w);
		st[i]={x,c,w[0]=='L'?-1:1};
	}
	std::sort(st+1,st+n+1);
	while(1){
		double minn=0x3f3f3f3f;
		for(int i=2;i<=n;i++)
			if(st[i-1].w==1&&st[i].w==-1) minn=std::min(minn,(st[i].x-st[i-1].x)/2.0);
		if(minn==0x3f3f3f3f){
			for(int i=1;i<=n;i++){
				if(st[i].x<0||st[i].x>l) continue;
				if(st[i].w==-1) ans[st[i].c]+=st[i].x;
				else ans[st[i].c]+=l-st[i].x;
			}
			break;
		}
		for(int i=1;i<=n;i++){
			if(st[i].x<0||st[i].x>l) continue;
			if(st[i].w==-1) ans[st[i].c]+=std::min(minn,st[i].x);
			else ans[st[i].c]+=std::min(minn,l-st[i].x);
			st[i]={st[i].x+(double)st[i].w*minn,st[i].c,st[i].w};
		}
		for(int i=2;i<=n;i++){
			if(st[i-1].x!=st[i].x) continue;
			int a=st[i].c,b=st[i-1].c;
			st[i].c=b,st[i-1].c=(a+b)%k;
			std::swap(st[i-1].w,st[i].w);
		}
	}
	for(int i=0;i<k;i++) printf("%.1lf\n",ans[i]);
	return 0;
}
/*
2 3 10
0 0 D
10 1 L

4 3 7
1 0 D
3 0 D
4 1 L
6 2 D

4 4 5
1 1 D
3 3 L
4 2 D
5 0 L
*/



