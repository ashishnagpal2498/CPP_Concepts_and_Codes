// MY Answer - TLE
// Logic - 
//    1. Calculate all subsequence of size k and add to map
//    2. Check if subsequence present in string - > remove map
//    3. check map.empty();

 bool hasAllCodes(string s, int k) {
        // Substrings of size 'k' will come in O(n)
        map<string,bool> binary_codes;
        // k size subsequence string
        for(int i=0;i < 1<<k; i++){
            int j = i,count =0;
            string ans = "";
            while(count<k){
                if(j&1){
                    ans+="1";
                }
                else{
                    ans+="0";
                }
                j>>=1;
                count++;
            }
            binary_codes.insert({ans,false});
        }
        
        // print Map   
      // for(auto i:binary_codes){
      //           cout<<i.first<<" -> ";
      //       }
      //  cout<<endl;
        int i=0,j=0,n= s.size();
        string smallAns = "";
        while(i<k) smallAns+=s[i++];
        while(i<=n){
                //cout<<smallAns;
                if(binary_codes.find(smallAns) != binary_codes.end()){
                    binary_codes.erase(smallAns);
                }
                smallAns.erase(smallAns.begin());
                smallAns+= s[i];
                i++;
                //cout<<" , "<<smallAns<<"->";
                if(binary_codes.empty()) return true;
        }
        return binary_codes.empty();
    }


// Soln

if(k > s.size()) return false;
    
    unordered_set<string> res_set;
    
    //Insertion into the set
    for(int i =0;i<= s.size()-k;i++)
        res_set.insert(s.substr(i,k));
    
    //Comparing res with 2^k
    return res_set.size() == pow(2,k);