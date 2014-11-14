class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        map<string, int> word; 
        map<string, int> curStr;
        vector<int> ret;
        int N = L.size();
        if(N <= 0) return ret;
        for(int i = 0; i < L.size(); i++)
            ++word[L[i]];
        int M = L[0].size();
        if(N*M>S.size()) return ret;
        int i, j;
        for(i = 0 ; i <= S.size() - N * M; i++) 
        {
            curStr.clear();
            for(j = 0; j < N; j++)
            {
                string t = S.substr(i + j * M, M);
                if(word.find(t) == word.end()) break;
                if(++curStr[t] > word[t]) break;
            }
            if(j == N) ret.push_back(i);
        }
        return ret;
    }
};
