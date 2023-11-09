#include<bits/stdc++.h>
using namespace std;
int n,q;
int x,y,x2,y2; 
int main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin>>n>>q;
	while(q--){
		cin>>x>>y>>x2>>y2;
		int x3=n,y3=n-y,ans3=x+1;
		int x4=0,y4=n-y,ans4=n-x+1;
		int ans=abs(x-x2)+min(abs(y-y2),n+1-abs(y-y2));
		ans=min(ans,abs(x3-x2)+min(abs(y3-y2),n+1-abs(y3-y2))+ans3);
		ans=min(ans,abs(x4-x2)+min(abs(y4-y2),n+1-abs(y4-y2))+ans4);
		cout<<ans<<endl;
	}
	return 0;
}
/*
麻烦的是可以斜着跳的部分。
但是很明显，没有傻子会跳两次斜着跳的。
跳自己那一列的斜着跳的最优。
那这道题就完了。 
*/ 
