#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull N=3e5+5;
ull a[N];
int main()
{
	ull n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	vector<ull> left_max(n+5, 0), right_max(n+5, n+1),left_min(n+5, 0), right_min(n+5, n+1);
    stack<ull> st;
    for(int i=1;i<=n;i++){
    	while((!st.empty())&&a[st.top()]<=a[i]){
    		st.pop();
		}
		if(!st.empty()){
			left_max[i]=st.top();
		}
        st.push(i);
	}
	st = stack<ull>();
	for(int i=n;i>0;i--)
	{
		while((!st.empty())&&a[st.top()]<a[i]){
    		st.pop();
		}
		if(!st.empty()){
			right_max[i]=st.top();
		}
        st.push(i);
	}
	st = stack<ull>();
	for(int i=1;i<=n;i++){
		while((!st.empty())&&a[st.top()]>=a[i]){
			st.pop();
		}
		if(!st.empty()){
			left_min[i]=st.top();
		}
        st.push(i);
	}
	st = stack<ull>();
	for(int i=n;i>0;i--){
		while((!st.empty())&&a[st.top()]>a[i]){
			st.pop();
		}
		if(!st.empty()){
			right_min[i]=st.top();
		}
        st.push(i);
	}
	ull max_sum=0,min_sum=0;
	for(int i=1;i<=n;i++){
		max_sum+=a[i]*(right_max[i]-i)*(i-left_max[i]);
		min_sum+=a[i]*(right_min[i]-i)*(i-left_min[i]);
	}
	cout<<max_sum-min_sum;
	return 0;
}
