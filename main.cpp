// Purpose:Convert hour from AM to PM and opposite
// Author:  Dr. Mohammad El-Ramly
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void funhour(string hour);
int main()
{
    string hour;
    cout<<"enter your hour (HH:MM AM) or (HH:MM PM)"<<endl;
    cin>>hour;
    cin.ignore();
    funhour(hour);

    return 0;
}
void funhour(string hour)
{
    string pm_am;
    cin>>pm_am;//input AM or PM
    int* num;
    num=new int [hour.size()];
    int* num1;
    num1=new int[hour.size()];
    int counter=0;
    int k=0;
    if(int(pm_am[0])==65)
    {
        int j=0;
        while(int(hour[j])!=58)//know this time takes one or two digit
        {
            counter++;
            j++;
        }
        for(int i=0; i<hour.size(); i++)//convert string array to int
        {
            if(hour[i]==':')
            {
                num[i]=int(hour[i]);
            }
            else
            {
                num[i]=int( hour[i])-48;
            }
        }
        for(int i=0; i<hour.size(); i++)//convert from AM to PM
        {


            if(i==0)
            {
                if(counter==2)
                {
                    if(num[i]!=2)
                    {
                        num1[i]=0;
                        num1[i+1]=num[i]+num[i+1]+9-12;
                        ++i;
                    }
                    else
                    {
                        num1[i]=-1;
                        num1[i+1]=num[i]+num[i+1]+18-12;
                        ++i;
                    }
                }

                else
                {
                    num1[0]=num[i]-12;
                }
            }
            else if(num[i]==58)
            {
                num1[i]=58;
            }
            else
                num1[i]=num[i];
        }
        if((num1[1]<0)||(num1[1]==58))//print the hour without convert
        {
            for(int i=0; i<hour.size(); i++)
            {
                if(num[i]==58)
                {
                    cout<<num[i+1];
                    ++i;
                }
                else
                {

                    if(num1[k]<0)
                    {
                        cout<<0;
                        ++k;
                    }
                    cout<<num[i];
                }
            }
        }
        else//print the new hour
        {
            for(int i=0; i<hour.size(); i++)
            {
                if(num1[i]==58)
                {
                    cout<< num1[i+1];
                    ++i;
                }
                else
                {
                    if(num1[i]<0)
                    {
                        cout<<" "<<endl;
                    }
                    else
                        cout<<num1[i];
                }
            }

        }
        cout<<" Hours";
    }
    else if (int(pm_am[0])==80)
    {
        int j=0;
        while(int(hour[j])!=58)//know this time takes one or two digit
        {
            counter++;
            j++;
        }
        for(int i=0; i<hour.size(); i++)//convert string array to int
        {
            if(hour[i]==':')
            {
                num[i]=int(hour[i]);
            }
            else
            {
                num[i]=int( hour[i])-48;
            }
        }
        for(int i=0; i<hour.size(); i++)//convert from AM to PM
        {

            if(counter==2)

            {
                if(i==0)
                {
                    if(num[i]==0)
                    {
                        num1[i]=num[i+1]+12;
                    }
                    else
                    {
                        num1[i]=num[i]+num[i+1]+9+12;
                    }
                    ++i;
                }
                else if(num[i]==58)
                {
                    num1[i-1]=58;
                }
                else
                    num1[i-1]=num[i];
            }
            else
            {
                if(i==0)
                {
                    num1[0]=num[i]+12;
                }
                else if(num[i]==58)
                {
                    num1[i]=58;
                }
                else
                    num1[i]=num[i];
            }
        }
        if((num1[0]>=24))//print the hour without convert
        {
            for(int i=0; i<hour.size(); i++)
            {
                if(num[i]==58)
                {
                    cout<<num[i+1];
                    ++i;
                }
                else
                {
                    cout<<num[i];
                }
            }
        }
        else//print new hour
        {
            if(counter==2)
            {
                for(int i=0; i<hour.size()-1; i++)
                {
                    if(num1[i]==58)
                    {
                        cout<< num1[i+1];
                        ++i;
                    }
                    else
                    {
                        if(num1[i]<0)
                        {
                            cout<<" "<<endl;
                        }
                        else
                            cout<<num1[i];
                    }
                }

            }
            else
            {
                for(int i=0; i<hour.size(); i++)
                {
                    if(num1[i]==58)
                    {
                        cout<< num1[i+1];
                        ++i;
                    }
                    else
                    {
                        if(num1[i]<0)
                        {
                            cout<<" "<<endl;
                        }
                        else
                            cout<<num1[i];
                    }
                }

            }

        }
        cout<<" Hours";
    }
    else
        cout<<"                  End";
}
