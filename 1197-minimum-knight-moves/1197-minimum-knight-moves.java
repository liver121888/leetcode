class Solution {
    private Map<String, Integer> memo = new HashMap<>();

    private int dfs(int x, int y) {
        String key = x + "," + y;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        if (x + y == 0) {
            return 0;
        } else if (x + y == 2) {
            return 2;
        } else {
            // abs here: 我反向跳一步後，如果跳到負座標，不要真的去處理負座標，因為它跟對稱的正座標答案一樣。
            // Knight 的兩種反向選擇是：
            // (x - 1, y - 2)
            // (x - 2, y - 1)
            // 但有時候會「跳過原點」，導致座標變成負數，例如：
            // dfs(1, 0)
            // 反推：
            // option1 = dfs(abs(1 - 1), abs(0 - 2)); // dfs(0, 2)
            // option2 = dfs(abs(1 - 2), abs(0 - 1)); // dfs(1, 1)
            // 如果沒有 abs()，會變成：
            // dfs(0, -2)
            // dfs(-1, -1)
            // 但在 knight move 裡：
            // dist(0, -2) == dist(0, 2)
            // dist(-1, -1) == dist(1, 1)
            // 因為棋盤上下左右對稱，所以可以直接用 abs() 把它折回第一象限。
            Integer ret = Math.min(dfs(Math.abs(x - 1), Math.abs(y - 2)),
                    dfs(Math.abs(x - 2), Math.abs(y - 1))) + 1;
            memo.put(key, ret);
            return ret;
        }
    }

    public int minKnightMoves(int x, int y) {
        return dfs(Math.abs(x), Math.abs(y));
    }
}