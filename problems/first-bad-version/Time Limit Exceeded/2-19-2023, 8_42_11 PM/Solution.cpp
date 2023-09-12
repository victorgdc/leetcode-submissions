// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(long int n) {
        long int k = 0;
        long int p = n;
        while (p > 0) {
            while (!isBadVersion(k+p)) {
                k += p;
            } 
            p /= 2;
        }
        return k+1;
    }
};