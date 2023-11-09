#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,K=45;
int n,k,len,a,b,cnt[N][K],sum[N];
struct node{
	int d,col;
	bool operator < (const node &other)const{
		return d<other.d;
	}
}L[N],R[N];
long double ans[K];
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	scanf("%d%d%d",&n,&k,&len);
	for(int i=1,d,c;i<=n;++i){
		scanf("%d%d",&d,&c),getchar();
		if(getchar()=='L') L[++a]={d,c};
		else R[++b]={d,c};
	}
	sort(L+1,L+a+1),sort(R+1,R+b+1);
	for(int i=1;i<=b;++i) ans[R[i].col]+=len-R[i].d,sum[i]=(sum[i-1]+R[i].col)%k;
	for(int i=1,j=1;i<=a;++i){
		for(;j<=b&&R[j].d<L[i].d;++j) ;
		if(j>1) ++cnt[j-1][(L[i].col+R[j-1].col)%k],ans[L[i].col]+=(L[i].d-R[j-1].d)/2.0;	
		if(L[i].d>R[1].d) ans[(sum[j-1]+L[i].col)%k]+=(R[1].d+L[i].d)/2.0;
		else ans[L[i].col]+=L[i].d;
	}
	for(int i=b;i>1;--i) for(int j=0;j<k;++j) cnt[i-1][(j+R[i-1].col)%k]+=cnt[i][j],ans[j]+=(R[i].d-R[i-1].d)/2.0*cnt[i][j];
	for(int i=0;i<k;++i) printf("%.1Lf\n",ans[i]);
	
	return 0;
}	
