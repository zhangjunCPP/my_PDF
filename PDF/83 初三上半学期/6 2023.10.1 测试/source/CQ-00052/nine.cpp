#include<bits/stdc++.h>
using namespace std;
int k,x,y;

int get(int x,int y){
	if(k%2==1){
		int jk=abs(x)+abs(y),dick=(k+1)/2;
		if(jk==k)return 1;
		else if(jk<k){
			if(jk%2==1)return 3;
			else return 2;
		}
		else if(jk%2==1){
			jk=jk-k-1;
			jk=(jk+1)/2;
			if(jk%k==0)return jk/k*2+1;
			else return (jk/k+1)*2+1;
		}
		else{
			if(jk<=2*k)return 2;
			jk=jk-dick*4+1;
			jk=(jk+1)/2;
			if(jk%k==0)return jk/k*2+2;
			else return (jk/k+1)*2+2;
		}
	}
	else{
		int lp=k/2,jk=abs(x)+abs(y);
		if(jk%2==1)return -1;
		else if(jk==k)return 1;
		else if(jk<k)return 2;
		else{
			int yu=jk/2;
			if(yu%lp==0)return yu/lp;
			else return yu/lp+1;
		}
	}
}
int xx,yy;
void work(int x,int y,int val){
	xx=x-k,yy=y;for(;xx<=x;xx++,yy++)if(get(xx,yy)==val-1){return;}
	xx=x,yy=y+k;for(;xx<=x+k;xx++,yy--)if(get(xx,yy)==val-1){return;}
	xx=x+k,yy=y;for(;xx>=x;xx--,yy--)if(get(xx,yy)==val-1){return;}
	xx=x,yy=y-k;for(;xx>=x-k;xx--,yy++)if(get(xx,yy)==val-1){return;}
	printf("f**k");
}
void dfs(int x,int y,int val){
	if(val==1){
		printf("%d %d\n",x,y);
		return;
	}
	work(x,y,val);
	dfs(xx,yy,val-1);
	printf("%d %d\n",x,y);
}
signed main(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
	scanf("%d%d%d",&k,&x,&y);
	int ans=get(x,y);
	printf("%d\n",ans);
	if(ans!=-1)dfs(x,y,ans);
	return 0;
}
