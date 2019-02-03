//CodeChef Cook-Off
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int testcase;
    cin>>testcase;    
     while(testcase>0)
    {   int no_of_days;
        int day_ith[32]={0};
        int problems_solved[32]={0};
        int Q;
        int deadline;
        int problem_to_be_solved;
             cin>>no_of_days;

        for(int i=0;i<no_of_days;i++)
            {
                cin>>day_ith[i]>>problems_solved[i];
            }
        cin>>Q;
        for(int i=0;i<Q;i++)
            {
                cin>>deadline>>problem_to_be_solved;
                int problems_solved_by_person = 0;
                for(int j=0;j<no_of_days;j++)
                {
                    if(deadline>=day_ith[j])
                    {
                        problems_solved_by_person += problems_solved[j];
                    }
                }
                if(problems_solved_by_person>=problem_to_be_solved)
                    {
                        cout<<"Go Camp"<<endl;
                    }
                else{
                    cout<<"Go Sleep"<<endl;
                    }
            }
            testcase--;
    }
    return 0;
}