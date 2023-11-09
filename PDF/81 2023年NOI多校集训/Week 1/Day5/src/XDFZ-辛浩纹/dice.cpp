#include<bits/stdc++.h>
using namespace std;
inline int read(){
    char ch=getchar();int sum=0,f=1;
    while(!isdigit(ch))f=(ch=='-')?-1:1,ch=getchar();
    while(isdigit(ch))sum=(sum<<1)+(sum<<3)+(ch^48),ch=getchar();
    return sum*f;
}
int n,k,a[104][7];
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	n=read();k=read();
	if(n==1){
		puts("Yes");
		for(int i=1;i<=6;++i)cout<<(k*i)<<" ";
	}
	else{
		cout<<"No";
	}
	return 0;
}
