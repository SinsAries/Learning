from Crypto.Util.number import getPrime
import random

leak_p = list('????0?000???0?10??000?0?00?101110??0100011??000011???111?10110100???1?0100?11??1??1?11000????11?????1?11????1111?010??11??00?1??00??1?11?0?010?1??1???0101000?00010?1?01010010000011?10?11???11001101?1?01?1????011?1110?11??1?010101??001??1?101??0???101010001?1??1?0?1?100011??10??010??1001100???0??0??0?10?0100??1?10011??1?10?00??00100110?1?0000?010011?1000??11010?110????11??000001??11??111??101????0?111??1?0?0?01000?01?1110?1??0100?1?00?00???010?0101?1101??11??1?11011?1?0??1?00110110011?0??0?0??1010?1000?101??0001??1111??000?11????0?1010??1000?0?1?0110011?0110010101?0?00001?0111?1?011000???0001??1?11110?0?1?0?101110110??111??1011100011??0?1??1???00?01?101101??110??0?000110?1????10?11?11010?111?011???01011100?01?010??01001?0001110001?0??00?1?0111?0??11?1?10?0010?1?01011001???111?1010100100111000??01??00?01??010??101??011100?01??0????11000011?010000?1001?10011101001?1??11???0??1011010?0111?100?1?0??10001100?00??0100?111?00001?1???0?1???00??00?1??1110??00??100?00011?11?1???111??0?00?111010001?1101?1?011011?0????001')
leak_q = list('11010000?01110010101?0?10?1??1?0100??0011000????00111???10?01?1?1000011???01010?1011?0???0100?000110?00?01010010001101?1110001010?0101?00?1???1?00?100010010?0??0??1010??0?1?101?11?0110100110010??1?1?1?11?1101???1?0?01100000?0??0100??10000?1001100011????01?0101?101?1?1?1??10111001?01????1?0100010?01?0??00??111?11??1?01?11101?111?1111110?11?0101??01?0??01101?11?1??000100?110000?1100?00???0011?1000?001?11111101?1?000??011011?00?0101?1??11?0010?11??001???101??00?001??1011110110?0?0?????0000110110??0?11111111?110?1100?0??111??001011111??1?01100?1?0?11?1?1?01???00?0001110??0?00????100???01?1010??11111?1?0111011?0?01???1??1011011001?1101?111?1?10?1001?00?11110?10110101000??11?0?1010011?00??1??10??1???1011??10?1?0??0?0?0010?0?0?11??1?0??1101110?10?0?0?11??1?0?0000001?00?0??0?1110???1100?000????10???0101100?0?10101?00?1?10?1?0010??11?1000??1???0110?101?1??1?010???00110?001111001?1010?001001?0?0?110?0?10?????0??0??011001010?1?0??01?111?10001?011?00?10????10??10?1?0?10??01?1?101?011001??01?1010??111???1111?1??01?0101?11')
N = 23475894821547906362591240717529099067158327696822707510594687907553243723131628550588911499180799017122662509008947306529693724907909747833546695761812612497580980259048493004571948156229024641943060955057810792942194281261040086661818314583309826436690562807668680383829451619501440919946869921145191396278137706351088703550043583346714505228358129311768048479401319909376472815099538429452698167698953576821399392095097069099076469255814080227915172166738365212667347362498261561749350559913713016561214777994226754532045253404397503792990674139536753696221900894666211573694334828906501517116587797207260004288427
N = list(bin(N)[2:])

def mul2bin(a, b, target):
    a = a[::-1]
    b = b[::-1]
    target = target[::-1]

    print(a)
    print(b)

    res = [[] for _ in range(len(a) + len(b))]
    for i in range(len(a)):
        for j in range(len(b)):
            if(a[i] == '0' or b[j] == '0'):
                continue

            if(a[i] == '1' and b[j] == '1'):
                res[i + j].append('1')
                continue
            if(a[i] == '?' and b[j] == '?'):
                res[i + j].append(str(i + 2) + '*' + str(j + 2))
                continue
            if(a[i] == '?' and b[j] == '1'):
                res[i + j].append(str(i + 2) + '*1')
                continue
            if(a[i] == '1' and b[j] == '?'):
                res[i + j].append('1*' + str(j + 2))
                continue
    for i in range(100):
        print(res[i])
    
mul2bin(leak_p, leak_q, N)

