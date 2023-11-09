#include<bits/stdc++.h>
using namespace std;
int rd(int x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c=='-'?1:-1),c=getchar();while(isdigit(c))x=x*10+c-48,c=getchar();return x*f;}
int n=1e5,m=5e5;
int main(){
	srand(time(0));
//	freopen(".in","r",stdin);
	freopen("tour.in","w",stdout);
	cout<<n<<' '<<m<<endl;
	int q=5e5;
	cout<<q<<endl;
	for(int i=2;i<=n;i++){
		printf("%d %d\n",i,rand()%(i-1)+1); 
	}
	for(int i=n+1;i<=m;i++){
		printf("%d %d\n",rand()%n+1,rand()%n+1);
	}
	while(q--){
		int s=rand()%n+1,t=rand()%n+1;
		printf("%d %d\n",s,t);
	}
	return 0;
}

