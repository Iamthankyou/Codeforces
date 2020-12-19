def solve():
    n = int(input())
    if n>45:
        print(-1)
        return
    ans = []
    i=9
    while n-i>=0 and i>0:
        n-=i
        ans.append(i)
        i-=1
    if n>0:
        ans.append(n)
    ans.sort()
    print("".join(str(x) for x in ans ))

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()