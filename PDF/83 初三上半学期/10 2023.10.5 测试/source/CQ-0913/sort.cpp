#include<bits/stdc++.h>
using namespace std;
void Freopen(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
}
int n,cmpcnt;
void solve(vector<int> a){
	int len=a.size();
//	printf("a: ");
//	for(int i=0;i<len;i++) printf("%d ",a[i]);
//	printf("\n");
	if(len<=1) return ;
	int pivot=a[((len+1)>>1)-1];
//	printf("pivot: %d\n",pivot);
	vector<int> al,ar;
	for(int i=0;i<len;i++){
		cmpcnt++;
		if(a[i]<pivot) al.push_back(a[i]);
		if(a[i]>pivot) ar.push_back(a[i]);
	}
//	return solve(al)+a[(len+1)>>1]+solve(ar);
	solve(al); solve(ar);
	return ;
}
int main(){
	Freopen();
	vector<int> a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		a.push_back(x);
	} 
//	printf("A: ");
//	for(int i=0;i<(int)a.size();i++) printf("%d ",a[i]);
//	printf("\n");
//	int ans=solve(a);
	solve(a);
	printf("%d\n",cmpcnt);
	return 0;
} 
/*
5
4 3 5 1 2


*/
