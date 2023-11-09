#include <bits/stdc++.h>
using namespace std;
int a[10000001]={1,2,2,2,3};
int main()
{
	int k=2,n;
	n=5;
	int left = 0, right = n;
	while (left < right) {
	    int mid = left + (right - left) / 2;
	    if (a[mid] < k) {
	            left = mid + 1;
	    } 
	    else if (a[mid] > k) {
	        right = mid;
	    } 
	    else if (a[mid] == k) {
	        left = mid + 1;
	    }
	}
	if (right <= 0 || a[right-1] != k) {cout<<-1<<endl;return 0;}   
	cout<<right-1; 
   
    return 0;
}
