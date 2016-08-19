from ctypes import cdll
lib = cdll.LoadLibrary('./libwheel.so')

class Wheel(object):
	def __init__(self):
		self.obj = lib.PlayerApi()

	def startWheel():
		lib.startWheel(self.obj)

	def getWheelRate():
		return lib.getWheelRate(self.obj)

	def getWheelQueueSize():
		return lib.getWheelQueueSize()

	def pushWheelKeys(pKey1, pKey2):
		lib.getWheelQueueSize(self.obj, pKey1, pKey2)