#include<bits/stdc++.h>
using namespace std;
const int N=110;

int a[N][20],n,k;

int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==1){
		puts("Yes");
		for(int j=0;j<=5;j++)printf("%d ",k<<j);
		puts("");
		return 0;
	}
	//printf("%d\n",siz);
	bool flag=1;
	for(int i=1;i<=n;i++){
		a[i][1]=0,a[i][2]=k; 
		int siz=2,cnt=0,pos=0,x=k;
		while(1){
			pos++;
			bool in_flag=1;
			for(int j=1;j<=siz;j++)
				if((a[i][j]^(k<<pos))!=(a[i][j]+(k<<pos)))in_flag=0;
			if(in_flag)
				for(int j=1;j<=siz;j++){
					a[i][2+(++cnt)]=a[i][j]^(k<<pos);
					if(a[i][2+cnt]>1e6)flag=0;
				}
			siz=cnt+2;
			if(cnt>=4)break;
		}
	}
	if(flag){
		puts("Yes");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=6;j++){printf("%d ",a[i][j]);
				//for(int pos=0;pos<=20;pos++)printf("%d",a[i][j]>>pos&1);
				//printf(" ");
			}
			puts("");
		}
	}else puts("No");
	return 0;
}
