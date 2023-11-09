#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n;
int c[MAXN],num[MAXN];
bool vis[25];
int ans,cnt;
int main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		if(vis[c[i]]){
			int j=0;
			while(1){
				if(!vis[j]){ans+=j; break;} 
				j++;
			}
			num[++cnt]=i;
			memset(vis,false,sizeof(vis));
		}
		vis[c[i]]=true;
	}
//	for(int i=1;i<=n;i++) printf("%d ",vis[i]);
//	printf("\n");
	int j=0;
	while(1){
		if(!vis[j]){ans+=j; break;}
		j++; 
	}
	printf("%d %d\n",ans,cnt+1);
	printf("1 ");
	for(int i=1;i<=cnt;i++) printf("%d ",num[i]);
	return 0;
}
