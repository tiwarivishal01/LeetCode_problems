class FreqStack {
public:

    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>group;
    int maxfreq = 0;

    FreqStack() {
        
    }
    
    void push(int x) {
        freq[x]++;
        group[freq[x]].push(x);
        maxfreq = max(maxfreq,freq[x]);
        
    }
    
    int pop() {
        int x = group[maxfreq].top();
        group[maxfreq].pop();
        freq[x]--;
        if(group[maxfreq].empty()){
            maxfreq--;
        }
        return x;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */