class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
       // vector<int> temp;
       int count=0;
        int j =0;
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                //temp.push_back(nums[i]);
                nums[j] = nums[i];
                j++;
                count++;
            
            }
        }
        for(int i=count;i<n;i++){
            if(nums[i] != 0) nums[i] = 0;
            //else nums[i] = 0;
        }
        
    }
};