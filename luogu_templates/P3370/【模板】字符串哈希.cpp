#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e4+10;
static const ull base=131;
static const ull mod=1e9+7;
ull get_hash(string s){
	ull hash=0;
	for(int i=0;i<s.size();i++){
		hash=(hash*base+(ull)(s[i]))%mod;
	}
	return hash;
}
ull a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		a[i]=get_hash(s);
	}
	sort(a+1,a+n+1);
	cout<<(int)(unique(a+1,a+n+1)-a-1);
	return 0;
}

