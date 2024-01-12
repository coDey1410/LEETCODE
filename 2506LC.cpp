class Solution {
public:
int pair(string a,string b){
    unordered_set<char>v_a;
    unordered_set<char>v_b;
        for(auto c:a)
        v_a.insert(c);
        for(auto c:b)
        v_b.insert(c);
        if(v_a.size()!=v_b.size())
        return 0;

        for(auto c:b)
        {
            if(v_a.count(c)<=0)
            return 0;
        }
        return 1;
}
    int similarPairs(vector<string>& words) {
         int cnt=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                cnt+=pair(words[i],words[j]);
            }
        }
        return cnt;
    }
};