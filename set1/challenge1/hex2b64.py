#!/bin/python
import binascii
import base64

text = raw_input('Enter hex encoded string: ')
raw = binascii.unhexlify(text)
encoded = base64.b64encode(raw)
print('Output: {}'.format(encoded))
