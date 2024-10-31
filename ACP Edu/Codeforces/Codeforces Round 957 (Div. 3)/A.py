TC = int(input())
for _ in range(TC):
    n, m, k = map(int, input().split())
    s = 'L' + input() + 'L'
    dp = [200001] * (n + 2)
    dp[0] = 0
    for i in range(n + 2):
        if(s[i] == 'C'):
            continue
        for j in range(i - 1, max(-1, i - m - 1), -1): 
            if(s[j] == 'L'):
                dp[i] = min(dp[i], dp[j])
        dp[i] = min(dp[i], dp[i - 1] + 1)
        # print(i, ':', dp[i])
    print('YES' if dp[n + 1] <= k else 'NO')
