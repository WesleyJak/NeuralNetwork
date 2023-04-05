#include <stdio.h>
#include <stdlib.h>
#include "layer.h"

Layer::Layer(int num, std::string myStr){
    SetNum(num);
    SetString(myStr);
}

void Layer::SetNum(int num){
    l_num = num;
}

void Layer::SetString(std::string str){
    l_string = str;
}