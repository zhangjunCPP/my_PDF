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
int n,m,f;//����ÿһ��ѯ�� 
int cha[N],cnt;//��¼��ַ��������� 

void dfs(int x,int cnt,int s,int last){//��n���x��
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
		for(int j=2;j<=n-1;j++){//ö�ټ���ƽ�У����j�飩 
			dfs(j,0,0,0); 
			if(f==1)printf("%d",1);
			else printf("%d",0);
		}
	}
	return 0;
}*/
