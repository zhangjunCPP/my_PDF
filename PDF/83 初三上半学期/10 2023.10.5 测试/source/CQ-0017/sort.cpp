#include<bits/stdc++.h>
using namespace std;
int n,cnt;
vector<int>a;
unordered_map<int,int>mp;
void sort(vector<int>a){
	if(a.size()<=1)return ;
	int k=a[ceil((a.size()-1)/2)];
	vector<int>al,ar;
	for(int i=0;i<(int)a.size();i++){
		cnt++;
		if(a[i]<k)al.push_back(a[i]);
		if(a[i]>k)ar.push_back(a[i]);
	}
	sort(al);
	sort(ar);
}
int solve(int len){
	if(mp[len])return mp[len];
	if(len==1)return mp[len]=0;
	if(len==2)return mp[len]=2;
	if(len==3)return mp[len]=3;
	int l=(len-1)/2,r=len-1-l;
	return mp[len]=solve(l)+solve(r)+len;
}
int main(){//20
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d",&n);
	bool A=1;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		a.push_back(x);
		if(x!=i)
		A=0;
	}
	if(A){
		printf("%d",solve(a.size()));
		return 0;
	}
	sort(a);
	printf("%d",cnt);
	return 0;
}

