#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=1e5+5;
int a[maxn],b[maxn];
int book[maxn<<1],tot;
int ans[maxn];
int vis[maxn<<1];
int main(){
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		book[++tot]=a[i];
		book[++tot]=b[i];
	}
	sort(book+1,book+tot+1);
	tot=unique(book+1,book+tot+1)-(book+1);
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(book+1,book+tot+1,a[i])-book;
		b[i]=lower_bound(book+1,book+tot+1,b[i])-book;
	}
	int k=1;
	while(1){
		bool f1=(!vis[a[k]]);
		bool f2=(!vis[b[k]]);
		if(f1) vis[a[k]]=1;
		else if(f2) vis[b[k]]=1;
		else{
			ans[k]+=m-tot;
			break;
		}
		k++;
		if(k>n) k=1;
	}
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=tot;j++) vis[j]=0;
		int j=1;
		while(1){
			bool f1=(a[j]!=i && !vis[a[j]]);
			bool f2=(b[j]!=i && !vis[b[j]]);
			if(f1) vis[a[j]]=1;
			else if(f2) vis[b[j]]=1;
			else{
				ans[j]++;
				break;
			}
			j++;
			if(j>n) j=1;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
