/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        map<int,UndirectedGraphNode*> m;
        if(!node) return NULL;
        return dfs(node,m);
    }

    UndirectedGraphNode* dfs(UndirectedGraphNode *node, map<int,UndirectedGraphNode*>& m)
    {
        UndirectedGraphNode *p = new UndirectedGraphNode(node->label);
        m[node->label] = p;
        for(int i = 0 ; i < (node->neighbors).size() ; ++i)
        {
            UndirectedGraphNode *tmp = (node->neighbors)[i] ;
            if(m.count(tmp->label)>0)
                (p->neighbors).push_back(m[tmp->label]);
            else
                (p->neighbors).push_back(dfs(tmp,m));
        }
        return p;
    }
};