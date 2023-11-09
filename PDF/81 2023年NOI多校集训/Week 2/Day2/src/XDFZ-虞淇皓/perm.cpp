//暴力枚举
//找了很久的规律都没有找出来 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,mod,ans[100],a[100],b[100],vis[100];
bool ch(int x){
	for(int i=1;i<=x;i++)b[a[i]]=i;
	for(int i=1;i<=x;i++){
		if(b[i]>a[i])return 1;
		if(b[i]<a[i])return 0;
	}
	return 0;
}
void dfs(int k,int md){
	if(k>md){
		if(ch(md)){
//			for(int i=1;i<=md;i++){
//				cout<<a[i]<<" ";
//			}
//			cout<<endl;
//			for(int i=1;i<=md;i++){
//				cout<<b[i]<<" ";
//			}
//			cout<<endl<<endl;
			ans[md]++;
			ans[md]%=mod;
		}
		return;
	}
	for(int i=1;i<=md;i++){
		if(!vis[i]){
			vis[i]=1;
			a[k]=i;
			dfs(k+1,md);
			a[k]=0;
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out,","w",stdout);
	scanf("%lld%lld",&n,&mod);
//	cout<<"1 0 0 0\n";
	for(int i=2;i<=n;i++){
		dfs(1,i);
//		cout<<i<<" "<<ans[i]<<" "<<ans[i]-ans[i-1]<<" "<<(ans[i]-ans[i-1])/(i-1)<<endl;
	}
//	cout<<endl;
	int s=0;
	for(int i=1;i<=n;i++){
		int x=s;
		s^=ans[i];
//		cout<<i<<' '<<s<<" "<<s-x<<endl;
	}
	cout<<s;
	return 0; 
}
