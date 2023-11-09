#include<bits/stdc++.h>
using namespace std;
const int N=2e3+2;
int p,k,n,c;
vector<int>ans[N];
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&p,&k);
	n=qpow(p,k);
	for(int i=0;i<n;i++){
		ans[++c].push_back(i);
		for(int j=i+1;j<n;j++){
			if((int)ans[c].size()==p){
				ans[++c].push_back(i);
			}
			ans[c].push_back(j);
		}
		if((int)ans[c].size()!=p){
			while(ans[c].size()){
				ans[c].pop_back();
			}
			c--;
		}
	}
	printf("%d\n",c);
	for(int i=1;i<=c;i++){
		for(int x:ans[i]){
			printf("%d ",x);
		}
		printf("\n");
	}
	return 0;
}

