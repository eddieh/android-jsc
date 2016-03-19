#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# read from the unicode data and constuct unicode tables
#

class UnicodeDataField():
    Value = 0
    Name = 1
    Category = 2
    CombiningClass = 3
    BidiCategory = 4
    Decomposition = 5
    DecimalDigitValue = 6
    DigitValue = 7
    NumericValue = 8
    Mirrored = 9
    OldName = 10
    Comment = 11
    UpperCase = 12
    LowerCase = 13
    TitleCase = 14

code_point_count = 0
upper_case_count = 0
lower_case_count = 0

upper_table = {}
lower_table = {}

with open('UnicodeData.txt', 'r') as ucdata:
    # skip ASCII
    for _ in xrange(127):
        next(ucdata)

    for line in ucdata:
        props = line.split(';')

        code_point_count += 1

        value = int(props[UnicodeDataField.Value], 16)

        # VERIFY: only 16-bit support needed??? That's what Duktape says...
        if value >= 0x10000:
            surrogate = value - 0x10000
            high_surrogate = 0xD800 + (surrogate >> 10)
            low_surrogate = 0xDC00 + (surrogate & 0x3FF)

            #print 'Surrogate ' + str(value) + ' =  ' + str(high_surrogate) + ' & ' + str(low_surrogate)

            continue

        if not props[UnicodeDataField.UpperCase] == '':
            upper_case_count += 1
            upper_table[value] = int(props[UnicodeDataField.UpperCase], 16)

        if not props[UnicodeDataField.LowerCase] == '':
            lower_case_count += 1
            lower_table[value] = int(props[UnicodeDataField.LowerCase], 16)

# print code_point_count
print upper_case_count
print lower_case_count

# for key in sorted(upper_table.keys()):
#     print str(key) + u' u→ ' + str(upper_table[key])

# for key in sorted(lower_table.keys()):
#     print str(key) + u' l→ ' + str(lower_table[key])
