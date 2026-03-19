#include "OrderBook.hpp"
#include <algorithm> // std::min ke liye

void OrderBook::addOrder(Order order) {
    if (order.side == Side::BUY) {
        bids[order.price].push_back(order);
    } else {
        asks[order.price].push_back(order);
    }
    // Naya order aate hi matching engine trigger hoga
    match();
}

void OrderBook::match() {
    // Jab tak Bid price Ask price se bada ya barabar hai, trade hoti rahegi
    while (!bids.empty() && !asks.empty()) {
        auto itBid = bids.begin(); // Highest Bid
        auto itAsk = asks.begin(); // Lowest Ask

        // Price match condition
        if (itBid->first >= itAsk->first) {
            auto& buyOrder = itBid->second.front();
            auto& sellOrder = itAsk->second.front();

            // Kitni quantity trade ho sakti hai?
            uint32_t matchedQty = std::min(buyOrder.quantity, sellOrder.quantity);
            
            // Quantity update karein
            buyOrder.quantity -= matchedQty;
            sellOrder.quantity -= matchedQty;

            // Agar Buy order poora khatam ho gaya
            if (buyOrder.quantity == 0) {
                itBid->second.pop_front();
                if (itBid->second.empty()) {
                    bids.erase(itBid);
                }
            }

            // Agar Sell order poora khatam ho gaya
            if (sellOrder.quantity == 0) {
                itAsk->second.pop_front();
                if (itAsk->second.empty()) {
                    asks.erase(itAsk);
                }
            }
        } else {
            // Agar prices match nahi ho rahe, toh aage check karne ki zaroorat nahi
            break; 
        }
    }
}