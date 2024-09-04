class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int lastPos = n-1;
        for(int i = n-1;i>=0;i--){
            if(i + nums[i] >= lastPos){
                lastPos = i;
            }
        }
        if(lastPos == 0){
            return true;
        }
        else{
            return false;
        }
    }
};