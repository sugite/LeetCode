class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() > 12 || s.size() < 4)
             return res;
        for (int i=1; i<4; i++) {
            string first = s.substr(0, i);
            if (!isValid(first))
                continue;
            for (int j=1; i+j < s.size() && j<4; j++) {
                string second = s.substr(i, j);
                if (!isValid(second))
                    continue;
                for (int k=1; i+j+k < s.size() && k<4; k++) {
                    string third = s.substr(i+j, k);
                    string fourth = s.substr(i+j+k);
                    if (isValid(third) && isValid(fourth)) {
                        string temp = first+"."+second+"."+third+"."+fourth;
                        res.push_back(temp);
                    }
                }
            }
        }
    
        return res;
    }

    bool isValid(string s) {
        if (s.size() > 1 && s[0] == '0')
            return false;
        if (stoi(s) <= 255 && stoi(s) >= 0)
            return true;
        else
            return false;
    }
};
