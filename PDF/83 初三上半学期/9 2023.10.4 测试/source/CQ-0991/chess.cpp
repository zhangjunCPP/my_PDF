#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+5;
int n,p,k;
int power(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
vector<int> a[N];
int nex[N],id[N];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&p,&k);
	n=power(p,k);
	if(k==1){
		printf("1\n");
		for(int i=0;i<n;i++) printf("%d ",i);
		return 0;
	}
	if(p==2){
		printf("%d\n",n*(n-1)/2);
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				printf("%d %d\n",i,j);
			}
		}
		return 0;
	}
	return 0;
}
