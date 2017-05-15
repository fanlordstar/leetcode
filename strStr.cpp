class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0)    // 字串为空时，不管原串，返回0
            return 0;
        else if(haystack.length() == 0 || haystack.length() < needle.length())   // 原串为空时，返回-1
            return -1;
        
        int ans = -1;
        for(int i = 0; i <= haystack.length() - needle.length(); i++)
        {
            string temp = haystack.substr(i, needle.length());
            if(hashString(temp) == hashString(needle) && temp == needle)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
    
    // 用来计算字符串的哈希函数
    long hashString(string &temp)
    {
        long hash = 0;
        for(int i = 0; i < temp.size(); i++)
        {
            hash = hash * 29 + (temp.at(i) - 'a'); 
        }
        
        return hash;
    }
};