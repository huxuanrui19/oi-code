#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	if(n<=k){
		cout<<"0";
		return 0;
	}
	else{
		s=' '+s;
		int sum=0,l=0,r=0;
		for(int i=2;i<=n;i++){
			if(s[i]!=s[i-1]) sum++;
		}
        if(k<=sum) l=sum+1;
        else l=k+1;
        if(k<(n-sum-1)) r=sum+k+1;
        else r=n;
        cout<<r-l+1;
	}
	return 0;
}
