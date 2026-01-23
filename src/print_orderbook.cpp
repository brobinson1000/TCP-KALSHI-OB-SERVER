#include "print_orderbook.h"
#include <iostream>

void print_orderbook(const std::vector<Order>& orderbook) {
    const char* green = "\033[32m";
    const char* red = "\033[31m";
    const char* reset = "\033[0m";

    for (const auto& order : orderbook) {
        if (order.active == true) {
            std::cout << " | " << green << order.orderid << reset << "\t" << " | " << green << order.trader_id << reset
                      << "\t" << " | " << green << order.price << reset << "\t" << " | " << green << order.prob_basis_point << reset << "\t"
                      << " | " << green << order.side << reset << "\t" << " | " << std::boolalpha << green << order.active << "\n" << reset;
        } else {
            std::cout << " | " << red << order.orderid << reset << "\t" << " | " << red << order.trader_id << reset
                      << "\t" << " | " << red << order.price << reset << "\t" << " | " << red << order.prob_basis_point << reset << "\t"
                      << " | " << red << order.side << reset << "\t" << " | " << std::boolalpha << red << order.active << "\n" << reset;
        }
    }
}

