#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e2+10;
const ll mod=(1<<30);
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<"1\n";
	srand(0);
	int n=rand()%N+1;
	cout<<n<<"\n";
	for(int i=1;i<=n;i++){
		cout<<rand()%mod<<" ";
	}
	return 0;
}

