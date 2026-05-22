class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int loop=0;
        for(int i=0;i<students.size();i++){
            q.push(i);
        }
        int i=0;
        while(!q.empty()){
            
            if(students[q.front()]==sandwiches[i]){
                i++;
                q.pop();
                loop=0;
            }
            else{
                q.push(q.front());
                q.pop();
                loop++;
                if(loop==q.size()) return q.size();
            }
        }
        return 0;
    }
};