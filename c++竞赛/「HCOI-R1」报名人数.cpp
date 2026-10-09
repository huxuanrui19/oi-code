#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[10]={6,2,5,5,4,5,6,3,7,6};
bool check(ll x){
    while(x%10==9){
        x/=10;
    }
    return x%10==2;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll l,r;
	cin>>l>>r;
	if(r-l>=10){
		cout<<"2";
	}
	else{
		for(ll i=l;i<r;i++){
			if((i/10==(i+1)/10&&i%10==2)||(i/10==(i+1)/10-1&&i%10==9&&check(i))){
				cout<<"2";
				return 0;
			}
		}
		cout<<"1";
	}
	return 0;
}
