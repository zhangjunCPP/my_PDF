#include<stdio.h>
#include<vector>
#include<iostream>
#include<windows.h>

const int N=1e5+5;
int n,k,l;
double ans[45];
struct dy{
	double d;
	int clo,f;
};
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	scanf("%d%d%d",&n,&k,&l);
	std::vector<dy> a;
	for(int i=1;i<=n;i++){
		dy t;char c;
		scanf("%lf%d",&t.d,&t.clo);
		std::cin>>c;
		t.f=c=='L'?-1:1;
		a.push_back(t);
	}
	int ci=n;
	while(ci){
		int tt=0,f=0;
		for(dy &i:a){
//			printf("%lf %d %d\n",i.d,i.f,i.clo);
			i.d+=i.f*0.5;
			if(i.d<0||i.d>l){
				a.erase(a.begin()+tt);
				ci--;
				f=1;break;
			}
			ans[i.clo]+=0.5;
			tt++;
		}
		if(f) continue;
//		printf("\n");
//		system("pause");
		int s=a.size();
		for(int i=0;i<s;i++){
			if(a[i].d==a[i+1].d){
				int t=a[i+1].clo;
				a[i+1].clo=a[i].clo;
				a[i].clo=(a[i].clo+t)%k;
				a[i].f=-a[i].f;
				a[i+1].f=-a[i+1].f;
			}
		}
	}
	for(int i=0;i<k;i++) printf("%.1lf\n",ans[i]);
	return 0;
}

