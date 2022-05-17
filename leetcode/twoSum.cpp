#include <algorithm>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


/* O(n^2) */
class Solution1 {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); j++) {
                if ((nums[i] + nums[j]) == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

/* O(n) */
class Solution2 {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            int b = nums[i], a = target - b;
            if (seen.count(a)) return {seen[a], i}; // Found pair of (a, b), so that a + b = target
            seen[b] = i;
        }
        return {};
    }
};


int main() {
    return 1;
}

