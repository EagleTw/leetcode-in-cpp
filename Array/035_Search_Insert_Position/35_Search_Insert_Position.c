int searchInsert(int* nums, int numsSize, int target){
    /* using divide and conquer */
    int lo = 0;
    int hi = numsSize - 1;

    while(hi >= lo) {
        int mid = (hi + lo) / 2;
        if (nums[mid] == target) return mid;
        else if(nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}
