#include <iostream>
#include <cstdlib>
#include <array>
#include <random>
#include "layer.h"

using namespace std;

int main(int argc, char* argv[]){
    Layer new_layer = Layer(10, "test?");
    cout << new_layer.GetStr() << endl;
    array<int, 3> arr = {1, 2, 3};
    for (int elem : arr){
        cout << elem << endl;
    }
    for (int i = 0; i < arr.size(); ++i){
        cout << arr[i] << endl;
    }
    return 0;
}