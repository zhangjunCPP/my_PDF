#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int k,q,n,m;
char s[N],p[N];
#define ull unsigned long long
ull hs1[N],hs2[N],hp1[N],hp2[N];
const ull h=26;
ull ksm(ull a,int b){
	ull ans=1;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
ull hzs1(int l,int r){
	ull x=hs1[l-1]*ksm(h,r-l+1);
	return hs1[r]-x;
}
ull hzp1(int l,int r){
	ull x=hp1[l-1]*ksm(h,r-l+1);
	return hp1[r]-x;
}
ull hzs2(int l,int r){
	ull x=hs2[r+1]*ksm(h,r-l+1);
	return hs2[l]-x;
}
ull hzp2(int l,int r){
	ull x=hp2[r+1]*ksm(h,r-l+1);
	return hp2[l]-x;
}
int ch(int l,int r){
	if(hzs1(l,r)==hzp1(1,r-l+1))return 1;
	int ans1=l-1;
	for(int i=log2(r-l+2);i>=0;i--){
		int mid=ans1+(1<<i);
		if(mid>r)continue;
		if(hzs1(l,mid)==hzp1(1,mid-l+1))ans1=mid;
	}
	ans1++;
	int ans2=r+1;
	for(int i=log2(r-l+2);i>=0;i--){
		int mid=ans2-(1<<i);
		if(mid<l)continue;
		if(hzs2(mid,r)==hzp2(mid-l+1,m))ans2=mid;
	}
	ans2--;
	// cout<<"@"<<l<<" "<<r<<"  "<<ans1<<" "<<ans2<<"@";
	if(ans2-ans1>=k)return 0;
	return 1;
}
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%s%d",&k,s+1,&q);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		hs1[i]=hs1[i-1]*h+s[i]-'a'+1;
	}
	for(int i=n;i;i--){
		hs2[i]=hs2[i+1]*h+s[i]-'a'+1;
	}
	while(q--){
		scanf("%s",p+1);
		m=strlen(p+1);
		// cout<<n<<" "<<m<<endl;
		if(m<=k){
			printf("%d\n",max(0,n-m+1));
			continue;
		}
		hp1[0]=hp2[m+1]=0;
		for(int i=1;i<=m;i++){
			hp1[i]=hp1[i-1]*h+p[i]-'a'+1;
		}
		for(int i=m;i;i--){
			hp2[i]=hp2[i+1]*h+p[i]-'a'+1;
		}
		int ans=0;
		for(int i=1;i<=n-m+1;i++){
			int x=ch(i,i+m-1);
			ans+=x;
				// cout<<i<<" "<<x<<"\n";
		}
		// cout<<"    ";
		// cout<<hzs1(3,4)<<" "<<hzp1(1,2)<<endl;
		printf("%d\n",ans);
	}
	return 0;
}