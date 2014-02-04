// -*- Mode: C; c-basic-offset: 8; -*-
//
// Copyright (c) 2012 Andrew Tridgell, All Rights Reserved
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//  o Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  o Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in
//    the documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//

///
/// @file	crc.c
///
/// crc 16 code
/// see http://www.8052.com/users/bigblack/index.phtml
///

#include <stdarg.h>
#include "radio.h"
#include "crc.h"


// Implemented based on the Si1000 datasheet
// http://www.silabs.com/Support%2520Documents/TechnicalDocs/Si1000.pdf
uint16_t 
crc16(__data uint8_t n, __xdata uint8_t * __data buf)
{    
    uint16_t ret;
    
    // sxelect 16-bit CRC, polynomial 0x1021
    CRC0SEL = 1;
    // Set the inital value to 0x0000 (1 -> 0xFFFF)
    CRC0VAL = 0;
    // Initialise the CRC hardware 
    CRC0INIT = 1;
    
    while  (n--)
        // Write each byte into the CRC input register
        CRC0IN = *(buf++);
    // Ensure we're going to read the first byte, then the second
    CRC0PNT0 = 0;
    CRC0PNT1 = 0;
    // read low byte
    ret = CRC0DAT;
    // and high byte
    ret = ret | CRC0DAT << 8;
    return ret;
    
}
