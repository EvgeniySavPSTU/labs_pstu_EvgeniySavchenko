#include <iostream>
using namespace std;
int main()
{
    int m[15]={8,1,1,3,5,1,10,55,10,55,23,14,1,55,77};
    int max=m[0],min=m[0],indmx=0,indmn=0,nmx=1,nmn=1;
    for (int i=0;i<16;i++)
    {
        if (m[i]>max)
        {
            max=m[i];
            indmx=i;
            nmx=1;
        }
        else if(m[i]<min)
        {
            min=m[i];
            indmn=i;
            nmn=1;
        }
        else if(m[i]==max) nmx++;
        else if(m[i]==min) nmn++;
    }
    cout<<"max: "<<max<<" index: "<<indmx<<" number: "<<indmx+1<<endl;
    cout<<"min: "<<min<<" index: "<<indmn<<" number: "<<indmn+1<<endl;
    if (nmx>1) cout<<"same max: "<<nmx<<endl;
    if (nmn>1) cout<<"same min: "<<nmn<<endl;
    return 0;
}