#include<iostream>
using namespace std;

class bank
{
private:
    double balance;
    string name;

public:
    int accNumber;
    void set_info(string n,int a_num,double b)
    {
        name=n;
        accNumber=a_num;
        balance=b;
    }
    void display_info();
    void deposit(double b);
    int withdraw(double amount);

};

void bank :: display_info()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Account number is: "<<accNumber<<endl;
    cout<<"Account balance is: "<<balance<<endl;
}

void bank :: deposit(double b)
{
    balance+=b;
    cout<<"New balance is: "<<balance<<endl;
}
int bank :: withdraw(double amount)
{
    if(balance>=amount && amount>=500)
    {
        balance-=amount;
        return 1;
    }
    else
        return 0;
}

int main()
{
    int option;
    bank b[3];
    b[0].set_info("Customer1",101,10000.00);
    b[1].set_info("Customer2",102,25000.00);
    b[2].set_info("Customer3",103,45000.00);
    while(1)
    {
        int num,idx,flag=0;
        double taka;
        cout<<"Enter account number:"<<endl;
        cin>>num;

        for(int i=0; i<3; i++)
        {
            if(b[i].accNumber==num)
            {
                idx=i;
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            cout<<"Invalid account number"<<endl;
            break;
        }

        cout<<"Enter 1 to display information:"<<endl;
        cout<<"Enter 2 to deposit balance:"<<endl;
        cout<<"Enter 3 to withdraw balance:"<<endl;
        cout<<"Enter your option:"<<endl;
        cin>>option;

        if(option==1)
        {
            b[idx].display_info();
        }
        else if(option==2)
        {
            cout<<"Enter the amount:"<<endl;
            cin>>taka;
            b[idx].deposit(taka);
        }
        else if(option==3)
        {
            cout<<"Enter the amount:"<<endl;
            cin>>taka;
            int op;
            op = b[idx].withdraw(taka);
            if(op==1)
                cout<<"Successful transaction"<<endl;
            else
                cout<<"Unsuccessful transaction"<<endl;
        }
        else
        {
            cout<<"Invalid option"<<endl;
            break;
        }
    }
    return 0;
}
