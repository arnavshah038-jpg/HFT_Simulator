#include "OrderBook.hpp"
#include "Utils.hpp"
#include <iostream>
#include <vector>

int main() {
    OrderBook ob;
    
    // Data folder se orders uthayiye
    std::vector<Order> orders = CSVReader::readOrders("data/orders.csv");
    if (orders.empty()) {
        std::cerr << "Error: No orders found in CSV file!" << std::endl;
        return 1;
    }

    std::cout << "--- HFT Stress Test: " << orders.size() << " orders ---\n";

    uint64_t start = Timer::now();

    for (const auto& o : orders) {
        ob.addOrder(o);
    }

    uint64_t end = Timer::now();
    uint64_t totalTime = end - start;

    std::cout << "Total Time: " << totalTime << " ns" << std::endl;
    std::cout << "Avg Latency per Order: " << totalTime / orders.size() << " ns" << std::endl;

    return 0;
}