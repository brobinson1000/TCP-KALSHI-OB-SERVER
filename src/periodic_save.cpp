#include <thread>
#include <chrono>
#include <string>
#include <iostream>
#include "periodic_save.h"

void periodic_save(std::vector<Order>& orderbook, const std::string &filepath, int interval_minutes) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::minutes(interval_minutes));
        save_bin_snap(orderbook, filepath);
        std::cout << "Orderbook snapshot saved \n";
    }
};
