def swap(first, second):
  temp = first
  first = second
  second = temp

def InsertionSortAlph(nums):
  for i in range(1, len(nums)):
    for j in range(0, i):
      if(nums[j] > nums[i]):
        temp = nums[j]
        nums[j] = nums[i]
        nums[i] = temp
 
def InsertionSortBeta(nums):
  for i in range(1, len(nums)):
    key = nums[i]
    j = i - 1
    while j >= 0 and nums[j] > key:
      nums[j + 1] = nums[j]
      j -= 1

    nums[j + 1] = key


if __name__ == '__main__':
  nums = [4, 2, 6, 7, 3, 4]
  InsertionSortBeta(nums)
  print nums