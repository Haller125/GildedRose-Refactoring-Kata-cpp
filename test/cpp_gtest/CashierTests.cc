#include <numeric>
#include <vector>
#include "gtest/gtest.h"
#include "GildedRose.h"

TEST(TestCalculateChange, test_calculate_change_exact_amount)
{
    Cashier cashier;
    const auto change = cashier.calculateChange(10, 10);
    EXPECT_TRUE(change.empty());
}

TEST(TestCalculateChange, test_calculate_change_overpaid)
{
    Cashier cashier;
    const auto change = cashier.calculateChange(20, 7);
    const std::vector<int> expected = {10, 1, 1, 1};
    EXPECT_EQ(expected, change);
}

TEST(TestCalculateChange, test_calculate_change_one_coin)
{
    Cashier cashier;
    const auto change = cashier.calculateChange(15, 10);
    const std::vector<int> expected = {5};
    EXPECT_EQ(expected, change);
}

TEST(TestBudgetOptionsMaxTwoItems, test_budget_options_two_item_combinations)
{
    Cashier cashier;
    std::vector<Item> items = {
        Item("apple", 10, 5),
        Item("banana", 10, 5),
        Item("orange", 10, 5),
    };

    const int budget = 10;
    const auto combinations = cashier.budgetOptions(budget, items);

    EXPECT_EQ(3, combinations.size());
    for (const auto & combo : combinations)
    {
        const int total = std::accumulate(combo.begin(), combo.end(), 0, [](int sum, const Item & item) {
            return sum + item.quality;
        });
        EXPECT_EQ(budget, total);
    }
}

TEST(TestBudgetOptionsMaxThreeItems, test_budget_options_three_item_combinations)
{
    Cashier cashier;
    std::vector<Item> items = {
        Item("item_1", 10, 3),
        Item("item_2", 10, 3),
        Item("item_3", 10, 3),
        Item("item_4", 10, 3),
    };

    const int budget = 9;
    const auto combinations = cashier.budgetOptions(budget, items);

    EXPECT_FALSE(combinations.empty());
    for (const auto & combo : combinations)
    {
        EXPECT_EQ(3, combo.size());
        const int total = std::accumulate(combo.begin(), combo.end(), 0, [](int sum, const Item & item) {
            return sum + item.quality;
        });
        EXPECT_EQ(budget, total);
    }
}

TEST(TestBudgetOptionsMaxFourItems, test_budget_options_four_item_combinations)
{
    Cashier cashier;
    std::vector<Item> items = {
        Item("item_1", 10, 2),
        Item("item_2", 10, 2),
        Item("item_3", 10, 2),
        Item("item_4", 10, 2),
        Item("item_5", 10, 2),
    };

    const int budget = 8;
    const auto combinations = cashier.budgetOptions(budget, items);

    EXPECT_FALSE(combinations.empty());
    for (const auto & combo : combinations)
    {
        EXPECT_EQ(4, combo.size());
        const int total = std::accumulate(combo.begin(), combo.end(), 0, [](int sum, const Item & item) {
            return sum + item.quality;
        });
        EXPECT_EQ(budget, total);
    }
}

TEST(TestBudgetOptionsMaxFiveOrMoreItems, test_budget_options_five_plus_item_combinations)
{
    Cashier cashier;
    std::vector<Item> items = {
        Item("item_1", 10, 1),
        Item("item_2", 10, 1),
        Item("item_3", 10, 1),
        Item("item_4", 10, 1),
        Item("item_5", 10, 1),
        Item("item_6", 10, 1),
    };

    const int budget = 6;
    const auto combinations = cashier.budgetOptions(budget, items);

    EXPECT_FALSE(combinations.empty());
    for (const auto & combo : combinations)
    {
        EXPECT_GE(combo.size(), 5);
        const int total = std::accumulate(combo.begin(), combo.end(), 0, [](int sum, const Item & item) {
            return sum + item.quality;
        });
        EXPECT_EQ(budget, total);
    }
}
