def solve():
    n = int(input())
    arr = list(map(int,input().split()))
    total = sum(arr)

    for i in range(n,0,-1):
        if total%i==0:
            sumBalance = total//i
            sumCurr = 0
            flag = True
            for j in range(n):
                sumCurr+=arr[j]
                if sumCurr>sumBalance:
                    flag=False
                    break
                elif sumCurr==sumBalance:
                    sumCurr=0
            if flag==True:
                print(n-i)
                return

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()