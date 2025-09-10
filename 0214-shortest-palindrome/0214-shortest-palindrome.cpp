class Solution {
public:
    string shortestPalindrome(string s) {
        int size = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        // Create combined string for KMP
        string combined = s + "$" + rev;

        // Build LPS array
        int n = combined.size();
        vector<int> lps(n, 0);
        int pre = 0, suf = 1;

        while (suf < n) {
            if (combined[pre] == combined[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }

        
        int last = lps.back();

        
        string rem = s.substr(last);
        reverse(rem.begin(), rem.end());

        return rem + s; 
    }
};
