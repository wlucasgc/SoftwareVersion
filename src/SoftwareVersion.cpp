//=================================================================================================
// SOFTWARE VERSION
//=================================================================================================

#include "SoftwareVersion.h"

//=================================================================================================
// CONSTRUTOR
//=================================================================================================

SoftwareVersion::SoftwareVersion(const byte& major, const byte& minor, const byte& patch, const bool& dev):
    _major(major),
    _minor(minor),
    _patch(patch),
    _dev(dev) {
}

//=================================================================================================
// DEVELOPER VERSION
//=================================================================================================

const bool SoftwareVersion::isDev() const {
    return(this->_dev);
}

//=================================================================================================
// SOFTWARE VERSION AS A STRING
//=================================================================================================

const String SoftwareVersion::toString() const {
    String softwareVersion = "v";
    softwareVersion += String(this->_major) + ".";
    softwareVersion += String(this->_minor) + ".";
    softwareVersion += String(this->_patch);

    if(this->isDev()) {
        softwareVersion += "-dev";
    }
    
    return(softwareVersion);
}

//=================================================================================================