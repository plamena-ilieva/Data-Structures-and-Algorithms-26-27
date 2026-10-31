class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                right = mid;        // Minimum is at mid or to its left
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;     // Minimum is strictly to the right
            } else {
                --right;            // Duplicate; safely discard one element
            }
        }

        return nums[left];
    }
};
