#include <iostream>
#include "OrderBook.h"

std::vector<Order> orderbook;

int main() {
    // Add some bids
    add_bid(90.45, "braves", 1, 23, 123, true, 0);
    resolve_bid(1, false);
    add_bid(90.45, "braves", 2, 23, 123, true, 0);
    add_bid(90.45, "marlin", 3, 23, 123, true, 0);
    add_bid(90.45, "cubs", 4, 23, 123, true, 0);
    add_bid(90.45, "braves", 5, 23, 123, true, 0);

    // Save the snapshot to file
    save_bin_snap(orderbook, "ob.txt");

    // Replay the snapshot from file
    replay_bin_snap(orderbook, "ob.txt");

    // Print the orderbook
    print_orderbook(orderbook);

    return 0;
}

