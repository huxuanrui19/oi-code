#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    multiset<int> nums;
    unordered_map<int, int> freq;
    int unique_count = 0;
    
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        nums.insert(num);
        if (freq[num] == 0) {
            unique_count++;
        }
        freq[num]++;
    }
    
    int count = 0;
    
    while (unique_count >= 3) {
        // Step 1: adjust smallest
        auto it_min1 = nums.begin();
        int min1 = *it_min1;
        auto it_min2 = next(it_min1);
        int min2 = *it_min2;
        
        nums.erase(it_min1);
        freq[min1]--;
        if (freq[min1] == 0) {
            unique_count--;
        }
        
        nums.insert(min2);
        if (freq[min2] == 0) {
            unique_count++;
        }
        freq[min2]++;
        
        count++;
        
        if (unique_count < 3) break;
        
        // Step 2: adjust largest
        auto it_max1 = prev(nums.end());
        int max1 = *it_max1;
        auto it_max2 = prev(it_max1);
        int max2 = *it_max2;
        
        nums.erase(it_max1);
        freq[max1]--;
        if (freq[max1] == 0) {
            unique_count--;
        }
        
        nums.insert(max2);
        if (freq[max2] == 0) {
            unique_count++;
        }
        freq[max2]++;
        
        count++;
    }
    
    cout << count << " " << *nums.begin() << " " << *nums.rbegin() << endl;
    
    return 0;
}
