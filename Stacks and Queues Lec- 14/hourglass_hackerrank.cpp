//Hour-glass Hackerrank
//Arrays - Basic 
#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int topleft=0,bottomleft=2;
    int i=0,j=0,maxsum=-1000;
    // int val=1;
    while(i<4)
    {   
            
        for(int j=0;j<4;j++)
        {  int sum=0;
            for(int k=j;k<=j+2;k++)
            {
                sum= sum+ arr[topleft][k]+arr[bottomleft][k];
                // cout<<"Inner loop sum "<<sum<<endl;
            }
            // cout<<"Hourglass no.  "<<val<<endl;
            // val++;
            // Now sum the middle element
            int midcord_i=  (topleft) + 1;
            // int a = (j+2);
            int midcord_j = j+1; 
            sum+=arr[midcord_i][midcord_j];
            // cout<<sum<<endl;
            // cout<<"Final sum "<<sum<<endl;
            if(sum>maxsum)
            {
                maxsum=sum ;
            }
        }
        i++;
        topleft++; bottomleft++; //topright+=i;bottomright+=i;
    }
    // cout<<maxsum;

    return maxsum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
