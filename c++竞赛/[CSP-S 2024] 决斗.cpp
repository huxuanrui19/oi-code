#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[N],b[N]; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	int ans=0;
	for(int i=1;i<1e5+10;i++){
		ans=max(ans,b[i]);
	}
	cout<<ans;
	return 0;
}

