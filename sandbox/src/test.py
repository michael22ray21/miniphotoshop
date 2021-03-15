import image_processing as im


size = 0
data = im.fileLoader('../images/sample.raw', size)
raw = im.RAW(data, size)