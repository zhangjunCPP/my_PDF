#include <bits/stdc++.h>
using namespace std;
struct Node{
	int p,q;
	char r;
} a[100005];
int ans[45];
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	int n,k,l;
	cin>>n>>k>>l;
	for(int i=1;i<=n;i++) cin>>a[i].p>>a[i].q>>a[i].r;
	int mini=1;
	while(1){
		mini=0;
		for(int i=1;i<n;i++){
			if(a[i].p==0||a[i+1].p==n+1) continue;
			if(a[i].r=='D'&&a[i+1].r=='L'&&(mini==0||a[i+1].p-a[i].p<a[mini+1].p-a[mini].p))
				mini=i;
		}
		if(!mini) break;
		int k=(a[mini+1].p-a[mini].p+1)/2;
		for(int i=1;i<=n;i++){
			if(a[i].r=='L') ans[a[i].q]+=min(a[i].p,k),a[i].p-=min(a[i].p,k);
			else ans[a[i].q]+=min(l-a[i].p+1,k),a[i].p+=min(l-a[i].p+1,k);
		}
		int tmp=a[mini].q;
		a[mini].q=(a[mini].q+a[mini+1].q)%k;
		a[mini+1].q=tmp;
		swap(a[mini],a[mini+1]);
	}
	for(int i=0;i<k;i++)
		cout<<ans[i]<<endl;
	return 0;
} 
