#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int p=0;
	while(1){
		system("B_rand.exe");
		system("b_bf.exe");
		system("b.exe");
		cout<<++p<<endl;
		if(system("fc b.ans b.out")){
			puts("WA");
			return 0;
		}puts("OK");
	}
	return 0;
}

