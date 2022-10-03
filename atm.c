#include <stdio.h>


int main() {

//    variable declaration
    int pin, choice, accountNumber;
    double balance, transferAmount, deposite, withdraw;

    printf("-------------WELCOME TO ATM MACHINE---------------\n\n");

    printf("Enter your pin: ");
    scanf("%d", &pin);

    printf("Enter amount to create account: ");
    scanf("%lf", &balance);
    printf("Enter your choice: \n");
    printf("1. Balance\n2. Deposite\n3. Withdraw\n4.Balance transfer\n5. Exit.\nChoice: ");

    scanf("%d", &choice);

    switch(choice) {

    case 1:
        printf("Your balance is %.2lf BDT.", balance);
        break;
    case 2:
        printf("Enter amount to deposite: ");
        scanf("%lf", &deposite);
        balance += deposite;
        printf("Now your total amount is %.2lf BDT.\n", balance);
        break;
    case 3:
        printf("Enter amount to withdraw: ");
        scanf("%lf", &withdraw);

        if (balance < withdraw) {
            printf("You don't have Sufficient balance. Current balance is %.2lf.", balance);
            break;
        }
        else {
            balance -= withdraw;
            printf("%.2lf BDT withdraw from your account. Current balance is %.2lf", withdraw, balance);
            break;
        }
    case 4:
        printf("Enter account number and amount to transfer.\n");
        printf("Account numbeer: ");
        scanf("%d", &accountNumber);
        printf("Amount: ");
        scanf("%lf", &transferAmount);

        if (balance < transferAmount) {
            printf("You don't have Sufficient balance. Current balance is %.2lf.", balance);
            break;
        }
        else {
            balance -= transferAmount;
            printf("%.2lf BDT has been transfered to the account number: %d . Current balance is %.2lf", transferAmount, accountNumber, balance);
            break;
        }
    case 5:
        printf("Thank you for using out ATM.\n");
        break;
    default:
        printf("Invalid choice");
        break;

    }


    return 0;
}
