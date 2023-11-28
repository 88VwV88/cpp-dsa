#include<iostream>

int main(int argc, char** argv) {
    using std::cout, std::endl;
    cout << "Hello, " << argv[argc!=1] <<  "! " << endl;
}

