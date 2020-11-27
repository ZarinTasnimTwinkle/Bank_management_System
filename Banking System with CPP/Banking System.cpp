#include<iostream>
using namespace std;
class DBBL
{
private:
    double balance;
    string name;
    string accType;

    void set_account_info(string n,int acount_number,string t,double b) //function to set account information
    {
        name=n;
        accNumber=acount_number;
        accType=t;
        balance=b;
    }

public:
    int accNumber;

    void access(string n,int acount_number,string t,double b) //function to access account information
    {
        set_account_info(n,acount_number,t,b);
    }

    void show_info()  //Function to display informations
    {
        cout<<"\nAccount holder Name: "<<name<<endl;
        cout<<"Account number is: "<<accNumber<<endl;
        cout<<"Account type is: "<<accType<<endl;
        cout<<"Account balance is: "<<balance<<endl;
    }

    void show_balance()  //Function to display balance
    {
        cout<<"\nYour account balance is: "<<balance<<endl;
    }

    void deposit_money(double b)  //Function to diposite money
    {
        balance+=b;
        cout<<"New balance is: "<<balance<<endl;
    }

    int withdraw_money(double amount)  //Function to withdraw money
    {
        if(balance>=amount && amount>=500)
        {
            balance-=amount;
            return 1;
        }
        else
            return 0;
    }

    char mainMenu()   // Function to display the main menu
    {
        char choice;
        cout << "\n************** MAIN MENU ************** " << endl;
        cout << "L -> Login to Banking Menu" << endl;
        cout << "Q -> Quit the Program" << endl;
        cout << "\nEnter your option:" << endl;
        cin >> choice;
        return choice;
    }

};

int main()
{
    char choice;
    DBBL account;
    cout<<"***************************************************************************************************************\n";
    cout<<"                                            DATCH BANGLA BANK\n";
    cout<<"***************************************************************************************************************\n";
    while (choice != 'q' || choice != 'Q')
    {
        choice = account.mainMenu();
        if (choice == 'q' || choice == 'Q')
        {
            cout << "Thanks for Visiting!\n";
            break;
        }
        switch (choice)
        {
        case 'l':
        case 'L':
        {
            int option;
            DBBL b[3];
            b[0].access("Zarin",101,"Saving",30000.00);
            b[1].access("Tasnim",102,"Current",50000.00);
            b[2].access("Mim",103,"Saving",80000.00);
            int num;
            cout<<"Enter account number:"<<endl;
            cin>>num;
            while(1)
            {
                int idx,flag=0;
                double taka;
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
                cout<<"\n\n*************** BANKING MENU ***************";
                cout<<"\n 1 -> Display account holder's Informations:"<<endl;
                cout<<" 2 -> Money Deposit:"<<endl;
                cout<<" 3 -> Money Withdraw:"<<endl;
                cout<<" 4 -> Check account Balance:"<<endl;
                cout<<" 5 -> Return to Main-Menu:"<<endl;
                cout<<"\nEnter your option:"<<endl;
                cin>>option;
                if(option==1)
                {
                    b[idx].show_info();
                }
                else if(option==2)
                {
                    cout<<"Enter the amount:"<<endl;
                    cin>>taka;
                    b[idx].deposit_money(taka);
                }
                else if(option==3)
                {
                    cout<<"Enter the amount:"<<endl;
                    cin>>taka;
                    int op;
                    op = b[idx].withdraw_money(taka);
                    if(op==1)
                        cout<<"Successful transaction"<<endl;
                    else
                        cout<<"Unsuccessful transaction"<<endl;
                }
                else if(option==4)
                {
                    b[idx].show_balance();
                }
                else if(option==5)
                {
                    break;
                }
                else
                {
                    cout<<"Invalid option"<<endl;
                    break;
                }
            }
        }
        break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
