/*
 *  This file is part of the KDE libraries
 *  Copyright (C) 2006 George Staikos <staikos@kde.org>
 *  Copyright (C) 2006 Alexey Proskuryakov <ap@nypop.com>
 *  Copyright (C) 2007 Harri Porten <porten@kde.org>
 *  Copyright (C) 2015 Eddie Hillenbrand <eddie.hillenbrand@adcolony.com>
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

// TODO: pass these tests - /icu-56.1/source/test/testdata/casing.txt

#ifndef WTF_UnicodeLibC_h
#define WTF_UnicodeLibC_h

#include <android/log.h>

#define APPTAG "ULIBC"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, APPTAG, __VA_ARGS__)

#include "UnicodeMacrosFromICU.h"
#include "UnicodeTables.h"

#include <wtf/ASCIICType.h>
#include <assert.h>
#include <wctype.h>

typedef uint16_t UChar;
typedef int32_t UChar32;

namespace WTF {
namespace Unicode {

enum Direction {
    LeftToRight = 0,
    RightToLeft,
    EuropeanNumber,
    EuropeanNumberSeparator,
    EuropeanNumberTerminator,
    ArabicNumber,
    CommonNumberSeparator,
    BlockSeparator,
    SegmentSeparator,
    WhiteSpaceNeutral,
    OtherNeutral,
    LeftToRightEmbedding,
    LeftToRightOverride,
    RightToLeftArabic,
    RightToLeftEmbedding,
    RightToLeftOverride,
    PopDirectionalFormat,
    NonSpacingMark,
    BoundaryNeutral,
};

enum DecompositionType {
    DecompositionNone = 0,
    DecompositionCanonical,
    DecompositionCompat,
    DecompositionCircle,
    DecompositionFinal,
    DecompositionFont,
    DecompositionFraction,
    DecompositionInitial,
    DecompositionIsolated,
    DecompositionMedial,
    DecompositionNarrow,
    DecompositionNoBreak,
    DecompositionSmall,
    DecompositionSquare,
    DecompositionSub,
    DecompositionSuper,
    DecompositionVertical,
    DecompositionWide,
};

enum CharCategory {
    NoCategory = 0,
    Mark_NonSpacing = 0x00000001,
    Mark_SpacingCombining = 0x00000002,
    Mark_Enclosing = 0x00000004,
    Number_DecimalDigit = 0x00000008,
    Number_Letter = 0x00000010,
    Number_Other = 0x00000020,
    Separator_Space = 0x00000040,
    Separator_Line = 0x00000080,
    Separator_Paragraph = 0x00000100,
    Other_Control = 0x00000200,
    Other_Format = 0x00000400,
    Other_Surrogate = 0x00000800,
    Other_PrivateUse = 0x00001000,
    Other_NotAssigned = 0x00002000,
    Letter_Uppercase = 0x00004000,
    Letter_Lowercase = 0x00008000,
    Letter_Titlecase = 0x00010000,
    Letter_Modifier = 0x00020000,
    Letter_Other = 0x00040000,
    Punctuation_Connector = 0x00080000,
    Punctuation_Dash = 0x00100000,
    Punctuation_Open = 0x00200000,
    Punctuation_Close = 0x00400000,
    Punctuation_InitialQuote = 0x00800000,
    Punctuation_FinalQuote = 0x01000000,
    Punctuation_Other = 0x02000000,
    Symbol_Math = 0x04000000,
    Symbol_Currency = 0x08000000,
    Symbol_Modifier = 0x10000000,
    Symbol_Other = 0x20000000
};

inline UChar32 foldCase(UChar32 c)
{
    return towlower(c);
}

inline int foldCase(UChar* result, int resultLength, const UChar* src, int srcLength, bool* error)
{
    *error = false;
    if (resultLength < srcLength) {
        *error = true;
        return srcLength;
    }
    for (int i = 0; i < srcLength; ++i)
        result[i] = foldCase(src[i]);
    return srcLength;
}

inline SpecialProperties specialCasingRule(UChar c)
{
    for (int i = 0; i < 103; i++)
        if (c == SpecialCasingTable[i].codePoint)
            return SpecialCasingTable[i];

    return (SpecialProperties){ 0, 0, 0, 0 };
}

inline UChar convertToLower(UChar c)
{
    for (int i = 0; i < 856; i++)
        if (c == (LowerTable[i] >> 16))
            return LowerTable[i] & 0x0000FFFF;

    return c;
}

inline int toLower(UChar* result, int resultLength, const UChar* src, int srcLength, bool* error)
{
    const UChar* srcIterator = src;
    const UChar* srcEnd = src + srcLength;
    UChar* resultIterator = result;
    UChar* resultEnd = result + resultLength;

    int remainingCharacters = 0;
    if (srcLength <= resultLength)
        while (srcIterator < srcEnd) {
            SpecialProperties props = specialCasingRule((UChar)(*srcIterator));
            if (props.codePoint) {
                if (*srcIterator < 0x10000) {
                    for (int i = 0; i < props.lowerLength; i++)
                        *resultIterator++ = props.lowerCase[i];

                    if (srcLength == resultLength)
                        remainingCharacters += props.lowerLength - 1;

                    *srcIterator++;
                } else {
                    // surrogate?
                    *srcIterator++;
                }
            } else
                *resultIterator++ = convertToLower(*srcIterator++);
        }
    else
        while (resultIterator < resultEnd)
            *resultIterator++ = convertToLower(*srcIterator++);

    if (srcIterator < srcEnd)
        remainingCharacters += srcEnd - srcIterator;

    *error = !!remainingCharacters;

    if (resultIterator < resultEnd)
        *resultIterator = 0;

    // LOGE(">>> resultIterator = %u", (uint)resultIterator);
    // LOGE(">>> result = %u", (uint)result);
    // LOGE(">>> remainingCharacters = %d", remainingCharacters);
    // LOGE(">>> return = %d", (resultIterator - result) + remainingCharacters);

    return (resultIterator - result) + remainingCharacters;
}

inline UChar32 toLower(UChar32 c)
{
    return towlower(c);
}

inline UChar32 toUpper(UChar32 c)
{
    return towupper(c);
}

inline UChar convertToUpper(UChar c)
{
    for (int i = 0; i < 865; i++)
        if (c == (UpperTable[i] >> 16))
            return UpperTable[i] & 0x0000FFFF;

    return c;
}

// Check if ch is high surrogate and ch2 is low surrogate.
inline bool isSurrogatePair(UChar ch, UChar ch2)
{
    if (ch >= 0xD800 && ch <= 0xDBFF)
        if (ch2 >= 0xDC00 && ch2 <= 0xDFFF)
            return true;

    return false;
}

// Convert pair to 32 bit, so we can look it up in surrogate table.
// ...Since only a few surrogates exist that need casing rules it
// might be okay, for now, to hardcode the casing difference. After
// conversion, the 32 bit character must be converted back to two 16
// bit characters...
inline UChar32 surrogatePairToUChar32(UChar a, UChar b)
{
    UChar32 ch = static_cast<unsigned short>(a);
    UChar32 ch2 = static_cast<unsigned short>(b);
    return ((ch - 0xD800) << 10) + (ch2 - 0xDC00) + 0x0010000;
}

// This is called from stringProtoFuncToUpperCase in
// runtime/StringPrototype.cpp
//
// If the string contains non-ASCII 1-1 case mapping the conversion to
// upper case is easy, just iterate over the string and replace each
// uppercaseable character with its uppercase equivalent.
//
// If the string contains non-ASCII 1-n case mappings the conversion
// is a bit odd. Convert every 1-1 case mapping and keep track of the
// needed space for the 1-n case mappings. Set error to true and
// return the total needed size. The caller will then resize the
// `result` buffer and will call this function again with the resized
// buffer and previously returned length. The conversion then scans
// the entire string again making the 1-n conversions along with 1-1
// conversions.
inline int toUpper(UChar* result, int resultLength, const UChar* src, int srcLength, bool* error)
{
    const UChar* srcIterator = src;
    const UChar* srcEnd = src + srcLength;
    UChar* resultIterator = result;
    int rindex = 0;

    int remainingCharacters = 0;
    while (srcIterator <= srcEnd && rindex < resultLength) {
        SpecialProperties props = specialCasingRule(*srcIterator);
        if (props.codePoint) {
            if (*srcIterator < 0x10000) {
                for (int i = 0; i < props.upperLength; i++) {
                    if (rindex >= resultLength) {
                        remainingCharacters += props.upperLength - i + 1;
                        break;
                    }
                    resultIterator[rindex++] = props.upperCase[i];
                }
            }
        } else {
            resultIterator[rindex++] = convertToUpper(*srcIterator);
        }
        srcIterator++;
    }

    if (srcIterator < srcEnd)
        remainingCharacters += srcEnd - srcIterator;

    *error = !!remainingCharacters;

    if (rindex < resultLength)
        resultIterator[rindex] = 0;

    return rindex + remainingCharacters;
}

inline UChar32 toTitleCase(UChar32 c)
{
    return c;
}

inline bool isArabicChar(UChar32 c)
{
    return c >= 0x0600 && c <= 0x06FF;
}

inline bool isAlphanumeric(UChar32 c)
{
    return !!iswalnum(c);
}

inline bool isSeparatorSpace(int32_t c)
{
    return !(c & 0xffff0000) && isASCIISpace(static_cast<unsigned short>(c));
}

inline bool isPrintableChar(UChar32 c)
{
    return !!iswprint(c);
}

inline bool isPunct(UChar32 c)
{
    return !!iswpunct(c);
}

inline bool hasLineBreakingPropertyComplexContext(UChar32 c)
{
    return false;
}

inline bool hasLineBreakingPropertyComplexContextOrIdeographic(UChar32 c)
{
    return false;
}

inline UChar32 mirroredChar(UChar32 c)
{
    return c;
}

inline CharCategory category(int32_t c)
{
    if (c < 0)
        return NoCategory;

    if (c < 0x000000ff) {
        static const CharCategory cats[] = {
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Separator_Space, Punctuation_Other, Punctuation_Other,
            Punctuation_Other, Symbol_Currency, Punctuation_Other,
            Punctuation_Other, Punctuation_Other, Punctuation_Open,
            Punctuation_Close, Punctuation_Other, Symbol_Math,
            Punctuation_Other, Punctuation_Dash, Punctuation_Other,
            Punctuation_Other, Number_DecimalDigit, Number_DecimalDigit,
            Number_DecimalDigit, Number_DecimalDigit, Number_DecimalDigit,
            Number_DecimalDigit, Number_DecimalDigit, Number_DecimalDigit,
            Number_DecimalDigit, Number_DecimalDigit, Punctuation_Other,
            Punctuation_Other, Symbol_Math, Symbol_Math, Symbol_Math,
            Punctuation_Other, Punctuation_Other,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Punctuation_Open,
            Punctuation_Other, Punctuation_Close, Symbol_Modifier,
            Punctuation_Connector, Symbol_Modifier, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Punctuation_Open, Symbol_Math, Punctuation_Close,
            Symbol_Math, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Other_Control, Other_Control,
            Other_Control, Other_Control, Separator_Space, Punctuation_Other,
            Symbol_Currency, Symbol_Currency, Symbol_Currency, Symbol_Currency,
            Symbol_Other, Symbol_Other, Symbol_Modifier, Symbol_Other,
            Letter_Lowercase, Punctuation_InitialQuote, Symbol_Math,
            Other_Format, Symbol_Other, Symbol_Modifier, Symbol_Other,
            Symbol_Math, Number_Other, Number_Other, Symbol_Modifier,
            Letter_Lowercase, Symbol_Other, Punctuation_Other,
            Symbol_Modifier, Number_Other, Letter_Lowercase,
            Punctuation_FinalQuote, Number_Other, Number_Other,
            Number_Other, Punctuation_Other, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Symbol_Math, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Uppercase, Letter_Uppercase, Letter_Uppercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Symbol_Math, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase,
            Letter_Lowercase, Letter_Lowercase, Letter_Lowercase
        };
        assert(sizeof(cats) / sizeof(CharCategory) == 0x0100);
        return cats[c];
    }

    // FIXME: implement for the rest ...
    return NoCategory;
}

inline Direction direction(UChar32 c)
{
    return LeftToRight;
}

inline bool isLower(UChar32 c)
{
    return !!iswlower(c);
}

inline uint8_t combiningClass(UChar32 c)
{
    return 0;
}

inline DecompositionType decompositionType(UChar32 c)
{
    return DecompositionNone;
}

inline int umemcasecmp(const UChar* a, const UChar* b, int len)
{
    for (int i = 0; i < len; ++i) {
        UChar c1 = foldCase(a[i]);
        UChar c2 = foldCase(b[i]);
        if (c1 != c2)
            return c1 - c2;
    }
    return 0;
}

} }

#endif // WTF_UnicodeLibC_h
