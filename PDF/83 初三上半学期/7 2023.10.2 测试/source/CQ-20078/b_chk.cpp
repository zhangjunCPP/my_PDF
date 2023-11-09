#include<bits/stdc++.h>
void data_maker(){
	static std::mt19937 Rand(std::random_device{}());
	std::FILE *fp=std::fopen("b_d.in","w");
	int n=4;
	std::fprintf(fp,"%d\n",n);
	for(int i=1;i<=n;++i) std::fprintf(fp,"%d ",Rand()%100+1);
	std::fclose(fp);
}
signed main(){
	for(int T=1;T<=10000;++T){
		data_maker();
		system("b.exe < b_d.in > b.out");
		system("b_bf.exe < b_d.in > b_bf.out");
		if(system("fc b.out b_bf.out")){
			std::printf("WA!\n");
			system("pause");
			return 0;
		}
		std::printf("AC!\n");
	}
	return 0;
}
