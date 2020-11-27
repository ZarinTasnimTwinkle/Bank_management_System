import java.util.Scanner;  
import java.util.Date;  

class Bank {
    private String account;
    private String name;
    private long balance;
    public Date withdrawDate;
    public Date depositeDate;

    Scanner input = new Scanner(System.in);

    //method to open an account
    void openAccount() 
    {
        System.out.print("Enter Account No: ");
        account = input.next();
        System.out.print("Enter Name: ");
        name = input.next();
        System.out.print("Enter Balance: ");
        balance = input.nextLong();
    }

    //method to display account details
    void showAccount() 
    {
        System.out.println("\nName-> "+ name + "\nAccount Number-> " + account + "\nBalance-> " + balance+" taka");
        System.out.print("\nLast Deposition Date : "+depositeDate);
        System.out.println("\nLast Withdrawal Date : "+withdrawDate);
    }

    //method to deposit money
    void deposit() 
    {
        long amount;
        System.out.println("Enter Amount You Want to Deposit : ");
        amount = input.nextLong();
        balance = balance + amount;
        System.out.println("Your New Balance : "+ balance+" taka");
        System.out.print("Balance Deposite Time : ");
        //to show the date of deposite 
            Date date = new Date();
            {
                depositeDate = date;
                System.out.println(depositeDate);
            }  
    }

    //method to withdraw money
    void withdrawal() 
    {
        long amount;
        System.out.println("Enter Amount You Want to withdraw : ");
        amount = input.nextLong();
        if(balance >= amount)
        {
            balance = balance - amount;
            System.out.println("Balance After Transaction : "+ balance+" taka");
            System.out.print("Balance Withdraw Time : ");
            //to show the date of withdraw 
            Date date = new Date();
            {
                withdrawDate = date;
                System.out.println(withdrawDate);
            }  
        }
        else 
            System.out.println("Less Balance..Transaction Failed..");
    }

    //method to search an account number
    boolean search(String AccountNumber) 
    {
        if (account.equals(AccountNumber)) 
            return (true);
        return (false);
    }

    //method to show balance
    void ShowBalance()
    {
        System.out.print("Your Balance : "+balance+" taka");
        System.out.print("\nLast Deposition Date : "+depositeDate);
        System.out.println("\nLast Withdrawal Date : "+withdrawDate);
    }
}

public class ExBank {
    public static void main(String arg[]) 
    {
        Scanner input = new Scanner(System.in);

        System.out.println("\n\n***************************************************************************************************************");
        System.out.println("                                        DATCH BANGLA BANK LIMITED");
        System.out.println("***************************************************************************************************************");

        //create initial accounts
        System.out.print("\nHow Many Customer You Want to Input : ");
        int n = input.nextInt();
        Bank C[] = new Bank[n];
        for (int i=0; i<C.length; i++) 
        {
            C[i] = new Bank();
            C[i].openAccount();
        }

        //run loop until menu 5 is not pressed
        int ch;
        do 
        {
            System.out.println("\n********Main Menu********\n\n 1. Display Account Information\n 2. Deposit\n 3. Withdrawal\n 4. Show Balance\n 5. Exit");
                System.out.print("\nyour Choice : "); 
                ch = input.nextInt();
                switch (ch) 
                {
                    case 1:
                        System.out.print("Enter Account Number You Want to Search: ");
                        String AccountNumber = input.next();
                        boolean found = true;
                        for (int i=0; i<C.length; i++) 
                        {
                            found = C[i].search(AccountNumber);
                            if (found)
                            {
                                C[i].showAccount();
                                break;
                            }
                        }
                        if (!found)
                            System.out.println("Search Failed..Account Not Exist..");
                        break;

                    case 2:
                        System.out.print("Enter Account No : ");
                        AccountNumber = input.next();
                        found = true;
                        for (int i=0; i<C.length; i++) 
                        {
                            found = C[i].search(AccountNumber);
                            if (found) 
                            {
                                C[i].deposit();
                                break;
                            }
                        }
                        if (!found)
                            System.out.println("Search Failed..Account Not Exist..");
                        break;

                    case 3:
                        System.out.print("Enter Account No : ");
                        AccountNumber = input.next();
                        found = true;
                        for (int i=0; i<C.length; i++) 
                        {
                            found = C[i].search(AccountNumber);
                            if (found) 
                            {
                                C[i].withdrawal();
                                break;
                            }
                        }
                        if (!found)
                            System.out.println("Search Failed..Account Not Exist..");
                        break;

                    case 4:
                        System.out.print("Enter Account No : ");
                        AccountNumber = input.next();
                        found = true;
                        for (int i=0; i<C.length; i++) 
                        {
                            found = C[i].search(AccountNumber);
                            if (found) 
                            {
                                C[i].ShowBalance();
                                break;
                            }
                        }
                        if (!found)
                            System.out.println("Search Failed..Account Not Exist..");
                        break;
                        

                    case 5:
                        System.out.println("Thanks for Visiting...");
                        break;
                }

            }
            while (ch != 5);
        
        }
    }

