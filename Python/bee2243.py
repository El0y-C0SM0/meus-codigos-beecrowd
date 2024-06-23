def main():
    n = int(input())
    nums = [int(x) for x in input().split()]
    nums.insert(0, 0)
    nums.append(0)

    for i in range(1, n):
        if nums[i] > nums[i - 1]:
            nums[i] = nums[i - 1] + 1

    for i in range(n, 0, -1):
        if nums[i] > nums[i + 1]:
            nums[i] = nums[i + 1] + 1

    print(max(nums))

if __name__ == '__main__':
    main()