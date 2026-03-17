#pragma once

#include <string>
#include <vector>

class Item
{
public:
    std::string name;
    int sellIn;
    int quality;
    Item(std::string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

class GildedRose
{
public:
    std::vector<Item> & items;
    GildedRose(std::vector<Item> & items);
    
    void updateQuality();
};

class Cashier
{
public:
    std::vector<int> coins;

    Cashier();

    std::vector<int> calculateChange(int amountPaid, int itemPrice);
    std::vector<std::vector<Item>> budgetOptions(int budget, const std::vector<Item> & currentItems);
};
