#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
int p,k;
vector<int> z[1001];
int cnt;
vector<int> ans[1000001];
void solve(int st,int p,int k){
	if(k==1){
		cnt++;
		for(int i=st;i<st+p;i++)ans[cnt].push_back(i);
		return;
	}int bl=pow(p,k-1);
	for(int i=1;i<=p;i++)solve(st+bl*(i-1),p,k-1);
	for(int i=1;i<=p;i++){
		z[i].clear();
		for(int j=st+bl*(i-1);j<st+bl*i;j++)z[i].push_back(j);
	}
	for(int i=0;i<bl;i++){
		for(int j=0;j<bl;j++){
			cnt++;
			ans[cnt].push_back(z[1][i]);
			ans[cnt].push_back(z[2][j]);
			for(int l=3;l<=p;l++){
				ans[cnt].push_back(z[l][(j+i*(l-2))%bl]);
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	p=rd(),k=rd();
	if(k==1){
		cout<<1<<endl;
		for(int i=0;i<p;i++)cout<<i<<" ";
		return 0;
	}
	int n=pow(p,k);
/*	for(int i=1;i<=p;i++){
		for(int j=bl*(i-1);j<bl*i;j++)z[i].push_back(j);
		for(int j=bl*(i-1)+p-1;j<bl*i;j+=p-1){
			cnt++;
			for(int l=j-p+1;l<=j;l++)ans[cnt].push_back(l);
		}
	}*/
	solve(0,p,k);
	/*for(int i=0;i<bl;i++){
		for(int j=0;j<bl;j++){
			cnt++;
			ans[cnt].push_back(z[1][i]);
			ans[cnt].push_back(z[2][j]);
			for(int l=3;l<=p;l++){
				ans[cnt].push_back(z[l][(j+i*(l-2))%bl]);
			}
		}
	}*/
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		for(int id:ans[i])printf("%d ",id);
		puts("");
	}
	return 0;
}
