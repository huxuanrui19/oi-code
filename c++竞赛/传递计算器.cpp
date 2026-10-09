#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll x,cnt=0,times=0;
	cin>>x;
	while(cnt%10!=3){
		cnt=cnt+x;
		times++;
		if(cnt%10==3) break;
		if(x%2==0){
			x=x/2;
		}
		else{
			x=x*3+1;
		}
	}
	cout<<times;
	return 0;
}

