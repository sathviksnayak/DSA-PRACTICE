class Solution {
public:
    int minPartitions(string n) {
         char x=*max_element(n.begin(),n.end());
         return x-'0';
  

    }
};