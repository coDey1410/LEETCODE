
class Solution {
public:
typedef stringstream ss;
inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}
inline void trim(std::string &s)
{
    ltrim(s);
    rtrim(s);
}
    string reverseWords(string words) {
      stack<string>q;
      ss check(words);
      string word,res="";
     while(getline(check,word,' '))
      {
          if(!word.empty())q.push(word);
      }
      while(!q.empty())
      {
          res+=q.top()+" ";
          q.pop();
      }
     trim(res);
     return res;

    }
};