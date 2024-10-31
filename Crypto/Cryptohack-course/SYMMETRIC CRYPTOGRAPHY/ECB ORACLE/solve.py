import requests
import json
from Crypto.Util.number import long_to_bytes as ltb

def get_encrypted(plaintext):
    url = f"https://aes.cryptohack.org/ecb_oracle/encrypt/{plaintext}/"
    r = requests.get(url=url)

    cipher_text = json.loads(r.text)["ciphertext"]

    return cipher_text

len_flag = 41
cur_know = b'crypto{'
for _ in range(41):
    '''
        padding phase
    '''
    tmp = b''
    while((len(cur_know) + len(tmp) + 1) % 16):
        tmp += b'X'
    
    target = get_encrypted(tmp.hex())
    print('CACCAC', target)
    '''
        brute force phase
    '''
    char_list = b'abcdefghjiklmnopqrstuvwxyz0123456789_{}'
    for char in char_list:
        plaintext = tmp + cur_know + ltb(char)
        encrypted = get_encrypted((plaintext).hex())
        # print(encrypted[(len(plaintext) - 1) // 16 * 32 : ((len(plaintext) - 1) // 16 + 1) * 32])
        # print(target[(len(plaintext) - 1) // 16 * 32 : ((len(plaintext) - 1) // 16 + 1) * 32])
        if(encrypted[(len(plaintext) - 1) // 16 * 32 : ((len(plaintext) - 1) // 16 + 1) * 32] == target[(len(plaintext) - 1) // 16 * 32 : ((len(plaintext) - 1) // 16 + 1) * 32]):
            cur_know += ltb(char)
            break
    print(cur_know)
        