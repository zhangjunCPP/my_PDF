#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int INF=0x3f3f3f3f;
int n,m,ans[maxn],vis[maxn];
vector<int>b[maxn]; 
bool cmp(vector<int>l,vector<int>r){
	return l.size()<r.size();
}
//void check(){
//	for(int i=1;i<=n;i++){
//		if(b[i].size()==0)continue;
//		int mx=b[i][b[i].size()-1];
//		int flag=0;
//		for(int j=mx+1;j<=n;j++){
//			if(!ans[j]){
//				ans[j]=1;flag=1;
//				break;
//			}
//		}
//		if(!flag){
//			cout<<"-1\n";
//			exit(0);
//		}
//	}
//}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int num;cin>>num;
		b[i].resize(num);
		for(int j=0;j<num;j++){
			int x;cin>>x;
			b[i][j]=x;
		}
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		int len=b[i].size();
		int id=-1;
//		cout<<len<<endl;
		for(int j=0;j<len;j++){
			if(ans[b[i][j]])id=b[i][j];
			vis[b[i][j]]=1;
		}
		if(id==-1)for(int j=0;j<len;j++)ans[b[i][j]]=1;
		else{
			while(ans[id]||vis[id])id++;
			if(id>m){
				for(int j=1;j<=m;j++)cout<<ans[j];
				return 0;
			}
			for(int j=0;j<len;j++)if(b[i][j]>id)ans[b[i][j]]=1;
			ans[id]=1;
		}
		for(int j=0;j<len;j++)vis[b[i][j]]=0;
	}
	for(int i=m;i>=1;i--)cout<<ans[i];
	return 0;
}
//2 3
//1 1
//1 1
