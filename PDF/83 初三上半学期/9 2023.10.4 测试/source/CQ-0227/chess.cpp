#include<bits/stdc++.h>
using namespace std;
const int N=2010;
bitset<N>v[N];
vector<bitset<N> >c;
set<int>st[N];
vector<int>a[N];
int cnt[N];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int p,K;scanf("%d%d",&p,&K);
	int tot=1;
	for(int i=1;i<=K;i++)tot*=p;
	if(K==1){
		printf("1\n");
		for(int i=0;i<p;i++)printf("%d ",i);
		return 0;
	}
	if(p==2){
		int ans=tot*(tot-1)/2;
		printf("%d\n",ans);
		for(int i=0;i<tot;i++)for(int j=i+1;j<tot;j++)printf("%d %d\n",i,j);
		return 0;
	}
	int ans=tot*(tot-1)/2/(p*(p-1)/2);
	printf("%d\n",ans);
	for(int i=0;i<tot;cnt[i]=tot-1,i++)for(int j=0;j<tot;j++)if(i^j){
		v[i][j]=1,st[i].insert(j);
	}
	
	//int idd=0;
	//for(int i=0;i<tot;i++){
		//int l=idd,r=idd+cnt[i]-1;
		//bitset<N>t;
		//t[i]=1;
		//for(int j=l;j<=r;j++)c.push_back()
		//for(int x:st[i]){
			
		
		//idd+=cnt[i];
	//}
	for(int i=1;i<=ans;i++){
		for(int j=1;j<=p;j++)cout<<a[i][j-1]<<" ";
		cout<<"\n";
	}
	return 0;
}
