#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int a[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	deque<int> q;
    cout<<"0\n";
	for(int i=1;i<n;i++){
		while(!q.empty()&&(i-k+1)>q.front()){
			q.pop_front();
		}
		while(!q.empty()&&a[i]<a[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		if(i>=1) cout<<a[q.front()]<<"\n";
	}
	return 0;
}

