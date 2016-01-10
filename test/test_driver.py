class test_driver_1:
	def __init__(self):
		pass

	def name(self):
		return "pyt1"

	def is_url_valid(self, url):
		print "is_url_valid url: ", url
		return True

	def get_content_length_for_url(self, url):
		print "get_content_length_for_url url: ", url
		return 666

	def get_block(self, url, attrs, offset, block_size):
		print "url: ", url
		print "offset: ", offset
		print "block_size: ", block_size
		print "attrs: ", attrs
		return "data"

class test_driver_3:
	pass

def get_drivers():
	return ["test_driver_1", "test_driver_2", "test_driver_3"]

