#include "add_bid.h"
#include "OrderBook.h"

void add_bid(double price, const char* title, int orderid, uint16_t prob_basis_point, uint32_t trader_id, bool active, unsigned char side) {
    Order new_order;
    new_order.orderid = orderid;
    new_order.title = title;
    new_order.price = price;
    new_order.prob_basis_point = prob_basis_point;
    new_order.trader_id = trader_id;
    new_order.active = active;
    new_order.side = side;

    orderbook.push_back(new_order);
}

