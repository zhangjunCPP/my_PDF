#include<bits/stdc++.h>
using namespace std;
int n,k,a[100],ans[26000];
void sol1(){
//	ans[n]=2;ans[n*2-1]=4;
	ans[n]=2;
	for(int i=1;i<=n;i++){
		int s=n-1;
		for(int j=1;j<=n;j++){
			s+=min(n-j+1,i+j-1)-max(i-j,0);
		}
		ans[s]+=2;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int s1=i-1,s2=j-i-1,s3=n-j;
//			cout<<i<<" "<<j<<"  "<<s1<<" "<<s2<<" "<<s3<<"  "<<n-2+s1*(s2+s3)+n-2+s3*(s1+s2)+((s1<=s2)?j-s1-2:j-s1-1)+(s1+1)*(s2+1)*(s3+1)<<endl;
			ans[n-2+s1*(s2+s3)+n-2+s3*(s1+s2)+((s1<=s2)?j-s1-2:j-s1-1)+(s1+1)*(s2+1)*(s3+1)]+=1;
		}
	}
	for(int i=1;i<=k;i++){
		cout<<ans[i]<<" ";
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d",&n,&k);
	sol1();
	return 0;
}


