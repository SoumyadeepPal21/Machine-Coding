#pragma once

#include <utils.h>
#include <memory>
#include <PaymentInterface.h>

using namespace std;

class User
{
public:
    User(string name) : name(name), walletAmmount(0)
    {
        userId = randomInt(0, 5000);
    }

    int getWallentAmmount() { return walletAmmount; }

    int getUserId() { return userId; }

    void setPaymentInteface(unique_ptr<PaymentInterface> pt)
    {
        this->paymentInterface = move(pt);
    }

    bool addBalance(int ammount)
    {
        if (paymentInterface == nullptr)
        {
            printf("\n%s does not have set payment method", name.c_str());
            return false;
        }
        if (!paymentInterface->addMoney(ammount))
            return false;
        walletAmmount += ammount;
        return true;
    }

    bool sendMoney(int ammount)
    {
        if (paymentInterface == nullptr)
        {
            printf("\n%s does not have set payment method", name.c_str());
            return false;
        }
        if (ammount > walletAmmount)
        {
            printf("\n%s does not have enough wallet balance", name.c_str());
            return false;
        }
        if (!paymentInterface->makePayment(ammount))
            return false;
        walletAmmount -= ammount;
        return true;
    }

    bool reciveMoney(int ammount)
    {
        if (paymentInterface == nullptr)
        {
            printf("\n%s does not have set payment method", name.c_str());
            return false;
        }
        if (!paymentInterface->addMoney(ammount))
            return false;
        walletAmmount += ammount;
        return true;
    }

private:
    string name;
    unique_ptr<PaymentInterface> paymentInterface;
    int userId;
    int walletAmmount;
};