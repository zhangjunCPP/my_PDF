#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int d,co;
}a[N],b[N];
int a1,b1;
double ans[50];
int cmp(node x,node y){
	return x.d<y.d;
}
void solve(int n,int k,int L){
	for(int i=1;i<=b1;i++)ans[b[i].co]+=L-b[i].d;
	for(int i=1;i<=a1;i++){
		double las=0;
		for(int j=b1;j;j--)if(a[i].d>b[j].d){
			double t=(1.0*a[i].d-b[j].d)/2.0;
			ans[a[i].co]+=t-las;
			//cout<<a[i].d<<" "<<b[j].d<<" "<<a[i].co<<"\n";
			las=t;
			a[i].co=(a[i].co+b[j].co)%k;
		}
		
		
		double t=a[i].d;
		ans[a[i].co]+=t-las;
		//for(int i=0;i<k;i++)printf("%.1lf ",ans[i]);
		//cout<<"\n";
	}
	for(int i=0;i<k;i++)printf("%.1lf\n",ans[i]);
}
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	int n,k,L;scanf("%d%d%d",&n,&k,&L);
	for(int i=1;i<=n;i++){
		int x,y;char ch[5];scanf("%d%d%s",&x,&y,ch+1);
		if(ch[1]=='L')a[++a1]={x,y};
		else b[++b1]={x,y};
	}
	sort(a+1,a+1+a1,cmp),sort(b+1,b+1+b1,cmp);
	if(n<=1000){
		solve(n,k,L);
		return 0;
	}
	return 0;
}
