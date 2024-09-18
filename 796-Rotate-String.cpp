class Solution {
public:
    bool rotateString(string s, string goal) {
        queue<char> q1,q2;
        for(int i=0;i<s.size();i++){
            q1.push(s[i]);
        }

        for(int i=0;i<goal.size();i++){
            q2.push(goal[i]);
        }
        int k = s.size();
        while(k !=0){
            int var = q1.front();
            q1.pop();
            q1.push(var);
            if(q1 == q2) return true;
            k--;
        }
        return false;

        
    }
};