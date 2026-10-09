#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll a;
		cin>>a;
		ll tmp=a,p=0;
		while(tmp%2==0){
			p++;
			tmp/=2;
		}
		cout<<int(pow(2,p))<<" "<<int(pow(2,p+1))<<" "<<int(pow(2,p+1)+a)<<'\n';
	} 
	return 0;
}

