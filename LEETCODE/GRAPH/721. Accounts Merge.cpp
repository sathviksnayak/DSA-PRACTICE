class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            parent[rx] = ry;
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        unordered_map<string, int> emailToAccount; 
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToAccount.find(email) != emailToAccount.end()) {
                    unite(i, emailToAccount[email]);
                } else {
                    emailToAccount[email] = i;
                }
            }
        }
        
       
        unordered_map<int, set<string>> rootToEmails;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            for (int j = 1; j < accounts[i].size(); j++) {
                rootToEmails[root].insert(accounts[i][j]);
            }
        }
        
        vector<vector<string>> result;
        for (auto& [root, emailSet] : rootToEmails) {
            vector<string> mergedAccount;
            mergedAccount.push_back(accounts[root][0]);
            for (string email : emailSet) { 
                mergedAccount.push_back(email);
            }
            result.push_back(mergedAccount);
        }
        
        return result;
    }
};