#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(){
	int n;
	cin>>n;
	ull k;
	cin>>k;
	k=k^(k>>1);
	while(n){
		cout<<((k>>(n-1))&1);
		n--;
	}
	return 0;
} 
