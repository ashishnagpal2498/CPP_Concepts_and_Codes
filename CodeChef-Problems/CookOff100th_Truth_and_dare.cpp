//Ram and shyam truth dare game
#include<iostream>
using namespace std;
int main()
{
    int testcase,i;
    cin>>testcase;

    while(testcase>0)
    {
    int tr,dr,ts,ds,val;
    int task_ram_truth[105]={0},task_ram_dare[105]={0},task_shyam_can_give_truth[105]={0};
    int task_shyam_can_give_dare[105]={0};
    cin>>tr;
    for( i=0;i<tr;i++)
    {   cin>>val;
        task_ram_truth[val]=1;
    }
    cin>>dr;
    for(i=0;i<dr;i++)
    {
        cin>>val;
        task_ram_dare[val]=1;
    }
    cin>>ts;
    for( i=0;i<ts;i++)
    {
        cin>>val;
        task_shyam_can_give_truth[val] =1;
    }
    cin>>ds;
    for(i=0;i<ds;i++)
    {
        cin>>val;
        task_shyam_can_give_dare[val]=1;
    }
//     cout<<"Ram Dare frequency array"<<endl;
//     for(int i=0;i<100;i++)
//     {
//         cout<<task_ram_dare[i]<<" ";
//     }
// cout<<endl;
    bool flag =true;
    for( i=0;i<100;i++)
    {
        if((task_shyam_can_give_truth[i]-task_ram_truth[i]!=0&&task_shyam_can_give_truth[i]!=0)||(task_shyam_can_give_dare[i]-task_ram_dare[i]!=0&&task_shyam_can_give_dare[i]!=0))
        {  // cout<<task_shyam_can_give_truth[i]<<"  ram truth val"<<task_ram_truth[i];
           // cout<<"\n val i "<<i;
            flag = false;
            break;
        }    
    }
    if(flag){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }

    testcase--;
    }
    return 0;
}