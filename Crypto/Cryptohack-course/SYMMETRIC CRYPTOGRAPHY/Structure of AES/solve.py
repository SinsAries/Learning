from Crypto.Util.number import long_to_bytes as ltb
def bytes2matrix(text):
    """ Converts a 16-byte array into a 4x4 matrix.  """
    return [list(text[i:i+4]) for i in range(0, len(text), 4)]

def matrix2bytes(matrix):
    """ Converts a 4x4 matrix into a 16-byte array.  """
    res = b''
    for i in range(4):
        for j in range(4):
            res += ltb(matrix[i][j])
    return res

matrix = [
    [99, 114, 121, 112],
    [116, 111, 123, 105],
    [110, 109, 97, 116],
    [114, 105, 120, 125],
]

res = matrix2bytes(matrix)

print(res)

print(type(matrix[-1]))
#b'crypto{inmatrix}'