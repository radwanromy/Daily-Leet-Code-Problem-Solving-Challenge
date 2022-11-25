class Solution {
public:
    int strStr(string haystack, string needle) {
        const int x=haystack.length();
        const int y=needle.length();
        for(int i= 0; i<x;i++){
            if(haystack.substr(i,y)==needle){
                return i;
            }
        }
        return -1;
    }
};
