//Lower bound and upper bound in vector
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{   vector<int> vect;
    for(int i=0;vect.size()<=10;i+=1) vect.push_back(i);
        
    for(int i=0;i<vect.size();i++) {cout<<vect.at(i)<<" ";}
        //Lower Bound - If value exist - returns the same value -
        // Else , just greater value
    cout<<"\nLower Bound :- \n";
    cout<<"1) Value - 10   Ans - "
    <<*lower_bound(vect.begin(),vect.end(),10)<<endl;
     cout<<"2) Value - 11   Ans - "
         <<*lower_bound(vect.begin(),vect.end(),11)<<endl;
     cout<<"3) Value - 5   Ans - "
      <<*lower_bound(vect.begin(),vect.end(),5)<<endl;    
    
    //Upper Bound - If the value exist 
    cout<<"Upper Bound :- \n";
    cout<<"1) Value - 10   Ans - "
    <<*upper_bound(vect.begin(),vect.end(),10)<<endl;
     cout<<"2) Value - 11   Ans - "
         <<*upper_bound(vect.begin(),vect.end(),11)<<endl;
     cout<<"3) Value - 5   Ans - "
      <<*upper_bound(vect.begin(),vect.end(),5)<<endl;    
    return 0;
}