//the code is from chenjh
#include<bits/stdc++.h>
using namespace std;
int cmpcnt=0;
vector<int> mysort(const vector<int>&a){
	if(a.size()<=1u) return a;
	int pivot=a[((a.size()+1)>>1)-1];
	vector<int> al,ag;al.clear(),ag.clear();
	for(const int x:a){
		++cmpcnt;
		if(x<pivot) al.emplace_back(x);
		if(x>pivot) ag.emplace_back(x);
	}
	al=mysort(al);
	al.emplace_back(pivot);
	vector<int> t=mysort(ag);
	for(const int x:t) al.emplace_back(x);
	return al;
}
int n;
vector<int> v;
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d",&n);
	v.resize(n);
	for(int&x:v) scanf("%d",&x);
	mysort(v);
	printf("%d\n",cmpcnt);
	return 0;
}

