#include<cstdio>
#include<windows.h>
#include<ctime>
#include<random>
#include<tuple>
#include<algorithm>
std::mt19937 Rand(std::random_device{}());
constexpr int N=55;
signed main(){
	int T=10000;
	for(int C=1;C<=T;++C){
		std::FILE *fp=std::fopen("bar.in","w");
		static int d[N][N];
		static std::tuple<int,int,int> e[N*N];
		memset(d,-1,sizeof d);
		int n=50,m=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(i!=j&&Rand()&1) e[++m]={i,j,d[i][j]=Rand()%1000+1};
		std::shuffle(e+1,e+m+1,Rand);
		std::fprintf(fp,"%d %d %d\n",n,m,Rand()%m+1);
		for(int i=1;i<=m;++i) std::fprintf(fp,"%d %d %d\n",std::get<0>(e[i]),std::get<1>(e[i]),std::get<2>(e[i]));
		std::fclose(fp);
		long st=clock();
		system("bar.exe");
		long ed=clock();
		if(ed-st<1000) std::printf("OK: %ld !\n",ed-st);
		else std::printf("TLE: %ld !\n",ed-st),system("pause");
	}
	return 0;
}
