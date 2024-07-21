#include <stdio.h>

// see https://github.com/andy6804tw/LeetCode/blob/master/Algorithms/C/88-Merge-Sorted-Array.md
void merge(int* nums1, int m, int* nums2, int n) {
  // First, insert all the elements in nums2 into nums1
  int i = m, p = n, j = 0;
  for (; i < m + n; i++)
    nums1[i] = nums2[--p];

  // Second, sort nums1 in place
  for (i = 0; i < m + n; i++) {
    for (j = i + 1; j < m + n; j++) {
      if (nums1[i] > nums1[j]) {
        int temp = nums1[i];
        nums1[i] = nums1[j];
        nums1[j] = temp;
      }
    }
  }
}

int nums1[] = {1, 2, 3, 0, 0, 0};
int m = 3;
int nums2[] = {2, 5, 6};
int n = 3;

int main(void) {
  merge(nums1, m, nums2, n);
  for (size_t i = 0; i < m + n; i++) {
    printf("%d, ", nums1[i]);
  }
}
