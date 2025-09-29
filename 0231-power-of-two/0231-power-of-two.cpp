class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;              // powers of two are positive
        return (n & (n - 1)) == 0;             // only one bit set
    }
};
