class Solution {
    func findSet(_ p: inout [Int], _ x: Int) -> Int{
        if (x != p[x]) {
            p[x] = findSet(&p, p[x]);
        }
        return p[x];
    }

    func union(_ p: inout [Int], _ x: Int, _ y: Int) {
        let px = findSet(&p, x);
        let py = findSet(&p, y);
        p[px] = py;
    }

    func numIslands(_ grid: [[Character]]) -> Int {
        let n = grid.count
        if n == 0 {
            return 0
        }
        let m = grid[0].count

        var p:[Int] = Array.init(repeating: 0, count: n * m)
        for (index, element) in p.enumerated() {
            p[index] = index
        }

        for (i, ele) in grid.enumerated() {
            for (j, e) in grid[i].enumerated() {
                if (j + 1 < m && grid[i][j] == grid[i][j + 1]) {
                    union(&p, i * m + j, i * m + j + 1);
                }
                if (i + 1 < n && grid[i][j] == grid[i + 1][j]) {
                    union(&p, i * m + j, (i + 1) * m + j);
                }
            }
        }

        var set = Set<Int>()
        for (i, element) in p.enumerated() {
            if (grid[i / m][i % m] == "1") {
                set.insert(findSet(&p, i));
            }
        }

        return set.count
    }
}