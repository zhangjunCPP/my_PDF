/*
��Ȼ��O(1)��
�����ͼ�е㸴��
���ǳ��԰���������

�����Ļ�
ͼ�����������໥�����·��ѡ����У�
1.ֱ����
abs(x1-x2)+abs(y1-y2)
���abs(y1-y2)�����Ǵ����˵Ļ��ƹ�ȥ�Ĵ���Ҫ��
�Ǿ�����
���ǻ���һ����� 
�����������߼���x��Ĳ�������
 
��!!!!!!!!!!!!!!!!!!!
����һ����Сʱ
��Ŀ������!!!!!!!!!!!!!!!!!!!!!!! 
*/
#include<bits/stdc++.h>
#define ll long long 
#define y1 yl
#define fir first
#define sec second
using namespace std;
//const ll N=1010;
//ll dis[N][N];
ll n,x1,x2,y1,y2;
//bool vis[N][N];
//queue<pair<ll,ll> >q;
//const ll dx[5]={0,-1,1,0,0};
//const ll dy[5]={0,0,0,-1,1};
//void bfs(pair<ll,ll>s){
//	while(!q.empty())q.pop();
//	dis[s.fir][s.sec]=0;
//	q.push(s);vis[s.fir][s.sec]=1;
//	while(!q.empty()){
//		ll x=q.front().fir,y=q.front().sec;q.pop();
//		vis[x][y]=1;
//		for(ll i=1;i<5;++i){
//			ll p=x+dx[i],q=y+dy[i];
//			if(p<0||p>n||q<0||q>n||vis[p][q])continue;
//			dis[p][q]=dis[x][y]+1;
//			::q.push({p,q});
//			if(p==x2&&q==y2)return;
//		}
//		if(x==0&&!vis[n][n-y]){
//			dis[n][n-y]=dis[x][y]+1;
//			if(n==x2&&n-y==y2)return;
//			q.push({n,n-y});
//		}
//		if(x==n&&!vis[0][n-y]){
//			dis[0][n-y]=dis[x][y]+1;
//			if(0==x2&&n-y==y2)return;
//			q.push({0,n-y});
//		}
//		if(y==0&&!vis[x][n]){
//			if(x==x2&&n==y2)return;
//			dis[x][n]=dis[x][y]+1;
//			q.push({x,n});
//		}
//		if(y==n&&!vis[x][0]){
//			if(x==x2&&0==y2)return;
//			dis[x][0]=dis[x][y]+1;
//			q.push({x,0});
//		}
//	}
//}
ll heng(ll y1,ll y2){
	return min({abs(y1-y2),y1+1+n-y2,y2+1+n-y1});
}
ll ans1,ans2,ans3;
int main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	ll q;
	scanf("%lld%lld",&n,&q);
	while(q--){
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		ans1=abs(x1-x2)+heng(y1,y2);
		ans2=x1+1+n-x2+heng(n-y1,y2);
		ans3=x2+1+n-x1+heng(n-y1,y2);
		printf("%lld\n",min({ans1,ans2,ans3}));
//		if(x1==x2&&y1==y2)puts("0");
//		else{
//			for(ll i=0;i<=n;++i)for(ll j=0;j<=n;++j)vis[i][j]=0;
//			bfs({x1,y1});
//		}
//		printf("%lld\n",dis[x2][y2]);
	}
	return 0;
}

