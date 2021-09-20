# -*- coding: utf-8 -*-
"""
Created on Sun Jul 12 13:40:50 2020

@author: User
"""

print("Q4")
price = input("請輸入消費金額:")
age = input("請輸入年齡:")
price=int(price)
age=int(age)
if age!=50:
    if price>=50000 and price<80000:
        price=price*0.98
        print("折價後金額: %d" % price)
    elif price>=80000 and price<100000:
        price=price*0.95
        print("折價後金額: %d" % price)
    elif price>=100000:
        price=price*0.9
        print("折價後金額: %d" % price)
    else:
        print("金額: %d" % price)
else:
    if (price<100000):
        price=price*0.95
        print("折價後金額: %d" % price)
    else:
        price=price*0.9
        print("折價後金額: %d" % price)