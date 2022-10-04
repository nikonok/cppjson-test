#include <iostream>
#include <fstream>
#include <vector>

#include <json_pathes.hpp>

#include <nlohmann/json.hpp>

// for convenience
using json = nlohmann::json;

struct JsonTest {
    std::string stringFiled;
    std::vector<uint32_t> vectorField;
    uint64_t numField;
};

std::ostream& operator<<(std::ostream& os, const JsonTest& jt)
{
    os << "stringFiled: " << jt.stringFiled << "\t";
    os << "vectorField: ";
    for(auto i: jt.vectorField) {
        os << i << ", ";
    }
    os << "\t" << "numField: " << jt.numField << "\t";
    return os;
}

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(JsonTest, stringFiled, vectorField, numField);

const std::string TMP_FILENAME("tmp.json");

int main() {
    std::ifstream f(JSON1);
    json data = json::parse(f);

    std::cout << "JSON from file: " << std::endl;
    std::cout << data << std::endl;

    JsonTest test = {"Hello World", {1, 2, 3}, 123};

    json j1 = test;
    std::cout << "JSON from struct" << std::endl;
    std::cout << j1 << std::endl;

    std::cout << "JSON from struct modified" << std::endl;
    j1["numField"] = 321;
    std::cout << j1 << std::endl;

    std::ofstream tmp_file(TMP_FILENAME, std::ios::trunc);

    tmp_file << j1;
    tmp_file.close();

    std::cout << "JSON from file modified" << std::endl;
    json j2 = json::parse(std::ifstream(TMP_FILENAME));
    std::cout << j2 << std::endl;

    std::cout << "JSON to struct" << std::endl;
    std::cout << j2.get<JsonTest>() << std::endl;
}
