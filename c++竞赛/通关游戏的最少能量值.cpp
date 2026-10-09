#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[int(1e5+10)];
bool cmp(pair<int,int> x,pair<int,int> y){
	int dx = x.first - x.second;
    int dy = y.first - y.second;
    if (dx != dy) {
        return dx > dy;
    }
    return x.first > y.first;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	sort(a+1,a+n+1,cmp);
	int ans=0,sum=0;
	for(int i=1;i<=n;i++){
		ans = max(ans,a[i].first + sum);
        sum += a[i].second;
	}
	cout<<ans;
	return 0;
} 
