#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> left_max(n, -1), right_max(n, n);
    stack<int> st;

    // 计算每个元素左边第一个比它大的位置
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            left_max[i] = st.top();
        }
        st.push(i);
    }

    st = stack<int>(); // 清空栈

    // 计算每个元素右边第一个比它大的位置
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] < a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            right_max[i] = st.top();
        }
        st.push(i);
    }

    vector<int> left_min(n, -1), right_min(n, n);

    // 计算每个元素左边第一个比它小的位置
    st = stack<int>();
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            left_min[i] = st.top();
        }
        st.push(i);
    }

    st = stack<int>();

    // 计算每个元素右边第一个比它小的位置
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] > a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            right_min[i] = st.top();
        }
        st.push(i);
    }

    long long max_sum = 0, min_sum = 0;
    for (int i = 0; i < n; ++i) {
        max_sum += static_cast<long long>(a[i]) * (i - left_max[i]) * (right_max[i] - i);
        min_sum += static_cast<long long>(a[i]) * (i - left_min[i]) * (right_min[i] - i);
    }

    cout << (max_sum - min_sum) << endl;

    return 0;
}
