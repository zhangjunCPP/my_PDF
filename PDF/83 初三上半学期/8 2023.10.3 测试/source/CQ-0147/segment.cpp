#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pii pair<int,int> 
typedef long long ll;
const int N=2e5+10;
void File(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
}
int n,a[N],vis[N];
int id,maxn;
int l,r,ans;
int check(int mid){
	for(int i=1,las=0;i<id;){
		if(a[i]>=mid){
			i++;
			las=1;
		}
		else if(a[i]+a[i+1]>=mid&&a[i]+a[i+1]<=maxn&&i<id-1){
			 i+=2;
			 las=2;
		}
		else if(a[i]+a[i-1]>=mid&&a[i]+a[i-1]<=maxn&&las==1){
			las=2;
			i++;
		}
		else return 0;
	}
	for(int i=id+1,las=0;i<=n;){
		if(a[i]>=mid){
			las=1;
			i++;
		}
		else if(a[i]+a[i+1]>=mid&&a[i]+a[i+1]<=maxn){
			 i+=2;
			 las=2;
		}
		else if(a[i]+a[i-1]>=mid&&a[i]+a[i-1]<=maxn&&las==1){
			las=2;
			i++;
		}
		else return 0;
	}
	return 1;
}
int ccheck(int mid){
	for(int i=1,las=0;i<id;){
		if(a[i]>=mid&&a[i]<=maxn){
			i++;
			las=1;
		}
		else if(a[i]+a[i-1]>=mid&&a[i]+a[i-1]<=maxn&&las==1){
			las=2;
			i++;
		}
		else if(i==id-1) return 0;
		else if(a[i]+a[i+1]>=mid&&a[i]+a[i+1]<=maxn){
			 i+=2;
			 las=2;
		}
		else return 0;
	}
	for(int i=id+2,las=2;i<=n;){
		if(a[i]>=mid&&a[i]<=maxn){
			las=1;
			i++;
		}
		else if(a[i]+a[i-1]>=mid&&a[i]+a[i-1]<=maxn&&las==1){
			las=2;
			i++;
		}
		else if(i==n) return 0;
		else if(a[i]+a[i+1]>=mid&&a[i]+a[i+1]<=maxn){
			 i+=2;
			 las=2;
		}
		else return 0;
	}
	return 1;
}
int cccheck(int mid){
	for(int i=1,las=0;i<id;){
		if(a[i]>=mid&&a[i]<=maxn){
			i++;
			las=1;
		}
		else if(a[i]+a[i-1]>=mid&&a[i]+a[i-1]<=maxn&&las==1){
			las=2;
			i++;
		}
		else if(a[i]+a[i+1]>=mid&&a[i]+a[i+1]<=maxn&&i<id-1){
			 i+=2;
			 las=2;
		}
		else return 0;
	}
	for(int i=id+2,las=2;i<=n;){
		if(a[i]>=mid&&a[i]<=maxn){
			las=1;
			i++;
		}
		else if(a[i]+a[i+1]>=mid&&a[i]+a[i+1]<=maxn){
			 i+=2;
			 las=2;
		}
		else if(a[i]+a[i-1]>=mid&&a[i]+a[i-1]<=maxn&&las==1){
			las=2;
			i++;
		}
		else return 0;
	}
	return 1;
}
int ccccheck(int mid){
	for(int i=1,las=0;i<id;){
		if(a[i]>=mid&&a[i]<=maxn){
			i++;
			las=1;
		}
		else if(a[i]+a[i+1]>=mid&&a[i]+a[i+1]<=maxn&&i<id-1){
			 i+=2;
			 las=2;
		}
		else if(a[i]+a[i-1]>=mid&&a[i]+a[i-1]<=maxn&&las==1){
			las=2;
			i++;
		}
		else return 0;
	}
	for(int i=id+2,las=2;i<=n;){
		if(a[i]>=mid&&a[i]<=maxn){
			las=1;
			i++;
		}
		else if(a[i]+a[i+1]>=mid&&a[i]+a[i+1]<=maxn){
			 i+=2;
			 las=2;
		}
		else if(a[i]+a[i-1]>=mid&&a[i]+a[i-1]<=maxn&&las==1){
			las=2;
			i++;
		}
		else return 0;
	}
	return 1;
}
int cccccheck(int mid){
	for(int i=1,las=0;i<id;){
		if(a[i]>=mid&&a[i]<=maxn){
			i++;
			las=1;
		}
		else if(a[i]+a[i+1]>=mid&&a[i]+a[i+1]<=maxn&&i<id-1){
			 i+=2;
			 las=2;
		}
		else if(a[i]+a[i-1]>=mid&&a[i]+a[i-1]<=maxn&&las==1){
			las=2;
			i++;
		}
		else return 0;
	}
	for(int i=id+2,las=2;i<=n;){
		if(a[i]>=mid&&a[i]<=maxn){
			las=1;
			i++;
		}
		else if(a[i]+a[i-1]>=mid&&a[i]+a[i-1]<=maxn&&las==1){
			las=2;
			i++;
		}
		else if(a[i]+a[i+1]>=mid&&a[i]+a[i+1]<=maxn){
			 i+=2;
			 las=2;
		}
		else return 0;
	}
	return 1;
}
int dp[N][2];
int ccc(int mid){
	memset(dp,0,sizeof dp);
	dp[0][1]=1;
	dp[0][2]=1;
	dp[id+1][2]=1;
	dp[id+1][1]=1;
	for(int i=1;i<id;i++){
		if(a[i]>=mid){
			dp[i][1]=1;
		}
		if(a[i]+a[i-1]>=mid&&i-1>1&&(dp[i-2][1]||dp[i-2][2])){
			dp[i][2]=1;
		}
	}
	
	for(int i=id+2;i<=n;i++){
		if(a[i]>=mid){
			dp[i][1]=1;
		}
		if(a[i]+a[i-1]>=mid&&i-1>id+1&&(dp[i-2][1]||dp[i-2][2])){
			dp[i][2]=1;
		}
	}
	if((dp[id-1][1]||dp[id-1][2])&&(dp[n][1]||dp[n][2])) return 1;
	else return 0;
}
int main(){
	File();
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	l=0,r=0;
	id,maxn=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push({a[i],i});
		if(maxn<a[i]){
			maxn=a[i];
			id=i;
			r=a[i];
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]+a[i+1]==155) cout<<a[i]<<endl;
	}
	a[0]=0;
	a[n+1]=0;
	int mid,mini;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			mini=mid;
		}
		else r=mid-1;
	}
	ans=maxn-mini;
	cout<<ans<<endl;
	int M=maxn;
	for(int i=1;i<n;i++){
		if(a[i]+a[i+1]>=M){
			maxn=a[i]+a[i+1];	
			id=i;
			l=1,r=maxn;
			while(l<=r){
				mid=(l+r)>>1;
				if(ccheck(mid)){
					l=mid+1;
					mini=mid;
				}
				else r=mid-1;
			}
//			cout<<maxn<<' '<<mini<<' '<<maxn-mini<<endl;
			ans=min(ans,maxn-mini);
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]+a[i+1]>=M){
			maxn=a[i]+a[i+1];	
			id=i;
			l=1,r=maxn;
			while(l<=r){
				mid=(l+r)>>1;
				if(cccheck(mid)){
					l=mid+1;
					mini=mid;
				}
				else r=mid-1;
			}
//			cout<<maxn<<' '<<mini<<' '<<maxn-mini<<endl;
			ans=min(ans,maxn-mini);
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]+a[i+1]>=M){
			maxn=a[i]+a[i+1];	
			id=i;
			l=1,r=maxn;
			while(l<=r){
				mid=(l+r)>>1;
				if(ccccheck(mid)){
					l=mid+1;
					mini=mid;
				}
				else r=mid-1;
			}
//			cout<<maxn<<' '<<mini<<' '<<maxn-mini<<endl;
			ans=min(ans,maxn-mini);
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]+a[i+1]>=M){
			maxn=a[i]+a[i+1];	
			id=i;
			l=1,r=maxn;
			while(l<=r){
				mid=(l+r)>>1;
				if(cccccheck(mid)){
					l=mid+1;
					mini=mid;
				}
				else r=mid-1;
			}
			cout<<maxn<<' '<<mini<<' '<<maxn-mini<<endl;
			if(ans>maxn-mini){
				ans=maxn-mini;
//				cout<<maxn<<' '<<mini<<' '<<i<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
} 
