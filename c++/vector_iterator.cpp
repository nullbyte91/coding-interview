#include <bits/stdc++.h>
#include <vector> 
#include <iostream>

using namespace std;

int
main(int argc, char** argcv){
    vector<int> test;
    int num = 5;
    for (int i=0; i<5; i++){
        test.push_back(i);
    }

    for (auto i=test.begin(); i != test.end(); i++){
        printf("Val:%d", *i);
    }
    putchar('\n');
    return 0;
}