#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e6+5;
ll n,m,k,tot;
vector<int> num[N],tmp;
vector<vector<int> > ans;
void get(int st,int ed){
	for(int i=st,tot=0;i<=st+n-1;i++)
		for(int j=st+n;j<=st+2*n-1;j++)
			tot++,
			num[tot].push_back(i),
			num[tot].push_back(j);
	for(int p=st+2*n,d=1;p<=ed;p+=n,d++)
		for(int i=p,stp=1;i<=p+n-1;i++,stp++)
			for(int j=1,ad=0;j<=n;j++,ad+=d)
				num[(j-1)*n+(stp+ad-1)%n+1].push_back(i);
	for(int i=1;i<=n*n;i++){
		tmp.clear();
		for(int u:num[i])
			tmp.push_back(u);
		ans.push_back(tmp);
	}
	return ;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>k;m=1;
	for(int i=1;i<=k;i++) m*=n;
	if(k==1){
		cout<<"1\n";
		for(int i=1;i<=m;i++)
			cout<<i-1<<' ';
	}
	else if(n==2){
		cout<<m*(m-1)/2<<'\n';
		for(int i=1;i<=m;i++)
			for(int j=i+1;j<=m;j++)
				cout<<i<<' '<<j<<'\n';
	}
	else if(k==2){
		for(int i=1;i<=m/n;i++){
			tmp.clear();
			for(int j=(i-1)*n+1;j<=i*n;j++)
				tmp.push_back(j);
			ans.push_back(tmp);
		}
		get(1,m);
		cout<<ans.size()<<'\n';
		for(vector<int> tmp:ans){
			for(int u:tmp) 
				cout<<u-1<<' ';
			cout<<'\n';
		}
	}
	return 0;
}
