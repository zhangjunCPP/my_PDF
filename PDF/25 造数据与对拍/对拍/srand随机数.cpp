    #include <cstdio>
    #include <cstdlib>
    #include <ctime>
    int main() {
        int a;
        srand((unsigned)time(NULL));
        a = rand()%2000+1000;
        printf("%d\n", a);
        return 0;
    }

