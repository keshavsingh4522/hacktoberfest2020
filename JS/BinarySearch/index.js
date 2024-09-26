/**
 * A simple Binary Search for searching desired number
 *
 * @param {Number[]} nums - List of number
 * @param {Number} target - The desired number to search
 * @return {Number} The index of the number, -1 if not found
 */
export const binarySearch = (nums, target) => {
  let left = 0;
  let right = nums.length - 1;

  while (left <= right) {
    const mid = parseInt(String(left + (right - left) / 2));
    if (nums[mid] === target) return mid;
    if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
  }

  return -1;
};
