class Solution(object):
    def intersection(self, nums1, nums2):
        result = []
        for i in nums1:
            if i in nums2 and i not in result:
                result.append(i)

        return result

    def intersection2(self, nums1, nums2):
        # return list(set(nums1) & set(nums2))
        # return list(set(nums1).intersection(nums2))
        # return nums1 or nums2
        result = []
        for i in nums1:
            if i in nums2:
                nums2.remove(i)
                result.append(i)

        return result

if __name__ == '__main__':
    s = Solution()
    print s.intersection2([1, 2, 2, 1], [2])