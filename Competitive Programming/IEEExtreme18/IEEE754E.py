import struct

def hex_to_float(hex_value):
    """Converts a hexadecimal string to IEEE 754 floating-point value."""
    int_value = int(hex_value, 16)
    sign = (int_value >> 31) & 1
    exponent = (int_value >> 23) & 0xFF
    mantissa = int_value & 0x7FFFFF

    # If exponent is all ones, return NaN or Inf
    if exponent == 0xFF:
        if mantissa == 0:
            return float('-inf') if sign else float('inf')
        return float('nan')

    # Handle zero
    if exponent == 0 and mantissa == 0:
        return 0.0

    # Normalize the exponent and mantissa
    exponent -= 127
    mantissa = 1 + mantissa / (1 << 23)

    # Apply the sign
    return (-1) ** sign * mantissa * (2 ** exponent)

def float_to_hex(value):
    """Converts a floating-point number to a hexadecimal IEEE 754 representation."""
    if isinstance(value, float):
        return hex(struct.unpack('<I', struct.pack('<f', value))[0])[2:].zfill(8)
    else:
        return hex(value)[2:].zfill(8)

def perform_fma(a, b, c):
    """Performs Fused Multiply Add: a * b + c in IEEE 754."""
    return a * b + c

def perform_nand(a, b):
    """Performs NAND operation on two integers."""
    a_int = struct.unpack('<I', struct.pack('<f', a))[0] if isinstance(a, float) else a
    b_int = struct.unpack('<I', struct.pack('<f', b))[0] if isinstance(b, float) else b
    return ~(a_int & b_int) & 0xFFFFFFFF

def execute_commands(test_cases):
    results = []
    for case in test_cases:
        C = []
        commands = case['commands']

        for command in commands:
            if command['type'] == 'C':
                h = command['params'][0]
                C.append(hex_to_float(h))
            elif command['type'] == 'F':
                i, j, k = command['params']
                C.append(perform_fma(C[i], C[j], C[k]))
            elif command['type'] == 'N':
                i, j = command['params']
                C.append(perform_nand(C[i], C[j]))

        if C:
            last_value = C[-1]
            results.append(float_to_hex(last_value))

    return results

# Read input and initialize test cases
with open('file.in', 'r') as f:
    data = f.read().strip().splitlines()

index = 0
T = int(data[index])
index += 1
test_cases = []

while index < len(data):
    case = {}
    
    # Read the constant value (ignore it for processing)
    constant_value = data[index].strip()  # Read constant value
    index += 1
    
    if index >= len(data):
        print("Warning: Expected more data after the constant value.")
        break

    # Read number of commands
    L = int(data[index].strip())  # Ensure we read an integer
    index += 1
    case['commands'] = []

    for __ in range(L):
        if index >= len(data):
            print("Warning: Expected more commands but reached end of input.")
            break
            
        command_line = data[index].strip().split()
        cmd_type = command_line[0]

        if cmd_type == 'C':
            h = command_line[1]
            case['commands'].append({'type': 'C', 'params': [h]})
        elif cmd_type == 'F':
            i, j, k = map(int, command_line[1:])
            case['commands'].append({'type': 'F', 'params': [i, j, k]})
        elif cmd_type == 'N':
            i, j = map(int, command_line[1:])
            case['commands'].append({'type': 'N', 'params': [i, j]})

        index += 1

    test_cases.append(case)

# Execute commands and print results
results = execute_commands(test_cases)
for result in results:
    print(result)
