#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
int p,s;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	p=read();
	s=read();
	if(s<p/2-1||s>(p/4)*ceil(1.0*p/4)||p&1){
		printf("Impossible");
		return 0;
	}
	if(p==4){
		printf("2333");
		return 0;
	}
	if(p==6){
		printf("232332");
		return 0;
	}
	int len=ceil(1.0*p/4);
	work(3);
	for(int i=1;i<len;i++){
		work(2);
	}
	work(1);
	len=p/4;
	for(int i=1;i<len;i++){
		work(2);
	} 
	len--;
	s-=p/2-1;
	int sum=0;
	work(1);
	sum++;
	while(s>=len){
		work(2);
		s-=len;
		sum++;
	}
	work(1);
	for(int i=1;i<len-s;i++){
		work(2);
	} 
	if(sum==ceil(1.0*p/4)){
		work(2);
		return 0;
	}
	work(3);
	sum++;
	if(s){
		work(1);
		for(int i=1;i<s;i++){
			work(2);
		}
		work(3);
		sum++;
	}
	for(int i=1;i<=ceil(1.0*p/4)-sum;i++){
		work(2);
	}
	work(1);
	return 0;
}
