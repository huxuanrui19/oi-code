#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> board;
vector<bool> used;
int N;
vector<bool> is_prime;
int min_total = INT_MAX;
vector<vector<int>> best_board;

vector<bool> sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

void dfs(int i, int j, int sum_row, int sum_col) {
    if (i == N) {
        int total = sum_row + sum_col - board[0][0];
        if (total < min_total) {
            min_total = total;
            best_board = board;
        }
        return;
    }

    for (int num = 1; num <= N * N; ++num) {
        if (used[num]) continue;

        bool valid = true;
        if (j > 0) {
            int left = board[i][j - 1];
            if (!is_prime[left + num]) {
                valid = false;
            }
        }
        if (i > 0) {
            int up = board[i - 1][j];
            if (!is_prime[up + num]) {
                valid = false;
            }
        }
        if (!valid) continue;

        int new_sum_row = sum_row;
        int new_sum_col = sum_col;
        bool is_first_row = (i == 0);
        bool is_first_col = (j == 0);

        if (is_first_row) new_sum_row += num;
        if (is_first_col) new_sum_col += num;

        int current_total = new_sum_row + new_sum_col;
        if (i == 0 && j == 0) {
            current_total -= num;
        }

        if (current_total >= min_total) {
            continue;
        }

        used[num] = true;
        board[i][j] = num;

        int next_i = i, next_j = j + 1;
        if (next_j == N) {
            next_i++;
            next_j = 0;
        }

        dfs(next_i, next_j, new_sum_row, new_sum_col);

        used[num] = false;
        board[i][j] = 0;
    }
}

int main() {
    cin >> N;
    if (N == 1) {
        cout << "NO" << endl;
        return 0;
    }

    int max_prime = 2 * N * N;
    is_prime = sieve(max_prime);

    board.resize(N, vector<int>(N, 0));
    used.resize(N * N + 1, false);

    dfs(0, 0, 0, 0);

    if (min_total == INT_MAX) {
        cout << "NO" << endl;
    } else {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << best_board[i][j];
                if (j != N - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
