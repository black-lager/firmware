#include "TextMessageModule.h"
#include "NodeDB.h"
#include "PowerFSM.h"
#include "configuration.h"

TextMessageModule *textMessageModule;

/**
 * Text messaging module with public key signed messages.
 */
ProcessMessage TextMessageModule::handleReceived(const MeshPacket &mp)
{
    auto &p = mp.decoded;
    DEBUG_MSG("Received text msg from=0x%0x, id=0x%x, msg=%.*s\n", mp.from, mp.id, p.payload.size, p.payload.bytes);

    // We only store/display messages destined for us.
    // Keep a copy of the most recent text message.
    devicestate.rx_text_message = mp;
    devicestate.has_rx_text_message = true;

    powerFSM.trigger(EVENT_RECEIVED_TEXT_MSG);
    notifyObservers(&mp);

    return ProcessMessage::CONTINUE; // Let others look at this message also if they want
}
