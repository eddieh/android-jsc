#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# read from the unicode data and constuct unicode tables
#

import sys
emit = sys.stdout.write

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

class SpecialCasingField():
    Code = 0
    LowerCase = 1
    TitleCase = 2
    UpperCase = 3
    ConditionList = 4

upper_table = {}
lower_table = {}

surrogate_upper_table = {}
surrogate_lower_table = {}

# =============================================================================
# Unicode Data
# =============================================================================
with open('UnicodeData.txt', 'r') as ucdata:
    # skip ASCII
    for _ in xrange(127):
        next(ucdata)

    for line in ucdata:
        props = line.split(';')

        value = int(props[UnicodeDataField.Value], 16)

        if value >= 0x10000:
            surrogate = value - 0x10000
            high_surrogate = 0xD800 + (surrogate >> 10)
            low_surrogate = 0xDC00 + (surrogate & 0x3FF)

            #print 'Surrogate ' + str(value) + ' =  ' + str(high_surrogate) + ' & ' + str(low_surrogate)

            if not props[UnicodeDataField.UpperCase] == '':
                surrogate_upper_table[value] = int(props[UnicodeDataField.UpperCase], 16)

            if not props[UnicodeDataField.LowerCase] == '':
                surrogate_lower_table[value] = int(props[UnicodeDataField.LowerCase], 16)

            continue

        if not props[UnicodeDataField.UpperCase] == '':
            upper_table[value] = int(props[UnicodeDataField.UpperCase], 16)

        if not props[UnicodeDataField.LowerCase] == '':
            lower_table[value] = int(props[UnicodeDataField.LowerCase], 16)

#print len(upper_table)
#print len(lower_table)

flat_upper_table = []
for key in sorted(upper_table.keys()):
    #print str(key) + u' u→ ' + str(upper_table[key])

    # combine both 16bit lower case and upper case values into a
    # single 32 bit value
    packed = (key << 16) | upper_table[key]
    flat_upper_table.append(packed)

flat_lower_table = []
for key in sorted(lower_table.keys()):
    #print str(key) + u' l→ ' + str(lower_table[key])

    # combine both 16bit upper case and lower case values into a
    # single 32 bit value
    packed = (key << 16) | lower_table[key]
    flat_lower_table.append(packed)

# build C array and output it to a header file
def emit_upper_table():
    value_count_per_line = 0
    emit('uint32_t UpperTable[' + str(len(flat_upper_table)) + '] = {\n')
    for i, value in enumerate(flat_upper_table):
        if value_count_per_line == 0:
            emit('    ' + str(value) + 'u')
        elif value_count_per_line < 5:
            emit(', ' + str(value) + 'u')
        else:
            emit(', ' + str(value) + 'u')
            if i < len(flat_upper_table):
                emit(',\n')
                value_count_per_line = 0
            continue

        value_count_per_line += 1
    emit('\n};\n')

emit_upper_table()
#print surrogate_upper_table
#print surrogate_lower_table

# =============================================================================
# Special Casing
# =============================================================================

special_casing = []
max_n = 0

with open('SpecialCasing.txt', 'r') as ucdata:

    for line in ucdata:
        # skip comments & blank lines
        if line[0] == '#' or line[0] == '\n':
            continue

        props = line.split(';')

        # we only care about non-conditionals
        if len(props) == 5:
            title_case = props[SpecialCasingField.TitleCase].strip().split(' ')
            if len(title_case) > max_n:
                max_n = len(title_case)

            upper_case = props[SpecialCasingField.UpperCase].strip().split(' ')
            if len(upper_case) > max_n:
                max_n = len(upper_case)

            special_casing.append({
                'codePoint': props[SpecialCasingField.Code].strip(),
                'lowerCase': props[SpecialCasingField.LowerCase].strip().split(' '),
                'titleCase': title_case,
                'upperCase': upper_case
            })

# print max_n

# for s in special_casing:
#     print s

# build C array and output it to a header file
def emit_special_casing_table():
    emit('SpecialProperties SpecialCasingTable[' + str(len(special_casing)) + '] = {\n')
    for i, element in enumerate(special_casing):
        emit('    { 0x' + element['codePoint'] + ', ')
        emit(str(len(element['lowerCase'])) + ', ')
        emit(str(len(element['titleCase'])) + ', ')
        emit(str(len(element['upperCase'])) + ', ')
        emit('{ ')
        for j, cp in enumerate(element['lowerCase']):
            emit('0x' + cp)
            if j < len(element['lowerCase']) - 1:
                emit(', ')
        emit(' }, { ')
        for j, cp in enumerate(element['titleCase']):
            emit('0x' + cp)
            if j < len(element['titleCase']) - 1:
                emit(', ')
        emit(' }, { ')
        for j, cp in enumerate(element['upperCase']):
            emit('0x' + cp)
            if j < len(element['upperCase']) - 1:
                emit(', ')
        emit(' } }')
        if i < len(special_casing) - 1:
            emit(',')
        emit('\n')
    emit('};\n')

#emit_special_casing_table()
