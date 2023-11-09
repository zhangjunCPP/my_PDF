#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T=500;
	freopen("comments.txt","r",stdin);
	while(T--)
	{
		system("cls");
		printf("%d Tests Last...\n",T);
		system("data.exe>data.in");
		system("Î´ÃüÃû1.exe<data.in>src.out");
		system("SPJ.exe>comments.txt");
		char sit=getchar();
		if(sit=='J')T++;
		else if(sit=='W'){printf("Wrong Answer...");return 0;}
//		else printf("Accepted!");
	}
	printf("All completed!");
	return 0;
}
