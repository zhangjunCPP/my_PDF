#include<bits/stdc++.h>
using namespace std; 
int a,b; 
void Freopen(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d",&a,&b);
	--a,--b;
	while(a)printf("1");
	while(b)printf("0");
	return 0;
}

