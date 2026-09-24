class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(),deadends.end());
        if(st.count("0000")){
            return -1;
        }
        queue<string>q;
        unordered_set<string>visted;
        q.push("0000");
        visted.insert("0000");
        int moves = 0;


        while(!q.empty()){
            int size = q.size();
            while(size--){
                string current = q.front();
                q.pop();

                if(current == target){
                    return moves;
                }
                for(int i =0;i<4;i++){
                    char org = current[i];
                    //move up
                    int dig = current[i]-'0';
                    int up = (dig + 1) % 10;
                    current[i] = '0'+up;

                    if(!st.count(current) && !visted.count(current)){
                        visted.insert(current);
                        q.push(current);
                    }

                    //move down 
                    int down = (dig + 9) % 10;

                    current[i] = '0' + down;

                    if (!st.count(current) &&
                        !visted.count(current)) {

                        visted.insert(current);
                        q.push(current);
                    }

                    current[i] = org;
                    
                }
            }
            moves++;

        }
        return -1;
        
    }
};