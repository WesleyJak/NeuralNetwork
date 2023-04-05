#ifndef LAYER_H
#define LAYER_H
#include <string>
class Layer{
    private:
        int l_num;
        std::string l_string;
    public:
        Layer(int num, std::string str);

        void SetString(std::string str);

        void SetNum(int num);

        int GetNum(){
            return l_num;
        }

        std::string GetStr(){
            return l_string;
        }

};

#endif