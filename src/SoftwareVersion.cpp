//=================================================================================================
// SOFTWARE VERSION
//=================================================================================================

#include "SoftwareVersion.h"

//=================================================================================================
// CONSTRUCTOR 1
//=================================================================================================

SoftwareVersion::SoftwareVersion() : SoftwareVersion(0, 0, 0) {}

//=================================================================================================
// CONSTRUCTOR 2
//=================================================================================================

SoftwareVersion::SoftwareVersion(const byte& major, const byte& minor, const byte& patch, const bool& dev):
    _major(major),
    _minor(minor),
    _patch(patch),
    _dev(dev) {
}

//=================================================================================================
// CONSTRUCTOR 3
//=================================================================================================

SoftwareVersion::SoftwareVersion(const String& softwareVersion) {
    if(!softwareVersion.endsWith("-dev")) {
        sscanf(softwareVersion.c_str(), "v%d.%d.%d", &this->_major, &this->_minor, &this->_patch);
        this->_dev = false;
        return;
    }

    sscanf(softwareVersion.c_str(), "v%d.%d.%d-dev", &this->_major, &this->_minor, &this->_patch);
    this->_dev = true;
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
// OPERATIONS
//=================================================================================================

SoftwareVersion& SoftwareVersion::operator=(const SoftwareVersion& other) {
    if(this != &other) {
        this->_major = other._major;
        this->_minor = other._minor;
        this->_patch = other._patch;
        this->_dev = other._dev;
    }

    return(*this);
}

const bool SoftwareVersion::operator==(const SoftwareVersion& other) const {
    return(this->_major == other._major && this->_minor == other._minor && this->_patch == other._patch && this->_dev == other._dev);
}

const bool SoftwareVersion::operator!=(const SoftwareVersion& other) const {
    return(this->_major != other._major || this->_minor != other._minor || this->_patch != other._patch || this->_dev != other._dev);
}

const bool SoftwareVersion::operator<(const SoftwareVersion& other) const {
    if(this->_major > other._major) {
        return(false);
    }
    
    if(this->_major < other._major) {
        return(true);
    }
    
    if(this->_minor > other._minor) {
        return(false);
    }
    
    if(this->_minor < other._minor) {
        return(true);
    }

    if(this->_patch >= other._patch) {
        return(false);
    }
    
    return(true);
}

const bool SoftwareVersion::operator>(const SoftwareVersion& other) const {
    if(this->_major < other._major) {
        return(false);
    }

    if(this->_major > other._major) {
        return(true);
    }
    
    if(this->_minor < other._minor) {
        return(false);
    }

    if(this->_minor > other._minor) {
        return(true);
    }
    
    if(this->_patch <= other._patch) {
        return(false);
    }
    
    return(true);
}

const bool SoftwareVersion::operator<=(const SoftwareVersion& other) const {
    if(this->_major > other._major) {
        return(false);
    }

    if(this->_major < other._major) {
        return(true);
    }
    
    if(this->_minor > other._minor) {
        return(false);
    }

    if(this->_minor < other._minor) {
        return(true);
    }
    
    if(this->_patch > other._patch) {
        return(false);
    }
    
    return(true);
}

const bool SoftwareVersion::operator>=(const SoftwareVersion& other) const {
    if(this->_major < other._major) {
        return(false);
    }

    if(this->_major > other._major) {
        return(true);
    }
    
    if(this->_minor < other._minor) {
        return(false);
    }

    if(this->_minor > other._minor) {
        return(true);
    }
    
    if(this->_patch < other._patch) {
        return(false);
    }
    
    return(true);
}

//=================================================================================================