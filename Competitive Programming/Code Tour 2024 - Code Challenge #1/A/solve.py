def main():
    K = int(input())
    p = input().split(' ')
    p = [int(x) for x in p]
    C = int(input())

    l = 0
    r = C + 1
    res = C
    while(l + 1 < r):
        m = l + (r - l + 1) // 2
        if(m * m * m == C):
            res = m
            break
        if(m * m * m < C):
            l = m
        else:
            r = m
    print(res)

if __name__ == "__main__":
    main()