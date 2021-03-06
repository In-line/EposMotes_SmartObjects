#ifndef RADIOCONTROL_H
#define RADIOCONTROL_H

#include "ifstream.h"
#include "ofstream.h"
#include "Message.h"
#include "Observer.h"
namespace pj{
class RadioControl :public Observer<Message>
{
    public:
        RadioControl(ifstream& receiver,ofstream& sender, int size );
        void startListening();
        void stopListening();

        virtual ~RadioControl();

        int sendMessage(Message);
        int getId();
        int generateId();

    protected:
       volatile bool isListening;
        int id;
        int size;

        int* web;

        int lastMsg;
        ifstream& receiver;
        ofstream& sender;

        int getHash(Message);

    private:
};
}
#endif // RADIOCONTROL_H
