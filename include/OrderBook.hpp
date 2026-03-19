#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include <map>
#include <list>
#include <vector>
#include "Order.hpp"

class OrderBook {
private:
    // Bids: Sabse mehnga kharidne wala top par (std::greater)
    std::map<long, std::list<Order>, std::greater<long>> bids;
    // Asks: Sabse sasta bechne wala top par (std::less)
    std::map<long, std::list<Order>> asks;

public:
    void addOrder(Order order);
    void match();
};

#endif