#include <stdio.h>

/*
int trap(int* height, int heightSize) { //前缀和做法，时间/空间复杂度均为为O(n)
    int left[heightSize], right[heightSize];
    left[0] = height[0];
    for (int i = 1; i < heightSize; i++){
        left[i] = height[i] > left[i-1]? height[i]: left[i-1];
    }
    right[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; i--){
        right[i] = height[i] > right[i+1]? height[i]: right[i+1];
    }    
    int ans = 0;
    for (int i = 0; i < heightSize; i++){
        ans += (left[i] < right[i]? left[i]: right[i]) - height[i];
    }
    return ans;
} */

int trap(int* height, int heightSize) {
    int left = 0, right = heightSize - 1, leftMax = 0, rightMax = 0, ans = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                ans += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                ans += rightMax - height[right];
            right--;
        }
    }
    return ans;
}

int main() {
    int h1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printf("%d\n", trap(h1, 12));

    int h2[] = {4, 2, 0, 3, 2, 5};
    printf("%d\n", trap(h2, 6));

    return 0;
}