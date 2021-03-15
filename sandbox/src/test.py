import image_processing as im

filename = '../images/sample.raw'
raw = im.RAW(filename)
print(raw.fileSize)