class Solution {
public:
int count(string s)
{
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
            int c = 0;
            for (char ch : s) {
                if (vowels.count(ch) > 0) {
                    c++;
                }
            }
            
            return c;

}
    bool halvesAreAlike(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int n=s.size();
       string a=s.substr(0,n/2);
       string b=s.substr(n/2,n/2);

       return count(a)==count(b);

    }
};