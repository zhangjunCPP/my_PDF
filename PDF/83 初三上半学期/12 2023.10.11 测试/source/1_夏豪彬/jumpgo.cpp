#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0'); 
} 
inline void FRE(){
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
}
typedef unsigned long long ULL;
const int N=505;
const int mod=1e9+7;
int n,ans,cnt;
string s,a;
map<ULL,int> mp;
inline ULL Hash(){
	ULL sum=0;
	for(int i=1;i<=n;++i){
		sum=sum*2+a[i]-'0';
	}
	return sum;
}
inline int Get(int pos){
	int sum=1;        
	ULL xx=Hash();
	if(mp[xx]==pos)return 0;
	mp[xx]=pos;
	for(int i=1;i<n;++i){
		if(a[i]=='0')continue; 
		if(a[i]==a[i+1]){
			if(a[i-1]=='0'){
				a[i]=a[i+1]='0';
				a[i-1]=a[i]='1';
				sum+=Get(pos);
				a[i-1]=a[i]='0';
				a[i]=a[i+1]='1';
			}
			if(a[i+2]=='0'){
				a[i]=a[i+1]='0';
				a[i+1]=a[i+2]='1';
				sum+=Get(pos);
				a[i+1]=a[i+2]='0';
				a[i]=a[i+1]='1';
			}
		}
	}
	return sum;
}
inline void dfs(int pos){
	if(pos==n+1){
		ans+=Get(++cnt);
		return;
	}
	if(s[pos]=='?'){
		a[pos]='0';
		dfs(pos+1);
		a[pos]='1';
		dfs(pos+1);	
	}
	else{
		a[pos]=s[pos];
		dfs(pos+1);
	}
}
int main(){
	FRE();
	n=rd();
	for(int i=1;i<=n;++i){
		cin>>s[i];
	}
	a[0]=a[n+1]='1';
	dfs(1);
	wr(ans); 
	return 0;
}
