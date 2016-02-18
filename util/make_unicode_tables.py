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

with open('UnicodeData.txt', 'r') as ucdata:
    # skip ASCII
    for _ in xrange(127):
        next(ucdata)

    for line in ucdata:
        props = line.split(';')

        code_point_count += 1

        if not props[UnicodeDataField.UpperCase] == '':
            upper_case_count += 1
            #print props[UnicodeDataField.Value] + u' → ' + props[UnicodeDataField.UpperCase]

            #print int(props[UnicodeDataField.Value], 16)
            print props[UnicodeDataField.Value]

        if not props[UnicodeDataField.LowerCase] == '':
            lower_case_count += 1
            #print props[UnicodeDataField.Value] + u' → ' + props[UnicodeDataField.LowerCase]

            #print int(props[UnicodeDataField.Value], 16)
            print props[UnicodeDataField.Value]

# print code_point_count
# print upper_case_count
# print lower_case_count
