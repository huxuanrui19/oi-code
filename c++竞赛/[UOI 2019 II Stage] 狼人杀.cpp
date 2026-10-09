#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e5+10;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ld n,a,b;
	cin>>n>>a>>b;
	if(b==0){
		cout<<(ll)ceil(n/a);
		return 0;
	}
	ld del=n/b+((b-a)/(2*b))*((b-a)/(2*b));
	ld num=(b-a)/(2*b);
	cout<<(ll)ceil(num+sqrtl(del));
	return 0;
}

