// https://leetcode.com/problems/squares-of-a-sorted-array

#include <queue>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<int> pq;
        vector<int> result;
        int tam = nums.size();
        for (auto i: nums) {
            pq.push((-1) * i * i);
        }
        while (!pq.empty()) {
            result.push_back(pq.top() * (-1));
            pq.pop();
        }
        return result;
    }
};