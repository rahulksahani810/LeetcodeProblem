class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n=nums.size();
       vector<int> ans;
       int mm = (n/3)+1;
       map<int,int> mapp;
       for(int i=0;i<n;i++){
        mapp[nums[i]]++;
        if(mapp[nums[i]] == mm){
            ans.push_back(nums[i]);
        }

       }
       return ans;
        
    }
};