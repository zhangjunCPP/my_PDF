#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],la[N],ne[N],xb[N],d[N],mi[N],ans=0;
int b[N],tot;
void dfs(int k){
	if(tot%4==0)ans=max(ans,tot);
	if(k>n)return;
	dfs(k+1);
	if(tot%4<2){
		b[++tot]=a[k];
		dfs(k+1);
		tot--;
	}
	else if(tot%4>=2&&a[k]==b[tot-1]){
		b[++tot]=a[k];
		dfs(k+1);
		tot--;
	}
}
void cl1(){
	dfs(1);
	cout<<ans;
}
void cl2(){
	for(int i=1;i<=n;i++){
		if(!xb[a[i]]){
			xb[a[i]]=i;
		} 
		else{
			la[i]=xb[a[i]];
			ne[xb[a[i]]]=i;
			xb[a[i]]=i;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<la[i]<<" "<<ne[i]<<endl;
//	}
	for(int i=n;i;i--){
		d[i]=1e9;
		if(!ne[i])continue;
		if(ne[i]-i-1<n-ne[i]){
			for(int j=i+1;j<ne[i];j++){
				if(ne[j]&&ne[j]>ne[i]&&ne[j]<d[i]){
					d[i]=ne[j];
				}
			}
		}
		else{
			for(int j=ne[i]+1;j<=n;j++){
				if(la[j]&&la[j]>i&&la[j]<ne[i]){
					d[i]=j;
					break;
				}
			}
		}
		d[i]=min(d[i],d[ne[i]]);
		if(ne[ne[i]]){
			if(ne[ne[ne[i]]]){
				d[i]=min(d[i],ne[ne[ne[i]]]);
			}
		}
	}
	d[0]=1e9-1;
	for(int i=n;i;i--){
		if(d[mi[i+1]]>d[i]){
			mi[i]=i;
		}
		else{
			mi[i]=mi[i+1];
		}
	}
//	for(int i=1;i<=n;i++){
//		if(d[i]==1e9)cout<<0<<" ";
//		else cout<<d[i]<<' ';
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
////		if(d[i]==1e9)cout<<0<<" ";
////		else 
//		cout<<mi[i]<<' ';
//	}
	for(int j=1;j<=n;j++){
		int an=0;
//		cout<<j<<endl;
		for(int i=j;i<=n;i++){
			if(mi[i]!=0){
//				cout<<i<<' '<<d[mi[i]]<<endl;
				i=d[mi[i]];
				an+=4;
			}
			else break;
		}
//		cout<<endl;
		ans=max(ans,an);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=50)cl1();
	else cl2();
	return 0;
}
