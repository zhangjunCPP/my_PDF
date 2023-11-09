#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=1e5+5;
using ull=unsigned long long;
int n;
const ull p=19191001;
ull hsh[N],pw[N];
char s[N];
vector<int> e[128]; 
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",s+1);n=strlen(s+1);pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*p,hsh[i]=hsh[i-1]+s[i]*pw[i-1],e[s[i]].push_back(i);
	for(int i=1;i<=n;i++){
		int cnt=0;
		int tmp=lower_bound(e[s[i]].begin(),e[s[i]].end(),i)-e[s[i]].begin();
		if(tmp+2>=e[s[i]].size()){
			printf("0 ");
			continue;
		}
		for(int j=tmp+1;j<e[s[i]].size()-1;j++){
			int len=e[s[i]][j]-i;
			if(len>(n-i)/3)break;
			int l=i+len,m=i+len*2-1,r=n-len+1;
			if(
			hsh[m]-hsh[l-1]==(hsh[l-1]-hsh[i-1])*pw[len]&&
			hsh[n]-hsh[r-1]==(hsh[m]-hsh[l-1])*pw[len+r-m-1])cnt++;
		}
//		for(int len=1;len<=(n-i)/3;len++){
//			int l=i+len,m=i+len*2-1,r=n-len+1;
//			if(
//			hsh[m]-hsh[l-1]==(hsh[l-1]-hsh[i-1])*pw[len]&&
//			hsh[n]-hsh[r-1]==(hsh[m]-hsh[l-1])*pw[len+r-m-1])cnt++;
//		}
		printf("%d ",cnt);
	} 
	return 0;
}
