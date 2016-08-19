import libwheelpy
import time

print "import successful"

#l = libwheelpy.Wheel()

print libwheelpy

libwheelpy.startWheel()

print libwheelpy.getWheelRate()

print "queue size should be 0 ",  libwheelpy.getWheelQueueSize()

for x in range(19):
	y = 1 << x
	print x, "y is", y
	libwheelpy.pushWheelKeys(1 << x, 1 << x)

for x in range(10):
	libwheelpy.pushWheelKeys(1048575, 1048575)

for x in range(19):
	y = 1 << x
	print x, "y is", y
	libwheelpy.pushWheelKeys(1 << x, 1 << x)

for x in range(10):
	libwheelpy.pushWheelKeys(1048575, 1048575)
count = 0

while True:
	print "queue size", libwheelpy.getWheelQueueSize()

	count = count + 1
	print "loop count ", count
	time.sleep(1)