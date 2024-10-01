def merge(nums1,nums2,m,n):
    for i in range(m-1,-1,-1):
        print(i,i+n)
        nums1[i],nums1[i+n]=nums1[i+n],nums1[i]
    print(nums1,nums2)
    i,j,val=n,0,0
    while i<m+n and j<n and val<m+n:
        print(i,j,val)
        if nums1[i]<nums2[j]:
            nums1[val]=nums1[i]
            i+=1
        else:
            nums1[val]=nums2[j]
            j+=1
        val+=1
    while i<m+n:
        nums1[val]=nums1[i]
        i+=1
        val+=1
    while j<n:
        nums1[val]=nums2[j]
        j+=1
        val+=1
    print(nums1)


merge([1,2,3,0,0,0],[2,5,6],3,3)
