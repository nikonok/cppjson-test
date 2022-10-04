#include <iostream>
#include <fstream>
#include <vector>

#include <json_pathes.hpp>

#include <json_struct/json_struct.h>

struct JsonTest {
    std::string stringFiled;
    std::vector<uint32_t> vectorField;
    uint64_t numField;
};

JS_OBJ_EXT(JsonTest, stringFiled, vectorField, numField);

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

const std::string TMP_FILENAME("tmp.json");

int main() {
    JsonTest test = {"Hello World", {1, 2, 3}, 123};
    auto jsonString = JS::serializeStruct(test, JS::SerializerOptions(JS::SerializerOptions::Compact));
    std::cout << "JSON from object: " << std::endl;
    std::cout << jsonString << std::endl;

    JS::Map map;
    JS::ParseContext parseContext(jsonString.c_str(), jsonString.size(), map);
    if (parseContext.parseTo(map) != JS::Error::NoError) {
        std::cout << "Error!" << std::endl;
    }
    map.setValue<uint64_t>("numField", parseContext, 321);

    jsonString = JS::serializeStruct(map, JS::SerializerOptions(JS::SerializerOptions::Compact));
    std::cout << "JSON from object modified: " << std::endl;
    std::cout << jsonString << std::endl;

    JS::ParseContext context(jsonString);
    JsonTest obj;
    context.parseTo(obj);
    std::cout << "Object from JSON: " << std::endl;
    std::cout << obj << std::endl;
}
