#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,id;
	cin>>t>>id;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int flag=0;
        sort(a+1,a+n+1);
		for(int i=2;i<=n-2;i++){
			int tar=a[1]+a[n]-a[i];
			if(binary_search(a+i+1,a+n,tar)){
				flag=1;
				break;
			}
		}
		if(flag==1) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
