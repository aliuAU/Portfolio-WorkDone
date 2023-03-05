#include "stockType.h"

istream &operator>>(istream &ins, stockType &stock)
{
    ins >> stock.symbols;
    ins >> stock.open_price;
    ins >> stock.close_price;
    ins >> stock.high_price;
    ins >> stock.low_prev_price;
    ins >> stock.close_prev_price;
    ins >> stock.no_shares;
    stock.calculateGain(stock.close_price, stock.close_prev_price);
    return ins;
}

void stockType::calculateGain(double closeP, double prevP)
{
    gain = ((closeP - prevP) / (prevP)*100);
}

bool stockType::operator==(const stockType &stock1) const
{
    return (symbols == stock1.symbols);
}

string stockType::getSymbols() const { return symbols; }
