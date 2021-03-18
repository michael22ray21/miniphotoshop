from copy import deepcopy

img1 = {
    'width' : 4,
    'height': 2,
    'pixels' : [
        [1, 2, 3, 9],
        [7, 3, 6, 4],
    ],
    'rgbPixels' : None,
}

img2 = {
    'width' : 4,
    'height': 2,
    'pixels' : [
        [1, 1, 1, 1],
        [2, 2, 2, 2],
    ],
    'rgbPixels' : None,
}

img3 = {
    'width' : 4,
    'height': 4,
    'pixels' : [
        [1, 2, 3, 9],
        [7, 3, 6, 4],
        [1, 1, 1, 1],
        [2, 2, 2, 2],
    ],
    'rgbPixels' : None,
}

def ZoomOut(target) :
    # zoom dengan skala 2
    img = deepcopy(target['pixels'])
    M = target['height']
    N = target['width']

    m = 0
    n = 0
    if (target['pixels'] != None) :
        for i in range(M) :
            for j in range(N) :
                if (m < M and n < N) :
                    target['pixels'][m][n] = img[i][j]
                    target['pixels'][m][n + 1] = img[i][j]
                    target['pixels'][m + 1][n] = img[i][j]
                    target['pixels'][m + 1][n + 1] = img[i][j]
                    n += 2
            m += 2
            n = 0
    pass

def ZoomIn(target) :
    # zoom dengan skala 2
    img = deepcopy(target['pixels'])
    M = target['height']
    N = target['width']
    m = 0
    n = 0
    if (target['pixels'] != None) :
        temp = [[0 for q in range(N // 2)] for p in range(M // 2)]
        for i in range(0, M, 2) :
            for j in range(0, N, 2) :
                tot = 0
                tot += target['pixels'][i][j]
                tot += target['pixels'][i][j + 1]
                tot += target['pixels'][i + 1][j]
                tot += target['pixels'][i + 1][j + 1]
                temp[i // 2][j // 2] = tot / 4
                print(temp)
        for i in range(M) :
            for j in range(N) :
                img[i][j] = temp[i // 2][j // 2]
    return img
    pass

def translate(target, m, n) :
    dummy = deepcopy(target['pixels'])
    N = target['height']
    M = target['width']
    if target['pixels'] != None :
        for i in range(N) :
            for j in range(M) :
                t_row = i - m
                t_col = j - n
                if t_row >= N or t_row < 0 or t_col >= M or t_col < 0 :
                    target['pixels'][i][j] = 0
                else :
                    target['pixels'][i][j] = dummy[t_row][t_col]

def ANDAdjustment(image1, image2) :
    if (image1['height'] == image2['height'] and image1['width'] == image2['width']) :
        if (image1['pixels'] == None and image2['pixels'] == None) :
            for i in range(image1['height']) :
                for j in range(image1['width']) :
                    for k in range(3) :
                        image1['rgbPixels'][i][j][k] = image1['rgbPixels'][i][j][k] & image2['rgbPixels'][i][j][k]
        elif (image1['pixels'] != None and image2['pixels'] != None) :
            for i in range(image1['height']) :
                for j in range(image1['width']) :
                    image1['pixels'][i][j] = image1['pixels'][i][j] & image2['pixels'][i][j]

def ORAdjustment(image1, image2) :
    if (image1['height'] == image2['height'] and image1['width'] == image2['width']) :
        if (image1['pixels'] == None and image2['pixels'] == None) :
            for i in range(image1['height']) :
                for j in range(image1['width']) :
                    for k in range(3) :
                        image1['rgbPixels'][i][j][k] = image1['rgbPixels'][i][j][k] | image2['rgbPixels'][i][j][k]
        elif (image1['pixels'] != None and image2['pixels'] != None) :
            for i in range(image1['height']) :
                for j in range(image1['width']) :
                    image1['pixels'][i][j] = image1['pixels'][i][j] | image2['pixels'][i][j]

print(img1['pixels'])
image = ZoomOut(img1)
print(img1['pixels'])