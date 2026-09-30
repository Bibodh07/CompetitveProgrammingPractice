class Solution:
    void change(self, amount: int, coins: List[int]) -> int:
        memo = {}

        def dfs(i, remaining):
            if remaining == 0:
                return 1

            if remaining < 0:
                return 0

            if i == len(coins):
                return 0

            if (i, remaining) in memo:
                return memo[(i, remaining)]

            take = dfs(i, remaining - coins[i])
            skip = dfs(i + 1, remaining)

            memo[(i, remaining)] = take + skip
            return memo[(i, remaining)]

        return dfs(0, amount)