#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
struct node
{
	int data;
	int shun;
}a[N];
bool cmp(node x,node y){return x.data>y.data;}
int n;
int solve(int l,int r)
{
	if(l>r) return 0;
	if(l<1||r>n) return 0;
//	cout<<l<<" "<<r<<endl;
	int len=r-l+1,mid=(len+1)/2;
	if(len==1) return 0;
	if(len==2) return 2;
	int c;
	for(int i=l;i<=r;i++) if(a[i].shun==mid)//ÕÒµ½Õâ¸öË³Ğò 
	{
		c=i;
		break;
	}
//	cout<<c<<endl;
	return solve(l,c-1)+solve(c+1,r)+(r-l+1);
}
int main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].data),a[i].shun=i;
	sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;i++) cout<<a[i].data<<" ";cout<<endl;
//	for(int i=1;i<=n;i++) cout<<a[i].shun<<" ";cout<<endl;
	cout<<solve(1,n);
	return 0;
}
