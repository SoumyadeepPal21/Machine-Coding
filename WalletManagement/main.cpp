#include <bits/stdc++.h>
#include "PaymentInterface.h"
#include <Wallet.h>
#include <User.h>
using namespace std;

int main()
{
    // cout << randomInt(0, 500) << endl;
    FlipkatWallet *flipkatWallet = FlipkatWallet::getInstance();

    shared_ptr<User> user1 = make_shared<User>("User1");
    unique_ptr<PaymentInterface> paymentInterface = make_unique<CreditCardPaymentInterface>(user1->getUserId());
    // cout << "user id " << user1->getUserId() << endl;
    user1->setPaymentInteface(move(paymentInterface));
    user1->addBalance(100);
    flipkatWallet->registerUser(user1);

    shared_ptr<User> user2 = make_shared<User>("User2");
    flipkatWallet->sendMoney(user1, user2, 10);

    flipkatWallet->registerUser(user2);
    flipkatWallet->sendMoney(user1, user2, 10);

    // cout << user1->getUserId() << " " << user2->getUserId() << endl;
    unique_ptr<PaymentInterface> paymentInterface2 = make_unique<UPIPaymentInterface>(user2->getUserId());
    user2->setPaymentInteface(move(paymentInterface2));
    flipkatWallet->sendMoney(user1, user2, 50);

    // cout << endl << user2->getWallentAmmount() << endl;
    flipkatWallet->sendMoney(user1, user2, 1);
    flipkatWallet->sendMoney(user2, user1, 1);
    vector<int> transactions = flipkatWallet->getTransactionHistory(user1, SEND);
    printf("\nprinting transactions ");
    for (int x : transactions)
    {
        cout << x << " ";
    }
    cout << endl;
}