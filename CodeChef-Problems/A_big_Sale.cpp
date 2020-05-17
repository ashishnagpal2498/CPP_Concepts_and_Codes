//A big sale 
#include<iostream>
using namespace std;
int main()
{
    //Need to find out the total loss in sale
    //ith - Quantity , discount , and price original 
    //
    int testcase;
    cin>>testcase;
    float price_ith,quantity_ith,discount_ith;
    int n; //No of iterations;
    while(testcase>0)
    {
    
        cin>>n;
        float ans = 0.0000000;

    for(int i=0;i<n;i++)
    {
        cin>>price_ith>>quantity_ith>>discount_ith;
        float newprice = price_ith +price_ith* (discount_ith/100);
         cout<<"new price of item  "<<newprice;
        //Now apply the discount to new price of the item;
        newprice = newprice - newprice*(discount_ith/100);
         cout<<"\n Discounted price of item  "<<newprice<<endl;
        float costprice = price_ith;
        float selling_price = newprice;
         cout<<"Cost price  "<<costprice<<"  selling_price  "<<selling_price<<endl;
        ans = ans + (costprice - selling_price)*quantity_ith;
    }
    cout<<ans<<endl;

    testcase--;
    }
    return 0;
}