def main():
    n = int(input())
    nums = [int(i) for i in input().split()]
    nums.sort(reverse=True)
    sum_nums = sum(nums)
    cont = 0

    for i in range(n):
        x = nums[i]
        sum_nums -= x
        if x < sum_nums:
            cont = n - i
            break

    print(cont)

if __name__ == '__main__':
    main()