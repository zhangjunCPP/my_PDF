#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
LL p,s,ceng[1000010];
//void dfs(int now,int x,int y){
//	if(now>p&&(x||y))return;
//	if(abs(x)+abs(y)>p-now+1)return;
//	if(now>p&&!x&&!y){
//		
//	}
//}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&p,&s);
	if((s+1)*2<p||(p&1)){printf("Impossible\n");return 0;}
	if((s+1)*2==p){
		printf("23");
		for(int i=1;i<s;++i)printf("2");
		printf("33");
		for(int i=1;i<s;++i)printf("2");
		return 0;
	}
	LL now=(s+1)*2,ss=s,len=1,flag=0,x=0;
	while(1){
		if(!ss)break;
		int tmp=ss/2;
		if(now+len*2-2*tmp<=p){
			x=(now+len*2-p)/2;
			ss-=x,len<<=1,ceng[len]=x,flag=1;break;
		}
		now=now+len*2-2*tmp,ceng[len+1]=(ss&1),len<<=1,ss>>=1;
	}
	if(flag){
		for(int i=1;i<=len;++i)printf("2");
		printf("3");
		for(int i=1;i<ceng[len];++i)printf("2");
		printf("3");
		LL res=ss,last=x;
		for(int i=len-1;i;--i){
			if(res-last>0){
				printf("1");
				for(int j=1;j<res-last;++j)printf("2");
				printf("3");
			}else printf("2");
			last=res,res+=ceng[i];
		}
		printf("3");
		for(int i=1;i<res;++i)printf("2");
	}else printf("Impossible\n");
	return 0;
}
