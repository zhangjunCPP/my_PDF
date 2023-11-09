#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int a[N],f[N],st,ed,n;
int check(int Max,int Min){
	for(int i=1;i<=n;i++)f[i]=0;
	f[0]=1,f[ed]=1;
	for(int i=1;i<st;i++){
		if(a[i]>=Min&&a[i]<=Max)f[i]|=f[i-1];
		if(i>1&&a[i]+a[i-1]>=Min&&a[i]+a[i-1]<=Max)f[i]|=f[i-2];
	}
	//cout<<"*";
	for(int i=ed+1;i<=n;i++){
		if(a[i]>=Min&&a[i]<=Max)f[i]|=f[i-1];
		if(i>ed+1&&a[i]+a[i-1]>=Min&&a[i]+a[i-1]<=Max)f[i]|=f[i-2];
	}
	return f[st-1]&&f[n];
}
int R;
int get(int Min){
	int l=Min,r=R,ans=2e9;
	while(l<=r){
		int mid=(1ll*l+r)/2;
		//cout<<mid<<"\n";
		if(check(mid,Min))ans=mid-Min,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
void sol(){
	int ans=1e9;
	for(int Min=1;Min<=20;Min++){
		for(int Max=Min;Max<=20;Max++){
			for(int i=1;i<=n;i++)f[i]=0;
			f[0]=1;
			for(int i=1;i<=n;i++){
				if(a[i]>=Min&&a[i]<=Max)f[i]|=f[i-1];
				if(i>1&&a[i]+a[i-1]>=Min&&a[i]+a[i-1]<=Max)f[i]|=f[i-2];
			}
			if(f[n]){
				ans=min(ans,Max-Min);
				break;
			}
		}
	}
	printf("%d",ans);
	
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	scanf("%d",&n);
	int Max=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),Max=max(Max,a[i]);
	if(Max<=10){sol();return 0;}
	for(int i=1;i<n;i++)R=max(R,a[i]+a[i+1]);
	int ans=2e9;
	for(int i=1;i<=n;i++){
		//cout<<i<<"\n";
		st=i,ed=i;
		ans=min(ans,get(a[i]));
		if(i!=n)ed++,ans=min(ans,get(a[i]+a[i+1]));
		//cout<<ans<<"\n";
	}
	printf("%d",ans);
	return 0;
}
