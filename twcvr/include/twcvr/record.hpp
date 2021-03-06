#pragma once

#include <eosiolib/eosio.hpp>

namespace twcvr {
    using std::string;
    using std::vector;
    using namespace eosio;

    struct [[eosio::table, eosio::contract("twcvr")]] musicscore {
        uint16_t music_id;
        uint32_t score;
        bool operator == (const musicscore& rhs) {
            if (this->music_id == rhs.music_id)
                return true;
            return false;
        }
        EOSLIB_SERIALIZE( musicscore, (music_id)(score) );
    };

    struct [[eosio::table, eosio::contract("twcvr")]] record {
        name owner;
        vector<musicscore> scores;
        uint64_t timestamp;
        uint64_t reserve_1;
        uint64_t primary_key() const { return owner.value; }

        EOSLIB_SERIALIZE( record, (owner)(scores)(timestamp)(reserve_1) );
    };
    typedef eosio::multi_index< "records"_n, record> record_table;
} // twcvr