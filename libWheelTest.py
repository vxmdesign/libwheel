import libwheelpy
import time

print "import successful"

#l = libwheelpy.Wheel()

print libwheelpy

libwheelpy.startWheel()

print libwheelpy.getWheelRate()

print "queue size shoudl be 0 ",  libwheelpy.getWheelQueueSize()

libwheelpy.pushWheelKeys(1, 2)
libwheelpy.pushWheelKeys(3, 4)
libwheelpy.pushWheelKeys(5, 6)
libwheelpy.pushWheelKeys(7, 8)
libwheelpy.pushWheelKeys(9, 10)

libwheelpy.setNumber(3)

print "number", libwheelpy.getNumber()

print "queue size should be 5 ", libwheelpy.getWheelQueueSize()

count = 0

while True:
	print "Rate ", libwheelpy.getWheelRate()
	libwheelpy.pushWheelKeys(1, 2)
	libwheelpy.pushWheelKeys(3, 4)
	print "Rate ",  libwheelpy.getWheelRate()
	print "queue size", libwheelpy.getWheelQueueSize()
	count = count + 1
	print "cound", count
	time.sleep(1)
