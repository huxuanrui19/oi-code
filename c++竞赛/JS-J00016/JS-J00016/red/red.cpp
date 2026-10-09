#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int main(){
	freopen("red.in","r",stdin);
	freopen("red.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		ll x,y;
		cin>>x>>y;
		if(x==y) cout<<"0\n";
		else if(x>y){
			if((x-y)%2==0){
				cout<<"1\n";
			}
			else cout<<"2\n";
		}
		else if(x<y){
			if((y-x)%2==1) cout<<"1\n";
			else{
				ll tmp=y-x;
				tmp/=2;
				if(tmp%2==0) cout<<"3\n";
				else cout<<"2\n"; 
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

