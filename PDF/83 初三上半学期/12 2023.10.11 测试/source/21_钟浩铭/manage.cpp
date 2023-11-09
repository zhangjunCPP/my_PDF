#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
inline void Freopen(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
}
int n,m;
int a[MAXN];
pair<int,bool> vis[MAXN];
//queue<int> q;
int main(){
	Freopen();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++) vis[i]={0,false};
		int cnt=k,ans=0;
		for(int i=1;i<=m;i++){
			if(vis[a[i]].second){vis[a[i]].first=i; continue;}
			if(cnt){cnt--; ans++; vis[a[i]].first=i; vis[a[i]].second=true;}
			else{
				ans++;
				int minn=1e9,id=0;
				for(int j=1;j<=n;j++){
					if(vis[j].second){
						if(minn>vis[j].first)
							minn=vis[j].first,id=j;
					}
				}
				vis[id].second=false;
				vis[a[i]]={i,true}; 
			}
		}
		printf("%d ",ans);
	}
	return 0;
}
/*
2 6
1 2 3 2 1 2
*/
