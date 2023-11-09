#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=33;
// bool st;
int n,q,len[N],ln;
char ch[N][M],s[M],dd[N];
#define ull unsigned long long
ull h[N][M],h2[M];const ull hs=31;
// bool ed;
int find(int x){
	int ans=0;
	for(int i=5;i>=0;i--){
		int mid=ans+(1<<i);
		if(mid>len[x]||mid>ln)continue;
		if(h2[mid]==h[x][mid])ans=mid;
	}
	return ans;
}
void sol1(){
	for(int i=1;i<=q;i++){
		scanf("%s",s+1);
		ln=strlen(s+1);
		for(int j=1;j<=ln;j++){
			h2[j]=h2[j-1]*hs+(s[j]-'a'+1);
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			int r=find(j);
			if(r==ln){
				ans+=ln+1;
				if(len[j]==ln){
					break;
				}
			}
			else{
				if(r==0)ans++;
				else ans+=r+1;
			}
		}
		printf("%d\n",ans);
	}
}
void sol2(){
	for(int i=1;i<=q;i++){
		scanf("%s",s+1);
		ln=strlen(s+1);
		char ss=s[1];

	}
}
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	// cout<<(&st-&ed)/1024.0/1024.0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
		len[i]=strlen(ch[i]+1);
	}
	int fl=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=len[i];j++){
			h[i][j]=h[i][j-1]*hs+(ch[i][j]-'a'+1);
			dd[i]=ch[i][j];
			if(j&&ch[i][j]!=ch[i][j-1])fl=0;
		}
	}
	scanf("%d",&q);
	if(!fl){
		sol1();
	}
	else{
		sol1();
	}
	return 0;
}
/*
g++ lihua.cpp -o lihua -std=c++14 -O2 -Wall
./lihua
*/