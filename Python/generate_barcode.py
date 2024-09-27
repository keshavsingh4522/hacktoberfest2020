from barcode import EAN13

from barcode.writer import ImageWriter
number = '5768689569595'
my_code = EAN13(number, writer=ImageWriter())
my_code.save("barcode")