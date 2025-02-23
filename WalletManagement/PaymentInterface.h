#pragma once

#include <iostream>

class PaymentInterface
{
public:
    virtual bool makePayment(int ammount) = 0;
    virtual bool addMoney(int ammount) = 0;
};

class UPIPaymentInterface : public PaymentInterface
{
public:
    UPIPaymentInterface(int userId)
    {
        if (userId == -1)
        {
            return;
        }
        this->userId = userId;
        printf("\nUPI account is created for user with id: %d", userId);
    }

    bool makePayment(int ammount) override
    {
        printf("\nAmmount %d is paid using UPI by user id %d", ammount, userId);
        return true;
    }

    bool addMoney(int ammount) override
    {
        printf("\nAmmount %d is credit to userid %d", ammount, userId);
        return true;
    }

private:
    int userId;
};

class CreditCardPaymentInterface : public PaymentInterface
{
public:
    CreditCardPaymentInterface(int userId)
    {
        if (userId == -1)
        {
            return;
        }
        this->userId = userId;
        printf("\ncredit card account is created for user with id: %d", userId);
    }

    bool makePayment(int ammount) override
    {
        printf("\nAmmont %d is credited to user %d using credit card", ammount, userId);
        return true;
    }

    bool addMoney(int ammount) override
    {
        printf("\nAmmount %d is credit to userid %d", ammount, userId);
        return true;
    }

private:
    int userId;
};
