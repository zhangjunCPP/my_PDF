#include<bits/stdc++.h>
#define n 400
using namespace std;
int k,a[9004][9004];
queue<pair<int,pair<int,int> > >q;
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
		if(jk%2==1)return 0;
		else if(jk==k)return 1;
		else if(jk<k)return 2;
		else{
			int yu=jk/2;
			if(yu%lp==0)return yu/lp;
			else return yu/lp+1;
		}
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen("1.txt","w",stdout);
	memset(a,0,sizeof(a));
	cin>>k;
	q.emplace(make_pair(n/2,make_pair(n/2,0)));
	for(int i=1;i<=20000000&&q.size();++i){
		int x=q.front().first,y=q.front().second.first,op=q.front().second.second;q.pop();
		if(x<0||y<0||x>n||y>n)continue;
		if(a[x][y])continue;
		a[x][y]=op;
		int xx=x-k,yy=y;for(;xx<=x;)q.emplace(make_pair(xx,make_pair(yy,op+1))),xx++,yy++;
		xx=x,yy=y+k;for(;xx<=x+k;)q.emplace(make_pair(xx,make_pair(yy,op+1))),xx++,yy--;
		xx=x+k,yy=y;for(;xx>=x;)q.emplace(make_pair(xx,make_pair(yy,op+1))),xx--,yy--;
		xx=x,yy=y-k;for(;xx>=x-k;)q.emplace(make_pair(xx,make_pair(yy,op+1))),xx--,yy++;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			if(get(i-n/2,j-n/2)!=a[i][j])
				printf("%d %d\n",i,j);
	}
	return 0;
}
