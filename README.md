### Build tests
    $ mkdir build
    $ cd build
    $ cmake ..
    $ cmake --build .

# Технические требования «Gilded Rose»


Привет и добро пожаловать в команду «Gilded Rose». Как вы знаете, мы небольшая гостиница удобно расположенная
в известном городе под руководством дружественного управляющего по имени Эллисон. Также мы занимаемся покупкой
и продажей только самых лучших товаров. К несчастью, качество наших товаров постоянно ухудшается по мере приближения
к максимальному сроку хранения.

У нас есть информационная система, которая ведет переучет всех товаров. Система
была разработана рубаха-парнем, по имени Leeroy, который отправился за поисками новых приключений. Ваша задача
заключается в том, чтобы добавить новый функционал в нашу систему, чтобы мы могли начать продавать новую категорию
товаров. Для начала введение в нашу систему:

- Все `товары` имеют значение `срока реализации` (`SellIn`), которое обозначает количество дней, в течение которых мы должны их продать
- Все `товары` имеют значение `качества` (`Quality`), которое обозначает, насколько ценен товар
- В конце дня наша система снижает значение обоих свойств для каждого товара

Довольно просто, не правда ли? Тут-то и начинается самое интересное:

- Как только срок продажи товара истек, его качество (`Quality`) портится в два раза быстрее
- Качество (`Quality`) товара никогда не бывает отрицательным
- Для товара __"Aged Brie"__ качество (`Quality`) увеличивается с возрастом
- Качество (`Quality`) товара никогда не превышает `50`
- __"Sulfuras"__, являясь легендарным товаром, никогда не нужно продавать и его `качество` (`Quality`) никогда не уменьшается
- __"Backstage passes"__, как и __"Aged Brie"__, увеличивается в качестве (`Quality`) по мере приближения к значению срока реализации (`SellIn`):
	- Качество (`Quality`) увеличивается на `2`, когда остаётся `10` дней или меньше, и на `3`, когда остаётся `5` дней или меньше, но
	- Качество (`Quality`) падает до `0` после концерта

Недавно мы подписали контракт с поставщиком зачарованных товаров. Это требует обновления нашей системы:

- Зачарованные (__"Conjured"__) предметы теряют качество (`Quality`) в два раза быстрее обычных товаров

Не стесняйтесь вносить любые изменения в метод `UpdateQuality` и добавлять любой новый код до тех пор,
пока система работает корректно. Тем не менее, не меняйте класс `Item` или свойства `Items`, так как они принадлежат
сидящему в углу гоблину, который очень яростен и поэтому выстрелит в вас поскольку не верит в принцип
совместного владения кодом (вы можете сделать метод `UpdateQuality` и свойства класса `Item` статическими
если хотите, мы вас прикроем).

Просто для уточнения, товар никогда не может иметь качество (`Quality`) выше чем `50`, однако легендарный товар __"Sulfuras"__
имеет качество `80` и оно никогда не меняется.


# C++ version of Gilded Rose refactoring kata

## Introduction
The C++ version of the Gilded Rose refactoring kata is available in four variants using different test frameworks:

* Catch2 test framework
  1. Traditional unit test with the [Catch2](https://github.com/catchorg/Catch2) test framework in the `test/cpp_catch2_unittest` folder.
  2. [Approval tests](https://github.com/approvals/ApprovalTests.cpp) with the [Catch2](https://github.com/catchorg/Catch2) test framework in the `test/cpp_catch2_approvaltest` folder.
* GoogleTest framework
  1. Traditional unit test with the [GoogleTest](https://github.com/google/googletest) test framework in the `test/cpp_googletest_unittest` folder.
  2. [Approval tests](https://github.com/approvals/ApprovalTests.cpp) with the [GoogleTest](https://github.com/google/googletest) test framework in the `test/cpp_googletest_approvaltest` folder.

The `GildedRose.cc` file, i.e. the code under test, is identical in all four variants.

## Prerequisites

* CMake version &GreaterEqual; 3.13
* C++ compiler that supports C++14 

## How to build and run tests in a terminal

### Build tests

    $ cd ${GIT_FOLDER}/GildedRose-Refactoring-Kata/cpp
    $ mkdir build
    $ cd build
    $ cmake ..
    $ cmake --build .

The following test specific options for building with CMake are available.

* `BUILD_APPROVAL_TESTS_WITH_CATCH2:BOOL=ON`
This option builds the approval tests with the Catch2 test framework.
* `BUILD_UNIT_TESTS_WITH_CATCH2:BOOL=ON`
This option builds the unit tests with the Catch2 test framework.
* `BUILD_APPROVAL_TESTS_WITH_GTEST:BOOL=ON`
This option builds the approval tests with the GoogleTest test framework.
* `BUILD_UNIT_TESTS_WITH_GTEST:BOOL=ON`
This option builds the unit tests with the GoogleTest test framework.

For example, run the CMake configuration `cmake -DBUILD_APPROVAL_TESTS_WITH_CATCH2=OFF -DBUILD_UNIT_TESTS_WITH_CATCH2=OFF ..` to disable the Catch2 based tests.

### Show available tests

    $ cd ${GIT_FOLDER}/GildedRose-Refactoring-Kata/cpp/build
    $ ctest -N
    Test project ${GIT_FOLDER}/GildedRose-Refactoring-Kata/cpp/build
      Test #1: GildedRoseCatch2ApprovalTests
      Test #2: GildedRoseCatch2UnitTests
      Test #3: GildedRoseGoogletestApprovalTests
      Test #4: GildedRoseGoogletestUnitTests

### Run all tests

    $ ctest

### Run all tests with verbose output

    $ ctest -VV

### Run a specific test with verbose output

    $ ctest -VV --tests-regex Catch2Approval

## How to build and run tests using the [CLion IDE](https://www.jetbrains.com/clion/)

1. Start CLion
2. Select menu `File - Open...`
3. Select folder `${GIT_FOLDER}/GildedRose-Refactoring-Kata/cpp`
4. Select menu `Build - Build Project`
5. Select menu `Run - Run...`
6. Select what test variant to run, e.g. `GildedRoseCatch2ApprovalTests`.

## How to build and run tests using Visual Studio &GreaterEqual; 2019 

1. Start Visual Studio
2. Select `Open a local folder`
3. Select folder `${GIT_FOLDER}/GildedRose-Refactoring-Kata/cpp`
4. Wait for message `CMake generation finished.` in the CMake output window at the bottom
5. Select what test variant to run in the drop down menu for Startup Items, e.g. `GildedRoseCatch2ApprovalTests.exe`.
6. Select menu `Debug - Start`
