class Solution {
public:
   int firstUniqChar(string s) {
    unordered_map<char, int> freq;
    queue<int> q;  // store indices

    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        freq[c]++;
        q.push(i);

        while(!q.empty() && freq[s[q.front()]] > 1) {
            q.pop();
        }
    }

    return q.empty() ? -1 : q.front();
}
};