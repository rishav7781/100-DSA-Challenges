//o(n log n) time | o(1) space

class Solution {

public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;  // quick check
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};

//o(n) time | o(1) space
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        for (char c : t) freq[c - 'a']--;
        
        for (int f : freq)
            if (f != 0) return false;
        
        return true;
    }
};

