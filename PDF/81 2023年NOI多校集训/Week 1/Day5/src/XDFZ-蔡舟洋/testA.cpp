#include<bits/stdc++.h>
using namespace std;
int ans[101],pos[6];
int main(){
	srand(time(0));
	freopen("dice.out","r",stdin);
	int n,k;
	cin>>n>>k;
	string sb;cin>>sb;
	for(int i=1;i<=n;i++){
		for(int j=0;j<6;j++){
			scanf("%d",&pos[j]);
			if(pos[j]>1000000)return puts("WA"),0;
		}
		for(int j=1;j<=100;j++){
			ans[j]^=pos[rand()%6];
		}
	}
	for(int j=1;j<=100;j++){
		if(ans[j]%k!=0)return puts("WA"),0;
	}
	puts("AC");
	return 0;
}

