class Solution {
    var ret:[Int] = []
    var visited:[Int] = []
    var hasCircle = false
    
    
    func findOrder(_ numCourses: Int, _ prerequisites: [[Int]]) -> [Int] {
        var graph:[[Int]] = Array(repeating: [], count: numCourses)
        visited = Array(repeating: 0, count: numCourses)
        
        for pre in prerequisites {
            graph[pre[1]].append(pre[0])
        }
        
        for node in 0..<numCourses {
            if visited[node] == 0 {
                visit(graph, node)
            }
        }
        
        return hasCircle ? [] : ret.reversed()
    }
    
    func visit(_ graph: [[Int]], _ node: Int) {
        visited[node] = 1
        for adj in graph[node] {
            if visited[adj] == 1 {
                hasCircle = true
                break;
            } else if visited[adj] == 0 {
                visit(graph, adj)
            }
        }
        visited[node] = 2
        ret.append(node)
    }
}