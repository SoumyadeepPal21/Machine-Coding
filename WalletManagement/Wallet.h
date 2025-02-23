#pragma once

#include "User.h"
#include "map"

class TransactionRegister
{
public:
    void registerTransaction(shared_ptr<User> user, TRANSACTION_TYPE type, int ammount)
    {
        int userId = user->getUserId();
        transactions[{userId, type}].push_back(ammount);
    }

    vector<int> getTransactionByType(shared_ptr<User> user, TRANSACTION_TYPE type)
    {
        int userId = user->getUserId();
        return transactions[{userId, type}];
    }

private:
    map<pair<int, TRANSACTION_TYPE>, vector<int>> transactions;
};

class FlipkatWallet
{

public:
    static FlipkatWallet *getInstance()
    {
        static FlipkatWallet *flipkatWallet = nullptr;
        if (flipkatWallet == nullptr)
        {
            flipkatWallet = new FlipkatWallet();
        }
        return flipkatWallet;
    }

    void registerUser(shared_ptr<User> user)
    {
        userRegistry[user] = user->getUserId();
    }

    void addWalletBalance(shared_ptr<User> user, int ammount)
    {
        if (!user->addBalance(ammount))
            return;
    }

    void sendMoney(shared_ptr<User> sender, shared_ptr<User> reciever, int ammount)
    {
        if (!userRegistry.count(sender))
        {
            printf("\nsender does not exist");
            return;
        }
        if (!userRegistry.count(reciever))
        {
            printf("\nreciever does not exist");
            return;
        }
        if (ammount <= 0)
        {
            printf("\nPositive ammount needs to be sent");
            return;
        }
        bool response = sender->sendMoney(ammount);
        if (!response)
            return;
        response = reciever->reciveMoney(ammount);
        if (!response)
        {
            sender->addBalance(ammount);
            return;
        }
        transactionRegister->registerTransaction(sender, SEND, ammount);
        transactionRegister->registerTransaction(sender, RECIEVE, ammount);
    }

    vector<int> getTransactionHistory(shared_ptr<User> user, TRANSACTION_TYPE type)
    {
        return transactionRegister->getTransactionByType(user, type);
    }

private:
    FlipkatWallet()
    {
        transactionRegister = make_shared<TransactionRegister>();
    }

    FlipkatWallet &operator=(const FlipkatWallet &) = delete;
    FlipkatWallet(const FlipkatWallet &) = delete;

    map<shared_ptr<User>, int> userRegistry;
    shared_ptr<TransactionRegister> transactionRegister;
};
