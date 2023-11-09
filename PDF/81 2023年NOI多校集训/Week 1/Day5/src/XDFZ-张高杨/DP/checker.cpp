#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main()
{
	puts("NB");
	for(int i=1;;i++)
	{
		system("cls");
		printf("%d AC\n",i-1);
		system("data_maker.exe");
		system("cut.exe");
		system("BF.exe");
		if(system("fc cut.out cut.bf"))return 0;
	}
	return 0;
}
