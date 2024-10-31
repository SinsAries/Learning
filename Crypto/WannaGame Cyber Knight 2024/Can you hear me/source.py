from Crypto.Util.number import *
from string import *
import signal
from random import randint
from ecc import *

flag = open("private/flag").read()

def timeout_handler(sig, frame):
    print('Too much time to make a decision!')
    exit(0)

def layer_1(m):
    command = getPrime(25)
    cast = lambda x: x * command
    return cast(m) ^ getPrime(10)

def layer_2(m, G):
    P = m * G
    return P.compress()
    
def generate_reward(a, b):
    p = 3750359746363913632432094873994878181149630487509142147997235788789731672605587125585450594856509062654065763831869624930882612562313187796447467616599725587908947137057125551043
    assert a % p != 0 
    assert b % p != 0
    while True:
        try:
            xG = randint(1, p-1)
            yG = evaluate(xG, a, b, p)
            E = Curve(p, a, b)
            G = Point(E, xG, yG)
            assert (G.y**2) % p == (G.x**3 + a * G.x + b) % p
            return E, G
        except:
            continue

BANNER = """
  ____             __   __            _   _                   __  __     ___
 / ___|__ _ _ __   \ \ / /__  _   _  | | | | ___  __ _ _ __  |  \/  | __|__ \\
| |   / _` | '_ \   \ V / _ \| | | | | |_| |/ _ \/ _` | '__| | |\/| |/ _ \/ /
| |__| (_| | | | |   | | (_) | |_| | |  _  |  __/ (_| | |    | |  | |  __/_|
 \____\__,_|_| |_|   |_|\___/ \__,_| |_| |_|\___|\__,_|_|    |_|  |_|\___(_)
"""
def banner():
    global BANNER
    print(BANNER, end="\n\n\n")

def menu():
    print("""What will you do ?
1. Choose the curve as your reward
2. Try to hear inside the room
3. Enter the password to open room
4. Go away (pls don't do it)""")
    return int(input("> "))

def challenge():
    chance_to_hear = 10
    set_curve = True
    alphabet = ascii_letters + digits
    password = "".join(alphabet[randint(0, len(alphabet))] for i in range(24))

    signal.alarm(120)
    banner()
    while True:
        choice = menu()

        if choice == 1:
            if set_curve:
                a, b = [int(num) for num in input("Let me know what you want: ").split(",")]
                try:
                    _, G = generate_reward(a, b)
                except:
                    print("The door didn't say anything, maybe thing you want is dangerous with it...")
                    exit()
                print(f"You can see your reward on the door: {G.compress()}")
                print("What will you do with your reward?")
                set_curve = False
            else:
                print("Only one chance to get reward!")

        elif choice == 2:
            if set_curve:
                print("You should get reward to go further...")
                continue
            if chance_to_hear == 0:
                sound = layer_2(layer_1(bytes_to_long(password.encode())), G)
                print(f"Now you can't hear anything")
            else:
                sound = layer_2(layer_1(bytes_to_long(password.encode())), G)
                chance_to_hear -= 1
                print(f"From inside the room, you hear {sound}")

        elif choice == 3:
            guess = input("The password that you wanna try is: ")
            if guess == password:
                print("You open the door, and the flag is inside the room! Turn out it tried to give you password to open the door.")
                print(f"Its name is {flag.decode()}")
                exit()
            else:
                print("Your password is wrong, and the door doesn't give you any change to reset...")
                exit()
    
        elif choice == 4:
            print("Maybe you will lost something really rare...")
            exit()

        else:
            print("You don't have this decision!")


if __name__ == "__main__":
    signal.signal(signal.SIGALRM, timeout_handler)
    try:
        challenge()
    except:
        pass
