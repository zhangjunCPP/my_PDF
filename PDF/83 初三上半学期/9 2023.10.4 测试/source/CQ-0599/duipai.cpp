#include <bits/stdc++.h>
using namespace std;
int main(){
	system("g++ data.cpp -lm -std=c++14 -O2 -o data.exe");
	system("g++ bftrans.cpp -lm -std=c++14 -O2 -o bftrans.exe");
	system("g++ trans.cpp -lm -std=c++14 -O2 -o trans.exe");
	for(int i=1;i<=100;i++) {
		cout<<i<<"\n"; 
		system("data.exe");
		
		puts("Finish data");
		system("bftrans.exe");
		puts("Finish bf");
		system("trans.exe");
		puts("Finish my");
		if(	system("fc trans.out bftrans.out")){
			puts("WA");
			return 0;
		}
	}
	puts("AC");
	system("start cmd");

}
