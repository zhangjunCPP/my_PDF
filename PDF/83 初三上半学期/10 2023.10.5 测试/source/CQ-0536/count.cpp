#include<stdio.h>

#define int unsigned long long
const int N=0;
int n;
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int T;scanf("%llu",&T);
	while(T--){
		scanf("%llu",&n);int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int ii=1;ii<=n;ii++){
					for(int jj=1;jj<=n;jj++){
					if(ii*jj>i*j) break;
						if(i*j==ii*jj) ans++;
					}
				}
			}
		}
		printf("%llu\n",ans);
	}
	return 0;
}

