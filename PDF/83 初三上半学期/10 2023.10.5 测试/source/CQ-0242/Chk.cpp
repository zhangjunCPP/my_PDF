#include<cstdio>
#include<random>
void make(){
    std::mt19937 Rand(std::random_device{}());
    int n=9;
    std::FILE *fp=std::fopen("Magic.in","w");
    std::fprintf(fp,"%d\n",n);
    int d=Rand()%n+1;
    for(int i=1;i<=n;++i){
        std::fprintf(fp,"%d %d 1\n",std::max(1,i-d+1),std::min(i+d-1,n));
    }
    // for(int i=1;i<=n;++i){
    //     int l=Rand()%i+1,r=Rand()%(n-i+1)+i;
    //     std::fprintf(fp,"%d %d %lld\n",l,r,/* (long long)(Rand()%10+1) */1ll);
    // }
    std::fclose(fp);
}
signed main(){
    for(int T=1;T<=1000;++T){
        make();
        std::system("./Copy < Magic.in > Copy.out");
        std::system("./Sub < Magic.in > Sub.out");
        if(std::system("diff Copy.out Sub.out")){
            std::printf("BuNiuBi");
            return 0;
        }
        else std::printf("NiuBi\n");
    }
    return 0;
}
/* 
4
3 4 1
2 3 4
1 2 2
2 2 6

3
1 1 1
2 3 8
2 2 3

2
2 2 2
1 1 10


 */