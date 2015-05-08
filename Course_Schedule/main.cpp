class Vertex{
public:
    Vertex(int i):color(0),value(i){}
    int color ;
    int value ;
    vector<Vertex*> nextList ;
};

class Solution {
public:
    vector<Vertex*> vertex_set;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0 ; i < numCourses ; ++i)
            vertex_set.push_back(new Vertex(i));
        for(int i = 0 ; i < prerequisites.size() ; ++i){
            vertex_set[prerequisites[i][1]]->nextList.push_back(vertex_set[prerequisites[i][0]]);
        }
        for(int i = 0 ; i < numCourses ; ++i){
            if(vertex_set[i]->color == 0)
                if(!DFS_VISIT(i)) return false;
        }
        return true;
    }
    
    bool DFS_VISIT(int i)
    {
        vertex_set[i]->color = 1;
		for(int j = 0 ; j < vertex_set[i]->nextList.size() ; ++j){
            if(vertex_set[vertex_set[i]->nextList[j]->value]->color == 1) return false;
			else if(vertex_set[vertex_set[i]->nextList[j]->value]->color == 0) 
				if(!DFS_VISIT(vertex_set[i]->nextList[j]->value)) return false;
        }
        vertex_set[i]->color = 2;
        return true;
    }
};