//
//  thread.cpp
//  try&test
//
//  Created by Praneeth Patil on 11/11/17.
//  Copyright © 2017 Praneeth Patil. All rights reserved.
//

#include <iostream>
#include <mutex>
#include <thread>
#include <future>

using namespace std;

struct foo {
    string operator()(const string& s) {
        cout << __PRETTY_FUNCTION__ << " s is " << s << endl;
        return ("string is " + s);
    }
};

int  main() {
    foo f;
    future<string> fut =  async(f, "praneeth");
    cout << "and then this happened\n";
    cout << fut.get() << endl;
    return 0;
}
