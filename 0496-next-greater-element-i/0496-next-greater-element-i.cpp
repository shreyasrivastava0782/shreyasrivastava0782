class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
    int m=nums2.size();

    unordered_map<int,int>mpp;

    for(int i=0;i<m;i++){
        mpp[nums2[i]]=i;
    }

    vector<int>ans;
    int nextgreater;

    for(int i=0;i<n;i++){
            int startIdx=mpp[nums1[i]];
            nextgreater=-1;

            for(int j=startIdx+1;j<m;j++){
                if(nums2[j]>nums1[i]){
                    nextgreater=nums2[j];
                    break;
                }
            }
        
        ans.push_back(nextgreater);
    }
    return ans;

    }
};