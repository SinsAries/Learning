import os
import random
from Crypto.Cipher import AES
from Crypto.Util import Counter
from Crypto.Hash import SHA256
from secret import FLAG

flag1 = FLAG[:len(FLAG)//3].encode()
flag2 = FLAG[len(FLAG)//3:2*len(FLAG)//3].encode()
flag3 = FLAG[2*len(FLAG)//3:].encode()

assert len(flag1) == len(flag2) == len(flag3) == 48

def pad(data, block_size):
    return data + (block_size - len(data) % block_size) * bytes([block_size - len(data) % block_size])


def challenge_part1(flag):
    key = os.urandom(16)
    iv = os.urandom(16)
    options = ['ecb', 'cbc', 'cfb', 'ofb', 'ctr']
    suboptions = ['data', 'flag']

    for _ in range(3):  # you only have 3 tries, stingy huh?
        [option, suboption, *more] = input('> ').split(' ')
        if option not in options:
            print('invalid option!')
            continue 
        if suboption not in suboptions:
            print('invalid suboption!')
            continue
        options.remove(option)

        if suboption == 'data':
            message = bytes.fromhex(more[0])
        else:
            message = flag

        if option == 'ecb':
            cipher = AES.new(key, AES.MODE_ECB)
        elif option == 'cbc':
            cipher = AES.new(key, AES.MODE_CBC, iv)
        elif option == 'cfb':
            cipher = AES.new(key, AES.MODE_CFB, iv, segment_size=128)
        elif option == 'ofb':
            cipher = AES.new(key, AES.MODE_OFB, iv)
        elif option == 'ctr':
            cipher = AES.new(key, AES.MODE_CTR,
                             counter=Counter.new(16, prefix=iv[:14]))

        ciphertext = cipher.encrypt(message)
        print(ciphertext.hex())
    else:
        print('No more options!')


def challenge_part2(flag):
    key = os.urandom(16)

    while True:
        try:
            options = input('> ').split(' ')
            if (options[0] == "encrypt_flag"):
                iv = os.urandom(16)
                cipher = AES.new(key, AES.MODE_GCM, iv)
                message = flag
                ciphertext= cipher.encrypt(message)
                print("Encrypted flag and tag, iv:", ciphertext.hex(), iv.hex())

            elif (options[0] == "encrypt_data"):
                iv = bytes.fromhex(options[1])
                cipher = AES.new(key, AES.MODE_GCM, iv)
                message = bytes.fromhex(input('input data:'))
                ciphertext= cipher.encrypt(message)
                print("Encrypted message and tag, iv:", ciphertext.hex(), iv.hex())
            else:
                print("Invalid option!")
        except Exception as e:
            print("An error occurred: ", e)
            break


def challenge_part3(flag):
    try:
        salt = os.urandom(2) # prevent rainbow table attack and ... brute force attack?
        password_file_path = os.path.join(os.path.dirname(__file__), "rockyou.txt") # rockyou.txt is a list of common passwords
        print(f"Looking for rockyou.txt at: {password_file_path}")

        if not os.path.isfile(password_file_path):
            print(f"Error: {password_file_path} not found")
            return

        with open(password_file_path, "rb") as file:
            passwords = file.readlines()[:100]

        password = random.choice(passwords).strip()
        key = SHA256.new(password + salt.hex().encode()).digest()[:16]
        cipher = AES.new(key, AES.MODE_ECB)
        ciphertext = cipher.encrypt(pad(password, 16))
        print("Encrypted password:", ciphertext.hex())

        input_password = input('input password:')
        if input_password.encode() == password:
            print("Correct password!")
            print("Good job! Here is your flag:", flag)
        else:
            print("Incorrect password!")

    except FileNotFoundError:
        print("rockyou.txt not found")
        return
    except Exception as e:
        print(f"An error occurred: {e}")
        return


def main():
    chall_option = input('challenge option:')
    if chall_option == '1':
        challenge_part1(flag1)
    elif chall_option == '2':
        challenge_part2(flag2)
    elif chall_option == '3':
        challenge_part3(flag3)
    else:
        print('Invalid option!')


if __name__ == '__main__':
    main()
