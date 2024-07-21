/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
  // remove 0s from nums1
  nums1.splice(m);

  if (nums1.length === 0) {
    nums2.forEach(nums2El => nums1.push(nums2El));
    console.log("nums1 is now:");
    console.log(nums1);
    return;
  }

  for (let x = 0, y = 0; y < n;) {
    if (nums1[x] === undefined) {
      nums1.splice(x, 0, nums2[y]);
      y++;
      continue;
    }

    if (nums1[x] < nums2[y]) {
      while (nums1[x] !== undefined && nums1[x] < nums2[y]) {
        x++;
      }
      nums1.splice(x, 0, nums2[y]);
      x++;
      y++;
    } else if (nums1[x] > nums2[y]) {
      nums1.splice(x, 0, nums2[y]);
      x++;
      y++;
    } else { // nums1[x] == nums2[y]
      nums1.splice(x, 0, nums2[y]);
      x++;
      y++;
    }
  }

  console.log("nums1 is now:");
  console.log(nums1);
};
