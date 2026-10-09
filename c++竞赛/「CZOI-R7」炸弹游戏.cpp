#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll m;
		cin>>m;
		if(m<=2){
			cout<<"Lose!\n";
			continue;
		}
		ll l=ceil(sqrtl(2*double(m)+0.25)+0.5);
		cout<<l<<" "<<2*m-2<<"\n";
	}
	return 0;
}

