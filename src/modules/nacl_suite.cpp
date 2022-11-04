import nacl.utils from meshtastic_node 
import persona_pb2 from nacl.public 
import PrivateKey, Box 
import os
#include "nacl_suite.h"
#include <nacl.h>

class naclSuite() :
// suite for NaCl

    // Secret vault stores collections of device name &corresponding keys
    // value is
    naclSuite()
    {
        int secret_vault = {} 
        int book = persona_pb2.secret_book()        
    }

                 

    string get_config_path(){
        string path_to_script = os.path.dirname(os.path.realpath(__file__)) 
        return path_to_script[ : - 13] + "/meshtastic_node/config.txt" 
    }

    void read_from_config(){
        string fileName = get_config_path() 
        temp = persona_pb2.secret_book() 
        f = open(fileName, "rb") 
        temp.ParseFromString(f.read()) for person in temp.person : print(person.local_name)
    }

// Public / private key generator using Curve25519
// Uses device_name as key
    keyPair generate_key_pairs(self, device_name : str)
    {
        // Keys are 48 bytes

        newPrivateKey = PrivateKey.generate() newPublicKey = newPrivateKey.public_key
        try : self
            .secret_vault[device_name] = [ newPublicKey, newPrivateKey ] print("keys generation succeed") except AttributeError
                : print("attribute error, secret vault most likely not initialized") return

                  return newPrivateKey,
            newPublicKey
    }

// Remove a device key pairs using device_name
    def remove_key_pairs(self, device_name : str)
    {
        try : 
            del self.secret_vault[device_name] 
            print("Successfully deleted key")
        except Exception as e :
            print(repr(e))
    }

 // Print out all device names and key pairs
    void fbi_open_up(self)
    {
        for (int i = 0; i < secret_vault.keys.length(), i++) {
            print("Device name : " + eachKey)
            print("Public Key:" + self.secret_vault[eachKey][0])
            print("Private Key: " + self.secret_vault[eachKey[1]])
        }
    }
        
    void add_person_to_book(self, localName, address, num){
        new_dude = persona_pb2.persona() 
        new_dude.local_name = localName 
        new_dude.mac_address = address
        new_dude.node_num = num self.book.person.append(new_dude)
    }

    def write_all_secrets_to_file(self):
        fileName = self.get_config_path()
        f = open(fileName,'ab')
#f.write(text_proto)
        f.write(self.book.SerializeToString())
        f.close()

    def print_book(self):
        print(self.book)

suite = naclSuite()
suite.add_person_to_book('MIke','1717 abc',2)
suite.write_all_secrets_to_file()
suite.read_from_config()