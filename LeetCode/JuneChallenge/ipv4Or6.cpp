// IPV4 or IPV6
#include<iostream>
using namespace std;
bool isInValidChar(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') continue;
        else if (s[i] >= 'a' && s[i] <= 'f') continue;
        else if (s[i] >= 'A' && s[i] <= 'F') continue;
        else return true;
    }
    return false;
}
string solve(string IP)
{
    string ans = "";
    // Precomputaion -
    int leadingZero = 0, i = 0;
    bool flag = false; // False - means IPV4 -
    int v = -1;
    while (IP[i] != '.' && IP[i] != ':')
    {   if (i > 5) {
            ans = "Neither";
            return ans;
        }
        i++;
    }
    // Version 6 ->
    if (IP[i] == ':') {
        flag = true;
    }
    if (flag) {
        // cout<<"IPV6 If"<<endl;
        // 8 hexadecimal - values range 0 to 4
        i = 0;
        int j = 0;
        while (IP[j] != '\0') {
            string smallIP = "";
            int length = 0;
            while (IP[j] != ':' && IP[j] != '\0')
            {   smallIP += IP[j];
                if (IP[j] == '.' || length > 4) {
                    ans = "Neither";
                    return ans;
                }
                length++;
                j++;
            }
            if ((smallIP.size() == 0 || smallIP.size() > 4 || (IP[j] != '\0' && IP[j] == ':' && IP[j + 1] == '\0' || isInValidChar(smallIP) )))
            {   // Check for leading Zero -
                ans = "Neither";
                return ans;
            }
            i++;
            if (i > 8) break;
            if (IP[j] != '\0') j++;
        }
        if (i != 8) {
            ans = "Neither";
            return ans;
        }
        else {
            ans = "IPv6";
            return ans;
        }
    }
    else {
        //cout<<"IPV4 ele part"<<endl;
        i = 0;
        int j = 0;
        while (IP[j] != '\0') {
            int num = 0, count = -1, length = 0;
            while (IP[j] != '.' && IP[j] != '\0')
            {   // doubt 000
                if (count == -1) {
                    if (IP[j] == '0' && IP[j + 1] != '.' && IP[j + 1] != '\0') {
                        ans = "Neither";
                        return ans;
                    }
                    count++;
                }
                if (IP[j] == ':' || length > 3) {
                    ans = "Neither";
                    return ans;
                }
                length++;
                num = num * 10 + (int)(IP[j] - '0');
                j++;
            }
            //cout<<num<<endl;
            if (num < 0 || num > 255 || length == 0 || (IP[j] != '\0' && IP[j] == '.' && IP[j + 1] == '\0'))
            {   // Check for leading Zero -
                ans = "Neither";
                return ans;
            }
            i++;
            if (i > 4) break;
            if (IP[j] != '\0') j++;
        }
        if (i != 4) {
            ans = "Neither";
            return ans;
        }
        else {
            ans = "IPv4";
            return ans;
        }
    }
}
int main()
{
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}