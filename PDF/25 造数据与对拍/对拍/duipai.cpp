
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t=200;  //²âÊÔ´ÎÊý 
    while(1)
    {
    	t--;
        system("data.exe > data.txt");
        system("baoli.exe < data.txt > baoli.txt");
         system("std.exe < data.txt > std.txt");
        if(system("fc std.txt baoli.txt"))   break;
    }
    if(t==0) cout<<"no error"<<endl;
    else cout<<"error"<<endl;
    system("pause");
    return 0;
}
