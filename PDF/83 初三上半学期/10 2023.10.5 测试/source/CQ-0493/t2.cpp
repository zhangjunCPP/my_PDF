#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
int q[110];
int DO(int x){
	vector<int>a;for(int i=1;i<=x;i++)a.push_back(i);
	int now=0;
	while(a.size()>1){
		vector<int>b;
		for(int i=0;i<(int)a.size();i++,now^=1)if(!now)b.push_back(a[i]);
		a=b;
	}
	return a[0];
}
void sc(int x){
	for(int i=7;i>=0;i--)if(x&(1<<i))cout<<1;else cout<<0;
}
int vis[100];
int main(){
	//freopen("diary.in","r",stdin);
	//freopen("diary.out","w",stdout);
	
	for(int i=1;i<=100;i++){
		int x=DO(i);
		if(x==i)q[i]=i;else q[i]=q[x];
		vis[q[i]]
		//cout<<i<<" "<<q[i]<<"\n";
	}
	return 0;
}
