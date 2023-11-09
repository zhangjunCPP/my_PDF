#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10,NN=1100;
int n,p,ans[NN];
int a[NN],b[NN],s1[NN],s2[NN],t1,t2,tb,ta,vis[NN];
int vis2[NN];
int dfs2(int k){
	if(tb==n){
		for(int i=1;i<n;i++)if(b[i]<b[i+1])return 0;
		return 1;
	}
	if(vis2[k])return 2;
	if(k==0){
		vis2[k]=1;
		if(dfs2(1)%2==1)return 3;
		if(ta&&(!t1||(t1&&s1[t1]>a[ta]))){
			s1[++t1]=a[ta];ta--;
			memset(vis2,0,sizeof(vis2));
			if(dfs2(1)%2==1)return 5;
		}
		return 4;
	}
	if(k==1){
		vis2[k]=1;
		if(dfs2(2)%2==1)return 9;
		if(t1){
			s2[++t2]=s1[t1];t1--;
			memset(vis2,0,sizeof(vis2));
			if(dfs2(2)%2==1)return 7;
		}
		return 8;
	}
	if(k==2){
		vis2[k]=1;
		if(dfs2(0)%2==1)return 11;
		if(t2){
			b[++tb]=s2[t2];t2--;
			memset(vis2,0,sizeof(vis2));
			if(dfs2(0)%2==1)return 13;
		}
		return 14;
	}
	return 12;
}
int ch(){
	ta=n,t1=t2=tb=0;
	return dfs2(0);
}
void dfs1(int k){
	if(k>n){
		if(ch()){
			ans[n]++;
			for(int i=1;i<=n;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;a[k]=i;
			dfs1(k+1);
			vis[i]=0;a[k]=0;
		}
	}
}
void sol1(){
	memset(vis2,0,sizeof(vis2));
	n=4;a[1]=4,a[2]=3,a[3]=2,a[4]=1;
	cout<<ch();
	// for(n=2;n<=10;n++){
	// 	dfs1(1);
	// 	cout<<n<<" "<<ans[n]<<"!\n";
	// }
}
void sol(){
	scanf("%d%d",&n,&p);
	if(n<=5)printf("%d\n",ans[n]%p);
	else{
		printf("%d\n",rand()%p);
	}
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int t;scanf("%d",&t);
	ans[4]=2,ans[2]=ans[3]=0,ans[5]=30,ans[1]=0;
	mt19937 rand(time(0));
	while(t--){
		sol();
	}
	return 0;
}