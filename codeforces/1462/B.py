import re

def solve():
    n = int(input())
    s = '.'
    s += input()

    if (len(s)<5):
        print("NO")
        return

    if s[1]=='2' and s[2]=='0' and s[3]=='2' and s[4]=='0':
        print("YES")
        return
    if s[1]=='2' and s[2]=='0' and s[3]=='2' and s[n]=='0':
        print("YES")
        return
    if s[1] == '2' and s[2] == '0' and s[n-1] == '2' and s[n] == '0':
        print("YES")
        return
    if s[1] == '2' and s[n-2] == '0' and s[n-1] == '2' and s[n] == '0':
        print("YES")
        return
    if s[n-3] == '2' and s[n-2] == '0' and s[n-1] == '2' and s[n] == '0':
        print("YES")
        return

    print("NO")

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()