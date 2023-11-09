#include<bits/stdc++.h>
using namespace std;
int tree[33][1145141],cnt=0,n,q;
set<string> se;
string a[114514];
void push(string s){
	int zz=0;
	tree[0][0]++;
	for(int i=0;i<s.size();i++){
		if(tree[s[i]-'a'+1][zz]==0){
			tree[s[i]-'a'+1][zz]=++cnt;
		}
		zz=tree[s[i]-'a'+1][zz];
		tree[0][zz]++;
	} 
} 
int find(string s){
	int zz=0,ans=0;
	ans+=tree[0][0];
	for(int i=0;i<s.size();i++){
		zz=tree[s[i]-'a'+1][zz];
		if(zz==0)return ans;
		ans+=tree[0][zz];
	} 
	return ans;
} 
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		se.insert(a[i]);
		push(a[i]);
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		string s;
		cin>>s;
		if(*se.find(s)!=s)
			cout<<find(s)<<endl;
		else{
			int ans=0;
			for(int j=1;j<=n;j++){
				ans++; 
				for(int k=0;k<s.size();k++){
					if(s[k]==a[j][k])ans++;
					else break;
				}
				if(a[j]==s)break;
			}
			cout<<ans;
		}
	}
	return 0;
}
/*
Fuck ccf!!!!!!!

"题目较简单"
*/
