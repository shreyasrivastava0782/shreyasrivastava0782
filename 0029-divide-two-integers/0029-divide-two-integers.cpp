class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        // Convert to long long to avoid overflow on abs()
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        long long quotient = 0, temp = 0;

        // Iterate from highest bit down to 0
        for (int i = 31; i >= 0; i--) {
            if (temp + (b << i) <= a) {
                temp += b << i;
                quotient |= 1LL << i;
            }
        }

        quotient = sign * quotient;

        // Clamp result into 32-bit int range
        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;
        return (int)quotient;
    }
};
