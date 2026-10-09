#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int a[4];
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		sort(a,a+4);
		//int tmp=unique(a,a+4)-a;
		if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]) cout<<"Yes\n";
		else{
			if(a[0]==a[1]&&a[1]==a[2]&&a[2]!=a[3]) cout<<"No\n";
			else{
				if(a[0]==a[1]&&a[2]==a[3]&&a[2]!=a[1]) cout<<"Yes\n";
				else cout<<"No\n"; 
			}
		}
	}
	return 0;
}

