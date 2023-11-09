#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int p=1e9+7;
int n;
string s;
namespace sub1{//n<=10
	bool check(){ return n<=10; }
	string t;
	int ans;
	map<string,bool> mp;
	void dfs(){
		if(mp.count(t)) return ;
		mp[t]=1;
		for(int i=1;i<=n;i++){
			if(t[i]=='1'){
				if(i>2&&t[i-1]=='1'&&t[i-2]=='0'){
					t[i]='0',t[i-2]='1';
					dfs();
					t[i]='1',t[i-2]='0';
				}
				if(i<n-1&&t[i+1]=='1'&&t[i+2]=='0'){
					t[i]='0',t[i+2]='1';
					dfs();
					t[i]='1',t[i+2]='0';
				}
			}
		}
	}
	void calc(int step){
		if(step>n){
			mp.clear();
			dfs();
			ans=(ans+(int)mp.size())%p;
			
			return ;
		}
		if(s[step]=='?'){
			t[step]='1';
			calc(step+1);
			t[step]='0';
			calc(step+1);
		}else{
			t[step]=s[step];
			calc(step+1);
		}
	}
	void work(){
		ans=0;
		t.resize(n+1);
		calc(1);
		printf("%d",ans);
	}
}
signed main(){
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
	cin>>n>>s;
	s=' '+s;
	sub1::work();
	
	return 0;
}
/*
5
?0110

3
???
*/
