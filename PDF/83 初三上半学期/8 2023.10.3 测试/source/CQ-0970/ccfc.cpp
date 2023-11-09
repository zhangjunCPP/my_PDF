#include<bits/stdc++.h>
using namespace std;
string s;
int n;
bool Find(string st,string t){
	if(st.size()*3>=t.size()) return 0;
	if(st!=t.substr(0,st.size())
		||st!=t.substr(st.size(),st.size())
		||st!=t.substr(t.size()-st.size(),st.size())) return 0;
	return 1;
}
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		string t=s.substr(i,n-i);
		int m=t.size(),cnt=0;
		for(int j=1;j<=m;j++){
			string st=t.substr(0,j);
			if(Find(st,t)) cnt++;
		}
		printf("%d",cnt);
		if(i!=n-1) printf(" ");
	}
	return 0;
}

