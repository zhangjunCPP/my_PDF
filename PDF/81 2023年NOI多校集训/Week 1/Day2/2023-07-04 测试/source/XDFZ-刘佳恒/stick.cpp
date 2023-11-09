#include<bits/stdc++.h>
using namespace std;
const int N=501;
int n,m,Q;
int a[N],mx;
vector<int> v;
void dfs(int now,int k,int las,int sp) {
	if( now>k || !las ) {
		if(now>k&&las) return ;
		int sum=0;
		for(int i=1;i<=k;i++) sum=sum+a[i]*a[i];//,cout<<a[i]<<" ";
		//puts("");
		//cout<<sum<<" ";
		v.push_back(sum);
		return ;
	}
	for(int i=sp;i<=las;i++) {
		a[now]=i;
		dfs(now+1,k,las-i,i);
		a[now]=0;
	}
} 
int main() {
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&n,&m); 
		if(m==0) { puts("1"); continue; }
		if(2*m==n*(n+1)) { puts("1"); continue; }
		if(2*m>n*(n+1)) { puts("0"); continue; }
		
		bool fff=false;
		for(int k=1;k<=n;k++) {
			int num=n-k;
			v.clear();
			//memset(a,0,sizeof(a));
			dfs(1,k,num,0);
			for(int i=0;i<(int)v.size();i++) {
				//cout<<num*num-v[i]+2*k<<" ";
				if(num*num-v[i]+num*(k-1)+k*(k-1)==m*2) { puts("1"); fff=true; break; }
			} //puts("\n");
			if(fff) break;
		}
		if(!fff) puts("0");
	}
	return 0;
}
