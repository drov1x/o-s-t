#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int j = 0;
    for (int i = 0; i < numsSize;){
        nums[j++] = nums[i++];
        while (i < numsSize && nums[i - 1] == nums[i])
            i++;
    }
    return j;
}

int main(){
    int numsSize = 10;
    int nums[] = {1, 1, 2, 3, 4, 4, 6, 7, 7, 7, 7};
    numsSize = removeDuplicates(nums, numsSize);
    printf("%d\n", numsSize);
    for (int i = 0; i < numsSize; i++)
        printf("%d ", nums[i]);
    return 0;
}