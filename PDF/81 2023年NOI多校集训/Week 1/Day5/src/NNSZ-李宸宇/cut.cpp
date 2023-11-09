#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;

int st,cost[N][N],f[N],n,pre[N],a[N];
void print(int i,int now){
	if(!i){
		printf("%d\n",now);
		printf("%d ",i+1);
		return;
	}
	int j=pre[i];
	print(j,now+1);
	printf("%d ",i+1);
}

int main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int l=1;l<=n;l++){
		st=0;
		for(int r=l;r<=n;r++){
			st|=(1<<a[r]);
			for(int i=0;i<=20;i++)
				if(!(st>>i&1)){cost[l][r]=i;break;}
		}
	}/*
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)printf("%d ",cost[i][j]);
		puts("");
	}*/
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++){
			if(f[i]<f[j-1]+cost[j][i]){
				f[i]=max(f[i],f[j-1]+cost[j][i]);
				pre[i]=j-1;	
			}
		}
	//for(int i=1;i<=n;i++)printf("%d ",pre[i]);
	//puts("");
	printf("%d ",f[n]);
	print(pre[n],1);
	return 0;
} 
