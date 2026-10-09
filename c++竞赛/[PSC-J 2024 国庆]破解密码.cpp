#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	int n,t=0;
	cin>>n;
	for(int i=0;i<s.size();i++){
		char ch=min(int(s[i]+n+t),int('z'));
		if(s[i]+t<ch) n-=ch-(s[i]+t);
		t=ch-s[i];
		s[i]=ch;
	}
	cout<<s;
	return 0;
}
