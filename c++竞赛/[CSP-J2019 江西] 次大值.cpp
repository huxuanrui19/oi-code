#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,a[N]; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	int ma=a[n-1],se=a[n-2];
	if(n<=1){
		cout<<"-1";
		return 0;
	}
	se=max(se,a[n]%a[n-1]);
	cout<<se;
	return 0;
}

