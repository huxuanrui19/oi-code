#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	if(n>108||n%12||n<12) cout<<"404";
	else{
		cout<<n/12;
	}
	return 0;
}

