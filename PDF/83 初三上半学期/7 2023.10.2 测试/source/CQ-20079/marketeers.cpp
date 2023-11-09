#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,mod=998244353;
int n,len[N];
vector<int>s[N];
int a[N],b[N],ans[N],sum;
void dfs(int k){
	if(k>n){
		for(int i=1;i<=n;i++){
			b[i]=0;
			for(int j=1+i;j<=n;j++){
				if(a[j]<a[i]){
					b[i]++;
				}
			}
			if(b[i]<ans[i])return;
			if(b[i]>ans[i]){
				sum=1;
				ans[i]=b[i];
				for(int j=i+1;j<=n;j++){
					ans[j]=0;
					for(int o=j+1;o<=n;o++){
						if(a[o]<a[j]){
							ans[j]++;
						}
					}
				}
//				cout<<sum<<"   ";
//				for(int j=1;j<=n;j++){
//					cout<<a[j]<<" ";
//				}
//				cout<<"   ";
//				for(int j=1;j<=n;j++){
//					cout<<ans[j]<<" ";
//				}
//				cout<<endl;
				return;
			}
		}
//		cout<<sum<<"   ";
		sum++;
		if(sum>mod)sum-=mod;
//		for(int i=1;i<=n;i++){
//			cout<<a[i]<<" ";
//		}
//		cout<<"   ";
//		for(int j=1;j<=n;j++){
//			cout<<b[j]<<" ";
//		}
//		cout<<endl;
		return;
	}
	for(int i:s[k]){
		a[k]=i;
		dfs(k+1);
		a[k]=0;
	}
}
void sol1(){
	dfs(1);
	printf("%d\n",sum);
}
signed main(){
	freopen("marketeers.in","r",stdin);
	freopen("marketeers.out","w",stdout);
	scanf("%d",&n);
	int mx=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		mx=max(mx,len[i]);
		for(int j=1;j<=len[i];j++){
			int x;scanf("%d",&x);
			s[i].push_back(x);
		}
	}
	if(n<=10&&mx<=5)sol1();
	else{
		cout<<0;
	}
	return 0;
}

