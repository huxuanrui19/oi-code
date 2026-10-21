#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll> p, q;
void pushPair(ll x, ll y) {
    if (x > p.top()) q.push(x); else p.push(x);
    if (y > p.top()) q.push(y); else p.push(y);
    while (p.size() > q.size() + 1) q.push(p.top()), p.pop();
    while (p.size() < q.size() + 1) p.push(q.top()), q.pop();
}
int main(){
    p.push(8);
    pushPair(7,8);
    printf("pre[3]=%lld (want 8)\n", p.top());
    return 0;
}
