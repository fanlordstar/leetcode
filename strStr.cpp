class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0)    // �ִ�Ϊ��ʱ������ԭ��������0
            return 0;
        else if(haystack.length() == 0 || haystack.length() < needle.length())   // ԭ��Ϊ��ʱ������-1
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
    
    // ���������ַ����Ĺ�ϣ����
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