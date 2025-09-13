class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        unordered_map<int,int>mpp;

        stack<int>s;

        for(int num:nums2){
            while(!s.empty() && num>s.top()){
                mpp[s.top()]=num;
                s.pop();
            }
            s.push(num);
        }
        while(!s.empty()){
            mpp[s.top()]=-1;
            s.pop();
        }

        vector<int>res;

        for(int num:nums1){
            res.push_back(mpp[num]);
        }

        return res;
    }
};