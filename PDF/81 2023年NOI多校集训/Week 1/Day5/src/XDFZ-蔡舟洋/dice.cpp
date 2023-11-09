#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	if(n==1){
		puts("Yes");
		for(int i=0;i<6;i++)cout<<k*i<<" ";
		return 0;
	}
	int bit=0,m0=0;
	while(k>>bit)bit++;
	while(!((k>>m0)&1))m0++;
	vector<int> pos;
	pos.push_back(0);
	int x=k>>m0;
	for(int j=2;j<=6;j++){
		pos.push_back(x<<m0);
		if((x<<m0)>1000000){
			puts("No");
			return 0;
		}
		x*=(1<<(bit-m0));
	}
	puts("Yes");
	for(int i=1;i<=n;i++){
		for(int v:pos)printf("%d ",v);
		puts("");
	}
	return 0;
}

