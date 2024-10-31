#ifndef MESSAGE_H
#define MESSAGE_H

#include <queue>

namespace Game {
    class Message {
        public:

            enum Type {
                CREATE_CUBE,
                PLAY,
                PAUSE
            };

            virtual ~Message();

            std::queue<Type> message_queue;
            static Message* get_instance();

            bool is_empty() const;
            void push(const Message::Type& type);
            Message::Type pop();

        private:
            Message();
            static Message* instance;

    };

}

#endif
