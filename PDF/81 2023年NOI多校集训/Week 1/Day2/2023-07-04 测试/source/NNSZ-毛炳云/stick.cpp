#include<bits/stdc++.h>
using namespace std;
int q;
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int n,m;
		scanf("%d%d",&n,&m);
		int st=n-1,ed=n*(n-1)/2;
		if(m==0)printf("%d\n",1);
		else if(m>=st&&m<=ed)printf("%d\n",1);
		else printf("%d\n",0);
	}
	return 0;
}

/*#include<bits/stdc++.h>
using namespace std;
const int N=505;
int q;
int n,m,f;//对于每一次询问 
int cha[N],cnt;//记录拆分方案的数组 

void dfs(int x,int cnt,int s,int last){//把n拆成x份
	 if(cnt==x){
	 	if(s==n){
	 		int sum=cha[1],ans=0;
		 	for(int i=2;i<=x;i++){
		 		ans+=sum*cha[i];
		 		sum+=cha[i];
			 }
			 if(m==ans){
			 	f=1;
			 	exit(0);
			 }
			 return;
		 }
		 else return;
	 }
	 for(int i=last;i<=n;i++){
	 	cha[++cnt]=i;
	 	dfs(x-1,cnt+1,s+i,i);
	 	cha[cnt]=0;
	 	cnt--;
	 }
}

int main(){
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&n,&m);f=0;
		memset(cha,0,sizeof(cha));cnt=0;
		for(int j=2;j<=n-1;j++){//枚举几组平行（拆成j组） 
			dfs(j,0,0,0); 
			if(f==1)printf("%d",1);
			else printf("%d",0);
		}
	}
	return 0;
}*/
