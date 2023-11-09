#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
int v[200005],p[200005],out[200005],st[200005],top;
int check(){
	bool f;
	f=true;
	for(int i=1;i<=n;i++)if(v[i]!=i){f=false;break;}
	if(f)return 1;
	
	f=true;
	for(int i=1;i<=n;i++)if(v[i]!=n-i+1){f=false;break;}
	if(f)return 2;
	
	if(n<=9)return 3;
	
	return 4;
}
void Freopen(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	int flag=check();
	if(flag==1){
		printf("%lld\n",1ll*n*(n-1)/2);
		for(int i=n;i;i--) 
			printf("%d ",i);
		puts("");
	}
	else if(flag==2){
		printf("%lld\n",1ll*n*(n-1));
		for(int i=2;i<=n;i++)
			printf("%d ",i);
		printf("1");
		puts("");
	}
	else if(flag==3){
		ll ans=0,sum;
		for(int i=1;i<=n;i++)p[i]=i;
		do{
			top=sum=0;
			for(int i=1;i<=n;i++){
				int num=0;
				while(top&&st[top]>p[i])++num,--top;
				sum+=1ll*num*v[p[i]];
				st[++top]=p[i];
			}
			if(sum>ans){
				ans=sum;
				for(int i=1;i<=n;i++)
					out[i]=p[i];
			}
		}while(next_permutation(p+1,p+1+n));
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
			printf("%d ",p[i]);
		puts("");
	}
	else
		puts("114514");
}
/*
10
2 2 1 24 13 15 20 10 29 29

*/
