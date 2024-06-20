=begin
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
=end

# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)
    i = 0
    nums.each_with_index{|val,idx|
        if nums[idx] > nums[i]
            i = i + 1
            nums[i],nums[idx] = nums[idx],nums[i]
        end
    }
    if nums.length() == 0
        return 
    end
    return i+1
    
end
nums = [1,8,8,9,10,10,10]
puts(remove_duplicates(nums))
