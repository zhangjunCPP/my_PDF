#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int l,r;
}a[N];
int tot;
int main(){
	freopen("camera.in","r",stdin);
	freopen("camera.out","w",stdout);
	int n,s;scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
		int l,r;scanf("%d%d",&l,&r);
		if(l>r)swap(l,r);
		if(r<0)continue;
		if(l>0)a[++tot]={l,r};
		else a[++tot]={0,r};
	}
	printf("%d\n",tot);
	return 0;
}
