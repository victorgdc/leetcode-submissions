// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int target;
        
        if (n == 1) return 1;

        while (l < r)  {
            int m = (l+r)/2;
            if (isBadVersion(m)) {
                if (!isBadVersion(m-1)) {
                    target = m;
                    break;
                }
                else r = m;
            }
            else {
                l = m;
            }
        }
        return target;       
    }
};