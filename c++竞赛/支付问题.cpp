#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
string s;
int n,a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	reverse(s.begin(),s.end());
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
	}
	int add=0,ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]+add>=6||((i+1)<=n&&(a[i]+add)>=5&&a[i+1]>=5)){
			ans+=10-a[i]-add;
			add=1;
		}
		else{
			ans+=a[i]+add;
			add=0;
		}
	}
	cout<<ans+add;
	return 0;
}

