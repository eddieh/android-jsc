/*
 *  Copyright (C) 2016 Eddie Hillenbrand. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 *
 */

#ifndef WTF_UnicodeTables_h
#define WTF_UnicodeTables_h

typedef uint16_t UChar;
typedef int32_t UChar32;

namespace WTF {
namespace Unicode {

extern uint32_t UpperTable[865];
extern uint32_t LowerTable[856];

struct SpecialProperties {
    uint16_t codePoint;
    char lowerLength;
    char titleLength;
    char upperLength;
    uint16_t lowerCase[3];
    uint16_t titleCase[3];
    uint16_t upperCase[3];
};

extern SpecialProperties SpecialCasingTable[103];

SpecialProperties specialCasingRule(UChar c);
UChar convertToLower(UChar c);
UChar convertToUpper(UChar c);
bool isSurrogatePair(UChar ch, UChar ch2);
UChar32 surrogatePairToUChar32(UChar a, UChar b);

} }

#endif // WTF_UnicodeTables_h
