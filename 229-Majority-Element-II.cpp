class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            int cnt =0;
        
            if( ans.size() == 0 || nums[i] != ans[0]){
                for(int j=0;j<n;j++){
                    if(nums[i] == nums[j]){
                        cnt++;
                    }
                    cout<<cnt<<\ \<<endl;

                }
                if(cnt > (n/3)){
                ans.push_back(nums[i]);
                }
            }
            if(ans.size()==2) break;

        }
        return ans;
        
    }
};