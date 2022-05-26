// Mapped Strings -

#include<iostream>
using namespace std;

string mp = {
    'A','B','C','D',
    'E','F','G', 'H',
    'I','J','K','L',
    'M','N','O','P',
    'Q','R','S','T',
    'U','V','W','X',
    'Y','Z'
};

void mapped_strings(string str,string num,int j){
    // base case 
    if(j>num.size()) return; 
    if(num[j] == '\0'){
        cout<<str<<endl;
    }
        //cout<<"here - "<<mp[num[i]-'0'-1];
        str+=mp[num[j]-'0'-1];
        //cout<<str<<endl;
        mapped_strings(str,num,j+1);
        
        str.pop_back();
        if(j+1 < num.size() ){
            int digit = (num[j]-'0')*10 + (num[j+1] - '0');
            //cout<<digit<<endl;
            if( digit <=27){
                str+=mp[digit-1];
                mapped_strings(str,num,j+2);
                 str.pop_back();
            }
    }
}

int main(){

    string num;
    cin>>num;
    string str = "";
    mapped_strings(str,num,0);
}