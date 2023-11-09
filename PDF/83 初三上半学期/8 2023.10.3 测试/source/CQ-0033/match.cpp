#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e3+2;
int n,m,mx[M];
bitset<M>S[M],s;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,x;j<=k;j++){
			cin>>x;
			S[i][x]=1;
		}
	}
	for(int i=n;i>=1;i--){
		bitset<M>t,T;
		t=S[i]^(s&S[i]);
		if(t==S[i])s|=t;
		else{
			T=s&S[i];
			int mmx=0;
			for(int j=m;j>=1;j--){
				if(T[j]){
					mmx=j;
					break;
				}
			}
			if(!mmx){
				printf("-1");
				return 0;
			} 
			int mxx=0;
			for(int j=mmx+1;j<=m;j++){
				if(!s[j]&&!T[j]&&!t[j]){
					mxx=j;
					s[j]=1;
					break;
				}
			}	
			for(int j=mxx+1;j<=m;j++){
				if(t[j]){
					s[j]=1;
				}
			}
		}
	}
	for(int i=m;i>=1;i--){
		printf("%d",(int)s[i]);
	}
	return 0;
}

