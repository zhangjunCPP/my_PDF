#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+2;
int n,m,f[N],a[N],b[N],ans,res;
vector<int>p[N];
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++){
		int pl=lower_bound(b+1,b+1+m,a[i])-b;
		p[pl].push_back(i);
	}
	ans=b[m]-b[1];
	for(int i=1;i<m;i++){//将bi的值全部删除掉
		int fg=0;
		int mn=b[i];
		for(int j:p[i]){
			if(f[j])continue;
			if(!f[j-1]&&j>1&&a[j]+a[j-1]<=b[m]){
		 		f[j+1]=f[j]=1;
			 	mn=min(a[j]+a[j+1],mn);
			}else if(!f[j+1]&&j<n&&a[j]+a[j+1]<=b[m]){
				f[j+1]=f[j]=1;
			 	mn=min(a[j]+a[j+1],mn);
			}else{
				if(!f[j-2]&&j>2&&a[j-1]+a[j-2]<=b[m]){
					f[j-2]=1;
					mn=min(a[j-2]+a[j-1],mn);
					mn=min(a[j]+a[j-1],mn);
				}else if(!f[j+2]&&j<n-1&&a[j+1]+a[j+2]<=b[m]){
					f[j+2]=1;
					mn=min(a[j+2]+a[j+1],mn);
					mn=min(a[j]+a[j+1],mn);
				}else{
					fg=1;
		 			break;	
				}
			}
		}
		if(fg){
			ans=b[m]-mn;
			break;
		}
		ans=b[m]-b[i+1];
	}
	printf("%d",ans);
	return 0;
}

