#include "tests.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
using namespace std;

class MyTest {
public:
    explicit MyTest(int val) : val(val) {}

    string ToString() {
        return to_string(val);
    }
    int val;
};


class MyGenerator {
public:
    MyTest operator()(std::mt19937 &rd) {
        return MyTest(rd() % 100);
    }
};

class MyChecker {
public:
    bool operator()(int a, int b) {
        return a == b;
    }
};


int main() {
//    {
//        Tester tester(4);
//        tester.RunTest("Test int", []() { REQUIRE(2 == 3); });
//        tester.RunTest("Test strings", []() { REQUIRE(string("asdfsdff") == string("s1")) });
//        tester.RunTest("Test vector", []() {
//            vector<int> v{1, 2, 4};
//            REQUIRE(v[0] == v[1]);
//        });
//        tester.RunTest("Test vector", []() {
//            vector<int> v{1, 1, 4};
//            REQUIRE(v[0] == v[1]);
//        });
//
//        tester.RunTests();
//    }
    {
        Tester tester(4);
        std::ofstream f;
        f.open("tmp.txt");
        tester.RunStressTest([](const MyTest& test) {return test.val % 2;}, [](const MyTest& test) {;return test.val % 2;}, MyGenerator(), MyChecker(), f) ;
    }

}
