#include<bits/stdc++.h>
using namespace std;
int rd(int x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c=='-'?1:-1),c=getchar();while(isdigit(c))x=x*10+c-48,c=getchar();return x*f;}

int main(){
	srand(time(0));
//	freopen(".in","r",stdin);
	freopen("maxmex.in","w",stdout);
	int n=1e5;
	cout<<n<<endl;
	for(int i=1;i<=n;i++)printf("%d ",rand()%11);
	puts("");
	int q=1e5;
	cout<<q<<endl;
	while(q--){
		int k=1+q;
		printf("%d\n",k);
	}
	return 0;
}
