#include <thread>
#include <iostream>
#include <version>
#include "OrderBook.h"

#if !defined(__cpp_lib_jthread)
# error "This program requires C++20. Please enable C++20 support in compiler."
#endif




std::vector<Order> orderbook;

int main() {
    // Add some bids
    add_bid(90.45, "braves", 1, 23, 123, true, 0);
    resolve_bid(1, false);
    add_bid(90.45, "braves", 2, 23, 123, true, 0);
    add_bid(90.45, "marlin", 3, 23, 123, true, 0);
    add_bid(90.45, "cubs", 4, 23, 123, true, 0);
    add_bid(90.45, "braves", 5, 23, 123, true, 0);



    // Print the orderbook
    print_orderbook(orderbook);

    std::thread save_thread(periodic_save, std::ref(orderbook), "ob.txt", 2);

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    save_thread.join();



    return 0;
}

