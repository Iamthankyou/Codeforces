import collections
def solve():
    n = int(input())
    arr = list(map(int,input().split()))

    cnt = [0]*200005

    for i in range(len(arr)):
        cnt[arr[i]]+=1

    ans = 0

    for i in range(200000):
        ans+=(cnt[i]-1)*(cnt[i]-2)*cnt[i]//6

    for i in range(200000):
        ans+=cnt[i]*cnt[i+1]*cnt[i+2]

    for i in range(200000):
        ans+=cnt[i]*(cnt[i+1]-1)*cnt[i+1]//2

    for i in range(200000):
        ans+=(cnt[i]-1)*cnt[i]//2*cnt[i+1]

    for i in range(200000):
        ans+=cnt[i]*(cnt[i+2]-1)*cnt[i+2]//2

    for i in range(200000):
        ans+=(cnt[i]-1)*cnt[i]//2*cnt[i+2]

    print(ans)

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()