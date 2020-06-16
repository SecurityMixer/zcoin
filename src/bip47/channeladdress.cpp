    #include "bip47/channeladdress.h"
    Bip47ChannelAddress::Bip47ChannelAddress(){

    }
    Bip47ChannelAddress::Bip47ChannelAddress(CExtPubKey &cKey, int child) {
        
        childNum = child;
        CExtPubKey dk;
        if(!cKey.Derive(dk, childNum)){
            throw std::runtime_error("Bip47ChannelAddress::Bip47ChannelAddress(CBaseChainParams *v_params, CExtPubKey &cKey, int child) is failed.\n");
        }
        ecKey = dk;

        pubKey = std::vector<unsigned char>(ecKey.pubkey.begin(),ecKey.pubkey.end());
    }
  
    std::vector<unsigned char>& Bip47ChannelAddress::getPubKey() {
        return pubKey;
    }

    std::string Bip47ChannelAddress::getPath() {
        return strPath;
    }