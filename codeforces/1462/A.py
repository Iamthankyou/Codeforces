def solve():
    n = int(input())
    left = 0
    right = n-1
    a = list(map(int,input().split()))

    while (left<n or right>=0) and left<=right:
        if left==right:
            print(a[left],end='')
        else:
            if left<n:
                print(a[left],' ',end='')
            if right>=0:
                print(a[right],' ',end='')
        left+=1
        right-=1
    print()

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()
