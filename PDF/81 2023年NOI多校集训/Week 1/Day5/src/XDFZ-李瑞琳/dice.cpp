#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
int n,k,b[7],t,flag;
int get(int s){
	int cnt=0;
	while(s){
		if(s&1)++cnt;
		s>>=1;
	}
	return cnt;
}
void dfs(int now,int last){
	if(now>6){
			for(int s=(1<<6)-1;s;s=(s-1)&((1<<6)-1)){
			if(get(s)!=t)continue;
				int res=0,tmp=s,pos=1;
				while(tmp){
					if(tmp&1)res^=b[pos];
					tmp>>=1,++pos;
				}
				if(res%k!=0)return;
			}
		printf("Yes\n");
		for(int i=1;i<=n;++i){
			for(int j=1;j<=6;++j)printf("%d ",b[j]);
			printf("\n");
		}
		exit(0);
	}
	for(int i=last+1;i*k<=1e6;++i){
		b[now]=i*k;
		dfs(now+1,i);
	}
}
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	n=read(),k=read();
	if(n==1){
		printf("Yes\n");
		for(int i=1;i<=6;++i)printf("%d ",k*i);
		return 0;
	}else if(k==2){
		printf("Yes\n");
		int tot=1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=6;++j){
				printf("%d ",2*tot);++tot;
			}
			printf("\n");
		}
	}else{
		if(n<=6)t=n;
		else if((n/6)&1)t=6-n%6;
		else t=n%6;
		dfs(1,0);
	}
	return 0;
}
