function findMin(nums: number[]): number {
    let start = 0, end = nums.length -1;
    let mid = 0;
    while(start <= end){
        mid = Math.floor((start + end) / 2);
        if(nums[mid]>nums[nums.length-1]){
            start = mid+1;
        }
        else{
            end = mid -1;
        }
    }
    return nums[start];
};