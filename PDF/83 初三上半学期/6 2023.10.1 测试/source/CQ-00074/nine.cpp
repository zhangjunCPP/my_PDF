/*
判无解
猜测奇数一定有解
偶数则要求(x+y)%2==0 

一直靠近，直到自己的范围圈能够圈住终点

范围圈已经能够快速求得
可以证明一旦进圈
三步以内必得答案
此题解决 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,INF=0x7fffffff;
int k,jl[N],x,y,ans;
pair<int,int>s[N];
void dfs(int x,int y,int step){
//	printf("dfs(%d,%d,%d)\n",x,y,step);
	if(!step)return;
	int i=x-k,j=y;
	for(;i!=x;++i,--j){
		if(jl[abs(i-::x)+abs(j-::y)]==step-1){
			s[ans+step]={x,y};
			dfs(i,j,step-1);
			return;
		}
	}
	for(;j!=y;++i,++j){
		if(jl[abs(i-::x)+abs(j-::y)]==step-1){
			s[ans+step]={x,y};
			dfs(i,j,step-1);
			return;
		}
	}
	for(;i!=x;--i,++j){
		if(jl[abs(i-::x)+abs(j-::y)]==step-1){
			s[ans+step]={x,y};
			dfs(i,j,step-1);
			return;
		}
	}
	for(;j!=y;--i,--j){
		if(jl[abs(i-::x)+abs(j-::y)]==step-1){
			s[ans+step]={x,y};
			dfs(i,j,step-1);
			return;
		}
	}
}
int u,v,i,f;
int main(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
	scanf("%d%d%d",&k,&u,&v);
	if(!(k&1)&&(u+v)&1)return puts("-1"),0;
	while(abs(x-u)+abs(y-v)>k){
		if(abs(x-u)>=k){
			if(x<u)x+=k;
			else x-=k;
		}
		else if(abs(y-v)>=k){
			if(y<v)y+=k;
			else y-=k;
		}
		else{
			int les=abs(x-u);
			x=u;
			if(y<v)y+=k-les;
			else y-=k-les;
		}
		s[++ans]={x,y};
	}
	if(k&1){
		jl[k]=1;
		for(i=k-1;i;--i,f^=1)jl[i]=2+f;
	//	s[ans+jl[abs(u-x)+abs(v-y)]]={u,v};
		dfs(u,v,jl[abs(u-x)+abs(v-y)]);
		ans+=jl[abs(u-x)+abs(v-y)];
	}
	else{
		jl[k]=1;
		f=INF;
		for(i=k-1;i;--i)jl[i]=2+(i&1?f:0);
		dfs(u,v,jl[abs(u-x)+abs(v-y)]);
		ans+=jl[abs(u-x)+abs(v-y)];
	}
	printf("%d\n",ans);
	for(i=1;i<=ans;++i)printf("%d %d\n",s[i].first,s[i].second);
	return 0;
}
