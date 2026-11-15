include <bits/stdc++.h>
using namespace std;
int main() {
 int n;
 long long L;
 scanf("%d %lld", &n, &L);
 vector<long long> a(n + 2, 0);
 for (int i = 1; i <= n; i++) {
 scanf("%lld", &a[i]);
 }
 // last[j] 表示: 从第 j 件开始装箱, 第一个背包能装到第几件
 // 右端点 r 只会往右走, 不会回头, 所以总共只移动 n 次
 vector<int> last(n + 2, 0);
 int r = 0;
 long long sum = 0; // 当前这段 a[j] + a[j+1] + ... + a[r] 的和
 for (int j = 1; j <= n; j++) {
 while (r + 1 <= n && sum + a[r + 1] <= L) {
 r++;
 sum += a[r];