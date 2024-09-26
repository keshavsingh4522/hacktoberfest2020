import { binarySearch } from "./index";

describe("JS > Binary Search", () => {
  const nums = [1, 3, 5, 8, 10, 25];
  it("Should return the index of the desired number", () => {
    expect(binarySearch(nums.slice(), 1)).toBe(0);
    expect(binarySearch(nums.slice(), 3)).toBe(1);
    expect(binarySearch(nums.slice(), 8)).toBe(3);
    expect(binarySearch(nums.slice(), 25)).toBe(5);
  });

  it("Should return -1", () => {
    expect(binarySearch(nums.slice(), 2)).toBe(-1);
    expect(binarySearch(nums.slice(), 20)).toBe(-1);
    expect(binarySearch(nums.slice(), 11)).toBe(-1);
  });
});
