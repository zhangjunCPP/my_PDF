#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	string s;
	int k,q;
	cin>>k>>s>>q;
	int len=s.length();
	while(q--){
		string p;
		cin>>p;
		int siz=p.length();
		int ans=0;
		for(int i=0;i<len-siz+1;i++){
			int first=-1,end=-1;
			for(int j=0;j<siz;j++){
				if(s[i+j]!=p[j]) {
					first=j;
					break;
				}
			}
			if(first==-1) {ans++;continue;}
			for(int j=siz-1;j>=0;j--){
				if(s[i+j]!=p[j]) {
					end=j;
					break;
				}
			}
			if(end-first<k) ans++;
		}
		cout<<ans<<"\n";
	}
}