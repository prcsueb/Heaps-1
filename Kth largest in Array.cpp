/*
**Time Complexity (TC):** O(N) on average, O(N^2) in the worst case

**Space Complexity (SC):** O(log N) on average, O(N) in the worst case

Where:
- `N` is the number of elements in the `nums` array.
*/

class Solution {
public:
    int quickSelect(vector<int>& nums, int k, int l, int r) {
        int pivot = nums[r];
        int p = l;
        for(int i=l;i<r;i++) {
            if(nums[i] <= pivot) {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[r]);
        if(p > k) {
            return quickSelect(nums, k, l, p-1);
        } else if(p < k) {
            return quickSelect(nums, k, p+1, r);
        } else {
            return nums[p];
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, nums.size()-k, 0, nums.size()-1);
    }
};