// header files

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


// functions

bool login();
bool signUp();
void mainMenu();
void checkBalance(float balance);
float moneyDeposit(float balance);
float moneyWithdraw(float balance);
void menuExit();
void errorMessage();

// global variables
int choose;
char name[50];
int pin;
int pin2;
float balance;

// main code

int main() {
    // local declarations
    int option;
    bool again = true;
    bool authorized = false;

    printf("******************Hello!*******************\n");
    printf("******************Welcome to ATM Banking Service!*******************\n");

    printf("Please Log in or Sign Up to continue\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("< 1 > Log in\n");
    printf("< 2 > Sign Up\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Your Selection:\t");
    scanf("%d", &option);
    
    if (option == 1) {
        authorized = login();
    } else if (option == 2) {
        authorized = signUp();
    } else {
        printf("Invalid Selection\n");
    }

    while (again && authorized) {
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("Welcome back %s\n\n", name);

        printf("******************Please choose one of the options below******************\n\n");
        mainMenu();

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("Your Selection:\t");
        scanf("%d", &option);
        switch (option) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = moneyDeposit(balance);
                break;
            case 3:
                balance = moneyWithdraw(balance);
                break;
            case 4:
                menuExit();
                break;
            default:
                errorMessage();
                break;
        }




        if (choose == 2) {
            again = false;
        }
    }
    return 0;
}

// functions

// main menu function
void mainMenu() {


    printf("< 1 > Check Balance\n");
    printf("< 2 > Deposit\n");
    printf("< 3 > Withdraw\n");
    printf("< 4 > Exit\n\n");
}

// check balance function
void checkBalance(float balance) {
    printf("Your current balance is: %.2f\n", balance);

    //
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Would you like to do another transaction:\n");
    printf("< 1 > Yes\n");
    printf("< 2 > No\n");
    scanf("%d", &choose);
}

// deposit money function
float moneyDeposit(float balance) {
    float deposit;

    printf("Your current balance is : %.2f\n", balance);
    printf("Enter the amount you want to deposit:\t");
    scanf("%f", &deposit);

    balance += deposit;
    printf("Your current balance after deposit is : %.2f\n", balance);

      //
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Would you like to do another transaction:\n");
    printf("< 1 > Yes\n");
    printf("< 2 > No\n");
    scanf("%d", &choose);

    return balance;
}

// withdraw money function
float moneyWithdraw(float balance) {
    float withdraw;

    printf("Your current balance is : %.2f\n", balance);
    printf("Enter the amount you want to withdraw:\t");
    scanf("%f", &withdraw);

    if (withdraw > balance) {
        printf("You don't have enough money to withdraw!\n");
    } else {
        balance -= withdraw;
        printf("You have successfully withdrawn $: %.2f\n", withdraw);
        printf("Your current balance is $: %.2f\n", balance);
    }

      //
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Would you like to do another transaction:\n");
    printf("< 1 > Yes\n");
    printf("< 2 > No\n");
    scanf("%d", &choose);

    return balance;
}

// exit menu function
void menuExit() {
    printf("Thank you for using our ATM Banking Service!\n");
    choose = 2;
}

// error message function
void errorMessage() {
    printf("Invalid option! Please try again!\n");
    choose = 2;
}


// login function
bool login() {
    int loginPin;
    int tries = 0;
    int maxTries = 3;
    bool loginSuccess = false;
    int option;
    

    while (tries < maxTries || !loginSuccess) {
        printf("Enter your pin: ");
        scanf("%d", &pin);

        if (loginPin == pin) {
            printf("You have successfully logged in!\n");
            loginSuccess = true;
            break;
        } else {
            printf("Invalid pin! Please try again!\n");
            printf("Don't have an account? Sign up now!\n");

                printf("< 1 > Log in\n");
                printf("< 2 > Sign Up\n");
                printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                printf("Your Selection:\t");
                scanf("%d", &option);
                if (option == 1) {
                    // login();
                } else if (option == 2) {
                    signUp();
                    loginSuccess = true;
                    break;
                } else {
                    printf("Invalid Selection\n");
                }

            loginSuccess = false;
            tries++;
        }
    }
    return loginSuccess;
}

// sign up function
bool signUp() {
    int tries = 0;
    int maxTries = 3;
    bool signUpSuccess = false;

    while (tries < maxTries || !signUpSuccess) {
        printf("Enter your name: ");
        scanf("%s", &name);

        printf("Enter your pin: ");
        scanf("%d", &pin);

        printf("Re-enter your pin: ");
        scanf("%d", &pin2);

        if (pin == pin2) {
            printf("\nYou have successfully signed up!\n");
            // add balance 
            printf("Enter your initial balance: ");
            scanf("%f", &balance);
        
            signUpSuccess = true;
            break;
        } else {
            printf("Invalid pin! Please try again!\n");
            signUpSuccess = false;
            tries++;
        }
    }

    return signUpSuccess;
}

// wrong password function 