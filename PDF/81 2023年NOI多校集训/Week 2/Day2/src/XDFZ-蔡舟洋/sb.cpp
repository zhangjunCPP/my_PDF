#include<bits/stdc++.h>
using namespace std;
long long f[17]={0,0,0,1,7,47,322,2404,19778,180130,1809632,19940552,239430724,3113226148};
int main(){
	long long jc=120;
	for(int i=6;i<=13;i++){
		jc=jc*i;
		printf("%.10lf\n",f[i]/1.0/jc);
	}
	return 0;
}

