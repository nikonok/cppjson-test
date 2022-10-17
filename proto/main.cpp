#include <iostream>

#include <Message.pb.h>

#include <google/protobuf/util/json_util.h>

void printMsg(const Message& msg) {
    std::cout << "Tag = " << msg.tag() << " Name = " << msg.name() << std::endl;
}

int main() {
    Message msg;

    msg.set_tag(123);
    msg.set_name("HELLO WORLD!");

    std::cout << "Message before serializing" << std::endl;
    printMsg(msg);

    std::string json;
    google::protobuf::util::MessageToJsonString(msg, &json);

    std::cout << "JSON by protobuf" << std::endl;
    std::cout << json << std::endl;


    Message newMsg;
    google::protobuf::util::JsonStringToMessage(json, &newMsg);

    std::cout << "Message after serializing" << std::endl;
    printMsg(newMsg);
}
