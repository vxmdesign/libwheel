from ctypes import *
lib = cdll.LoadLibrary('./libwheel.so')

# class Wheel(object):
# 	def __init__(self):
# 		#self.obj = lib.PlayerApi()
# 		pass
lib.getWheelRate.restype=c_double

def startWheel():
	lib.startWheel()
	print 'starting wheel'

def getWheelRate():
	return lib.getWheelRate()
	


def getWheelQueueSize():
	return lib.getWheelQueueSize()

def pushWheelKeys(pKey1, pKey2):
	lib.pushWheelKeys( pKey1, pKey2)

def setNumber(val):
	lib.setNumber(int(val))

def getNumber():
	return lib.getNumber()

	