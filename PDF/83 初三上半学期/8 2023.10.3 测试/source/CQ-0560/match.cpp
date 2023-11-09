//the code is from chenjh
#include<bits/stdc++.h>
using namespace std;
int n,m;
bool b[1000005];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int x;k--;) scanf("%d",&x),b[x]=1;
	}
	for(int i=m;i>0;i--) putchar(b[i]|'0');
	return 0;
}

