class Solution {

public:
    void reverse(vector<int> &nums,int start,int end){
        while(start < end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end]= temp;
        start++;
        end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int d = k % nums.size();

        reverse(nums , 0 , nums.size()-1);
        reverse(nums, 0 , d -1);
        reverse(nums , d , nums.size()-1);
        
    }
};