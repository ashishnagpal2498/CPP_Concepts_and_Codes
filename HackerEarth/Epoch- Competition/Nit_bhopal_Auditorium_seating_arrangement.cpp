//Ladies Seating arrangement
#include<iostream>
using namespace std;
int count = 0;
bool numberofladiesin_ith_seat(int seatnum,int j)
{     static int ladies_placed =0;
    //Base Case
    if(seatnum==j)
    {

    }
    for(int i=j;i<seatnum-1;i++)
    {
        //place the lady and call recursion
         count+=ladies_placed;
         ladies_placed++;
         bool smallans = numberofladiesin_ith_seat(seatnum,j+1);
         if(smallans)
         {
            return true;
         }
         else
         {
            //backtrack
            ladies_placed--;
            
         }
        
    }
}

int main()
{

    return 0;
}