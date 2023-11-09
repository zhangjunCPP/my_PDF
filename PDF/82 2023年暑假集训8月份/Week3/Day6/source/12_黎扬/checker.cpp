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
int main(){
	int t=100;
	while(t--){
		system(".exe > 1.txt");
		system(".exe < 1.txt > 11.txt");
		system(".exe < 1.txt > 111.txt");
		if(system("fc 11.txt 111.txt")){
			cout<<"WA!";
			return 0;
		}
		cout<<t<<":AC!\n";
	}
	return 0;
}

