#include "message.h"

namespace Game {
    Message* Message::instance = nullptr;

    Message::Message() {

    }

    Message::~Message() {

    }

    Message* Message::get_instance() {
        if(instance == nullptr)
            instance = new Message();

        return instance;
    }


    bool Message::is_empty() const {
        return message_queue.empty();
    }


    void Message::push(const Message::Type& type) {
        message_queue.push(type);
    }


    Message::Type Message::pop() {
        Message::Type type = message_queue.front();
        message_queue.pop();

        return type;
    }


}
