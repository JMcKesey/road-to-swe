// market making:
// it's a losers game. Why? you need to be good at everything
// make small profits and avoid big losses. You can lose alot
// because you're providing prices at any point of time some catalyst
// that causes alot of volatility can wipe out your inventory
//
//
// why is low latency important:
// Reacting fast to certain events (to update pricing or cancel orders)
// You need to smart and accurate
//
// Standard trading system:
// FPGA a chip that lets you implement a digital circuit inside it.
// Graph @ 8.00
// Engineering cost of FGPA is costly
// Strategies send rules to the FGPA. For it to be fast it needs to be 
// simple. 
//
// Order book deep dive
// David Gross says that an Order book is a datastructure
// Shows the bids/asks, size at each price level
// Network card has a finite amount of buffers, if ur app doesn't read fast enough
// you will miss some of the information
// Two ordered sequences: bids(high to low) asks from(low to high)
// Each order has an ID (uint64_t), typical order book has 1000 price levels


// standard API

enum class Side { Bid, Ask };

using OrderId = uint64_t;
using Volume = int64_t;

void AddOrder(OrderId orderId, Side side, Price price, Volume volume);

void ModifyOrder(OrderId orderIf, Volume newVolume);

void DeleteOrder(OrderId orderId);

// always need a hashmap when implement an OrderBook

void AddOrder(uint64_t orderId, Side side, Price price, Volume volume)
{
  auto [it, inserted] = mOrders.emplace(orderId, ...);
  EXPECT(inserted, "duplicate order");
}

void DeleteOrder(uint64_t orderId)
{
  auto it = mOrders.find(orderId);
  EXPECT(it != mOrders.end(), "missing order");
}

std::map<Price Volume, std::greater<Price>< mBidLevels;
std::map<Price Volume, std::less<Price>< mAskLevels;

template <class T>
typename T::iterator AddOrder(T& levels, Price price, Volume volume)
{
  auto[it, inserted] = levels.try_emplace(price, volume);
  if (inserted == false)
    it->second += volume;
  return it;
}


...

// Latency distribution is very important to look at 
// in the lecture he models the use of std::map and plots it against freq and latency(ns)
// gathered a week of data and on different instrument
// between OrderBook operations add memory allocations to randomize the heap
// randomized allocs greatly increase the latency and simulate a real env
// PRINCIPLE #1: "Most of the time, you don't want node containers"


// use std::vector one for bidLevels and mAskLevels
// he says 'cache locality' is great not sure what that means
// complexity is worse
// latency dist produces a fat tail which is bad, usually want it 
// to be narrow
// Why that happens? do EDA to find out
// He plots a barchart with Number of updates against # level 

// @ 23.58
