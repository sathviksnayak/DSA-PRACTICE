class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string curr = "";
        
        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                
                if (curr == "" || curr == ".") {
                  
                }
                else if (curr == "..") {
                    if (!stack.empty()) stack.pop_back();
                }
                else {
                    stack.push_back(curr);
                }
                
                curr = "";
            } else {
                curr += path[i];
            }
        }
        
        string ans = "/";
        for (int i = 0; i < stack.size(); i++) {
            ans += stack[i];
            if (i != stack.size() - 1) ans += "/";
        }
        
        return ans;
    }
};