class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0, n = s.length();

        while(i<n && s[i]==' '){
            i++; //remove leading spaces
        }

        while(i<n){
            string word;
            while(i<n && s[i]!=' '){
                word += s[i++];
            }

            if(!word.empty()) words.push_back(word);

            while(i<n && s[i]==' '){
                i++; //remove spaces inbetween words;
            }
        }

        reverse(words.begin(),words.end());

        string res = "";
        int length = words.size();

        for(int j = 0;j<length;j++){
            res += words[j];
            if(j!=length-1) res += ' '; // add space before adding a new word
        }


        return res;
    }
};