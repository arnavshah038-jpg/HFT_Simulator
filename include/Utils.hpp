#ifndef UTILS_HPP
#define UTILS_HPP

#include <chrono>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Order.hpp"

class Timer {
public:
    static uint64_t now() {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(
                   std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    }
};

class CSVReader {
public:
    static std::vector<Order> readOrders(const std::string& filename) {
        std::vector<Order> orders;
        std::ifstream file(filename);
        
        if (!file.is_open()) {
            return orders; 
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;
            
            std::stringstream ss(line);
            std::string id, side, price, qty;

            std::getline(ss, id, ',');
            std::getline(ss, side, ',');
            std::getline(ss, price, ',');
            std::getline(ss, qty, ',');

            Order o;
            o.id = std::stoull(id);
            o.side = (side == "B" || side == "BUY") ? Side::BUY : Side::SELL;
            o.price = std::stol(price);
            o.quantity = std::stoul(qty);
            orders.push_back(o);
        }
        return orders;
    }
};

#endif