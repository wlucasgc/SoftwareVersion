//=================================================================================================
// SOFTWARE VERSION
//=================================================================================================

#pragma once

#include <Arduino.h>

class SoftwareVersion {
    private:
        byte _major;
        byte _minor;
        byte _patch;
        bool _dev;

    public:
        SoftwareVersion();
        SoftwareVersion(const byte& major, const byte& minor, const byte& patch, const bool& dev = false);
        SoftwareVersion(const String& softwareVersion);
        
        const bool isDev() const;
        const String toString() const;
};

//=================================================================================================