#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int B,L,D;
    cin>>B>>L>>D;
    int books[10005];
    for(int i=0;i<B;i++) cin>>books[i];
    int lib = L;
    vector<vector<int> > libDetails;
    vector<vector<int> > libBooks;
    int m =0;
    while(m<lib)
    {    int val;
        for(int i=0;i<3;i++)
            {   cin>>val;
                libDetails[m].push_back(val);
            }
        for(int i=0;i<libDetails[m][0];i++)
        {
            cin>>val;
            libBooks[m].push_back(val);
        }    
            m++;
    }
    for(int i=0;i<libDetails.size();i++)
    {
        if(i+1<L && libDetails[i][1]>libDetails[i+1][1])
        {
            swap(libDetails[i],libDetails[i+1]);
        }
    }
    for(int i=0;i<libBooks.size();i++)
    {
        for(int j=0;j<libBooks[i].size();j++)
        {
            for(int k=0;k<libBooks[i].size()-1;k++)
            {
                if(books[libBooks[j][k]]<books[libBooks[j][k+1]])
                {
                    swap(libBooks[j][k],libBooks[j][k+1]);
                }
            }
        }
    }   
    bool isSigning = false; 
    m=0;
    int maxSum=0;
  while(D--)
  { 
    if(!isSigning)
    {
        isSigning = true;
        //nothing happens;
    }
    else{
        if(m<L)
        {
            //books left for signing -

        }
        //number of books can be picked per day-

    }
  }  
  return 0;      
}