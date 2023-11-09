#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e5+10;
int n,k,tot1,tot2,last;
double L,ans[N],mid;
char c;
struct node{
	int d,col,opt;
	double now;
}cham[N],l_cham[N],r_cham[N];
bool cmp(node a,node b){return a.d<b.d;}
bool cmp2(node a,node b){return a.d>b.d;}
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	n=read(),k=read(),L=1.0*read();
	for(int i=1;i<=n;++i){
		cham[i].d=read(),cham[i].col=read();
		c=getchar(),cham[i].opt=(c=='L'?0:1);
//		cout<<cham[i].d<<" "<<cham[i].col<<" "<<cham[i].opt<<"\n";
	}
	sort(cham+1,cham+1+n,cmp);
	for(int i=1;i<=n;++i)
		if(cham[i].opt==1)ans[cham[i].col]+=L-cham[i].d,r_cham[++tot2]=cham[i];
		else l_cham[++tot1]=cham[i];
	sort(l_cham+1,l_cham+1+tot1,cmp2),sort(r_cham+1,r_cham+1+tot2,cmp2);
	for(int i=1;i<=tot1;++i)l_cham[i].now=1.0*l_cham[i].d;
	last=1;
	for(int i=1;i<=tot1;++i){
		while(last<=tot2&&r_cham[last].d>l_cham[i].d)++last;
		if(last>tot2)break;
		for(int j=last;j<=tot2;++j){
			mid=(1.0*l_cham[i].d+r_cham[j].d)/2.0;
			ans[l_cham[i].col]+=(l_cham[i].now-mid),l_cham[i].col=(l_cham[i].col+r_cham[j].col)%k,l_cham[i].now=mid;
		}
	}
	for(int i=1;i<=tot1;++i)ans[l_cham[i].col]+=l_cham[i].now;
	for(int i=0;i<k;++i)printf("%.1lf\n",ans[i]);
	return 0;
}
/*
4 4 5
1 1 D
3 3 L
4 2 D
5 0 L
*/
