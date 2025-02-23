#pragma once

#include <random>
using namespace std;

int randomInt(int low, int high)
{
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dis(low, high);
    return dis(gen);
}

enum TRANSACTION_TYPE
{
    SEND,
    RECIEVE,
    ADD_BALANCE,
    TRANSACTION_TYPE_MAX
};
