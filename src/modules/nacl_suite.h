#include <nacl.h>
#include "persona_pb2"


class naclSuite():
     //suite for PyNaCl
    private:
        // Both are hash lists
        int secret_vault
        int book
    public:

        naclSuite();
    
        string get_config_path();

        void read_from_config();

        // Public / private key generator using Curve25519
        // Uses device_name as key
        uint_48 generate_key_pairs(string device_name);
        // Keys are 48 bytes
    
        // Remove a device key pairs using device_name
        void remove_key_pairs(string device_name);        
    
        // Print out all device names and key pairs
        void fbi_open_up();

        void add_person_to_book(string localName, string address, int num);

        void write_all_secrets_to_file();

        void print_book();