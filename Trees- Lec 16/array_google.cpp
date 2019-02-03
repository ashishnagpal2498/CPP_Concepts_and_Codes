//
//Curr position , position at which need to jump
bool CanPlace(vector<int>arr , int curr,int jump_pos,int jump_num)
{
    if(jump_num%2==0)
    {
       //even 
        if(arr[curr]>arr[jump_pos])
        {
            return true;
        }
    }
    else{
        //odd condition
        if(arr[curr]<arr[jump_pos])
        {
            return true;
        }
    }
    return false

}

bool isPossible(vector<int>arr,int i,int jump_num)
{   
    //Base case
    if(i==arr.size()-1)
    {
        return true;
    }

    int sz = arr.size();
    for(int j=i+1;j<sz-1;j++)
    {
        if(CanPlace(arr,i,j,jump_num))
        {
            i = j;
            jump_num++;
            bool smallarr = isPossible(arr,i,jump_num);
            if(smallarr)
            {
                return true;
            }
        }
    }
    // Backtracking ??????
    return false;
}
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int countfields = 0;
    bool ans ;
    int sz = A.size();
    for(int i=0;i<sz;i++)
    {
        ans = isPossible(A,i,1);
        if(ans)
        {
            countfields++;
        }
    }
    return countfields;
}