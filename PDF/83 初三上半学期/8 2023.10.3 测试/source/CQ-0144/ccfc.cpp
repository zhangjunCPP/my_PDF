#include<bits/stdc++.h>
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
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
}
string ch;
int n;
int main(){
	FRE();
	cin>>ch;
	n=ch.size(); 
	for(int i=0;i<n;++i){
		int dd=(n-i+1)/3;
		if(dd*3==n-i)dd-=1;
		int sum=0;
		for(int j=1;j<=dd;++j){
			string s1;
			for(int s=i;s<=i+j-1;++s){
				s1+=ch[s];
			}
			string s2;
			for(int s=i+j;s<=i+j+j-1;++s){
				s2+=ch[s];
			}
			if(s1!=s2)continue;
			string s3;
			for(int s=n-j;s<n;++s){
				s3+=ch[s];
			}
			if(s2!=s3)continue;
			sum++;
		}
		wr(sum);putchar(' ');
	}
	return 0;
} 
