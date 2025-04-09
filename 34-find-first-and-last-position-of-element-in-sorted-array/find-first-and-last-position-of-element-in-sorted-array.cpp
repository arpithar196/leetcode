class Solution {
public:
    int binarySearch(int start,int end, int target, vector<int>& nums,bool findFirst){
        int result = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                result = mid; 
                if (findFirst) {
                    // Continue searching in the left half to find the first occurrence
                    end = mid - 1;
                } else {
                    // Continue searching in the right half to find the last occurrence
                    start = mid + 1;
                }
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=-1,right=-1;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target && left==-1){
        //         left=i;
        //     } else if(nums[i]==target){
        //         right=i;
        //     }
        // }
        left=binarySearch(0,nums.size()-1, target,nums, true);
        if(left!=-1)
            right=binarySearch(0,nums.size()-1,target,nums,false);
        vector<int> res;
        res.push_back(left);
        res.push_back(right);
        return res;
    }
};