//UNLOCK - HB
#include<iostream>
#include<set>
#include<vector>
#define Arrout for(int i=0;i<n;i++) {cout<<arr[i]<<" ";}
#define setOut for(auto i=st.begin();i!=st.end();i++){auto p = *i; cout<<p.first<<" ";}
using namespace std;
class myComp{
public:
    bool operator()(pair<int,int> A,pair<int,int>B)
    {
        return A.first>B.first;
    }
};
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    set<pair<int,int> ,myComp > st;
    int arr[100005];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        st.insert(make_pair(arr[i],i));
    }
    // for(auto i=st.begin();i!=st.end();i++)
    // {
    //     auto p = *i;
    //     cout<<p.first<<" ";
    // }
    //PAIR OF VALUE + INDEX
    for(int i=0;i<k&&k<n;i++)
    {   pair<int,int> topElement = *(st.begin());
        if(arr[i]==topElement.first)
        {    st.erase(st.begin());
            k++;
            continue;
        }
        else
        {   int ele = arr[i];
            int newIndex = topElement.second;
            swap(arr[i],arr[newIndex]);
            //Update The Set and - 
            //Update the element in set
            st.erase(st.begin());
            //
            auto it = st.find(make_pair(arr[newIndex],i));
            st.erase(it);
            st.insert(make_pair(arr[newIndex],newIndex));
        }
        // cout<<"STATUS OF ARRAY\n";
        // Arrout;
        // cout<<" -> SET ";
        // setOut;
        // cout<<endl;
    }

    // for(int i=0;i<n;i++) {cout<<arr[i]<<" ";}
    Arrout;
    return 0;
}