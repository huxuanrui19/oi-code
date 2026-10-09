#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1e5+10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;ull k;
	cin>>n>>k;
	ull ans=k^(k>>1);
	while(n){
		if(ans&(1ull<<(n-1))) cout<<1;
        else cout<<0;
		n--;
	}
	return 0;
}
