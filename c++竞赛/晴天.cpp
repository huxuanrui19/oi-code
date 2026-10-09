#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;
		if(n==1&&x==0&&y==0) cout<<"0\n";
		else if((x+y+2)>n) cout<<"-2\n";
		else{
			for(int i=1;i<=x-1;i++){
				cout<<i%2<<" ";
			}
			if(x==0) cout<<"0 ";
			else cout<<"1 0 ";
			for(int i=1;i<=n-x-y-2;i++){
				cout<<"0 ";
			}
			for(int i=1;i<=y+1;i++){
				cout<<i%2-1<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}

