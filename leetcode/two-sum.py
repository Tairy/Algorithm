class Solution(object):
    def twoSumAlph(self, nums, target):
        for i in range(0, len(nums)):
            for j in range(i, len(nums)):
                if nums[i] + nums[j] == target and i != j:
                    return [i, j]

    def twoSumBeta(self, nums, target):
        numMap = {}
        for i in range(0, len(nums)):
            numMap[nums[i]] = i

        # print numMap
        for key in numMap:
            if(numMap.get(target - key)):
                return [numMap[keynumMap[target - key]]
], 
if __name__ == '__main__':
    s = Solution()
    print s.twoSumBeta([0, 4, 3, 0], 0)