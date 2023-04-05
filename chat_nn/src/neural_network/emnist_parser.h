#ifndef EMNISTPARSER_H
#define EMNISTPARSER_H

#include <string>
#include <vector>

class EMNISTParser {
public:
    EMNISTParser() = default;
    ~EMNISTParser() = default;

    std::vector<std::vector<float>> parse_images(const std::string& filename);
    std::vector<int> parse_labels(const std::string& filename);

private:
    int read_int(std::ifstream& file);
};

#endif // EMNISTPARSER_H
