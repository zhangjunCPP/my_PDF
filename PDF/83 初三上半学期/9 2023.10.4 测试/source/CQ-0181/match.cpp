/*
对于每一个i 
若有 a_i!=b_i &&a_j!=b_j
且 j-i>=k 那么这个就不是模糊匹配。 
*/
#include<bits/stdc++.h>
#define PUT putchar('\n')
using namespace std;
inline int rd(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0'); 
}
inline void FRE(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}
int k,q;
string a,b; 
int n1,n2;
inline bool check(int id){
	int ptr=id+n2;
	for(int i=id;i<ptr;++i){
		if(a[i]!=b[i-id]){
			for(int j=i+k;j<ptr;++j){
				if(a[j]!=b[j-id])return 0;
			}
		}
	}
	return 1;
} 
int main(){
	FRE();
	k=rd();
	cin>>a;
	n1=a.size();
	q=rd();
	while(q--){
		cin>>b;
		n2=b.size();
		int sum=0;
		if(n2>n1){
			wr(sum);PUT;continue;
		}
		for(int i=0;i<=n1-n2;++i){
			sum+=check(i);
		}
		wr(sum);PUT;
	}
	return 0;
}
