#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=7e5+5;
int n,a[N];
using ll=long long;
ll cnt;
void solve(int l,int r){
	if(r-l+1<=1)return;
	cnt+=r-l+1;
	int p=a[(l+r)>>1];
	vector<int> s1,s2;
	for(int i=l;i<=r;i++)if(a[i]<p)s1.push_back(a[i]);
	else if(a[i]>p)s2.push_back(a[i]);
	for(int i=l;i<l+s1.size();i++)a[i]=s1[i-l];
	for(int i=l+s1.size()+1;i<=r;i++)a[i]=s2[i-l-s1.size()-1];
	a[l+s1.size()]=p;
	solve(l,l+s1.size()-1);
	solve(l+s1.size()+1,r);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	solve(1,n);
	cout<<cnt<<endl;
//	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}
/*
5
4 3 5 1 2
*/
