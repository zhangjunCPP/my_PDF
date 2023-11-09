#include<bits/stdc++.h>
using namespace std;
struct node{
	double d;
	int b,t;
	node(double d=0,int b=0,int t=0):d(d),b(b),t(t){}
}a[100001];
bool cmp(node x,node y){return x.d<y.d;}
int n,k,L,d,b,t,lst,aus[41];
double ans[41],cnt[41];
char ch[2];
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	
	scanf("%d%d%d",&n,&k,&L);
	for(int i=1;i<=n;i++){
		scanf("%d%d%s",&d,&b,ch);
		a[++t]=node(d,b,ch[0]=='L');
		if(ch[0]=='D') ans[b]+=d;//向右，颜色不变 
	}
	sort(a+1,a+1+t,cmp);
	reverse(a+1,a+1+t);
	for(int i=1;i<=t;i++){
		if(i==1){
			if(a[i].t==1) cnt[a[i].b]++;
			lst=a[i].d;
		}
		else{
			if(a[i].t==1){
				for(int j=0;j<k;j++) ans[j]+=cnt[j]*(a[i].d-lst);
				cnt[a[i].b]++,lst=a[i].d;
			}
			else{
				double mid=(a[i].d+lst)/2.0;
				for(int j=0;j<k;j++) ans[j]+=cnt[j]*(mid-lst);
				for(int j=0;j<k;j++) aus[(j+a[i].b)%k]=cnt[j];
				for(int j=0;j<k;j++) cnt[j]=aus[j];
				cnt[a[i].b]++,lst=a[i].d;
			}
		}
	}
	for(int i=0;i<k;i++) ans[i]+=cnt[i]*(L-lst);
	for(int i=0;i<k;i++) printf("%.1lf\n",ans[i]);
	return 0;
}
