#include<bits/stdc++.h>
#define y1 sbsbsbsbsb
using namespace std;
int rd(int x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c=='-'?1:-1),c=getchar();while(isdigit(c))x=x*10+c-48,c=getchar();return x*f;}

int main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	int n=rd(),q=rd();
	while(q--){
		int x1=rd(),y1=rd(),x2=rd(),y2=rd();
		int ans=n+n;
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				int x=x2+i*(n+1),y=y2+j*(n+1);
//				cerr<<"ooo:"<<y<<endl;
				if(i!=0)y=n-y;
//				cerr<<x<<' '<<y<<endl; 
				ans=min(ans,abs(x1-x)+abs(y1-y));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

