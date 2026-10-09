#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long double a=sqrt(5)+1,fac=1.0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1;i<=6;i++){
		fac*=a;
	}
	cout<<floor(fac);
	return 0;
}

