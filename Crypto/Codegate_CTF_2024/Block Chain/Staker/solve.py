from web3 import Web3

# Connect to the RPC endpoint
rpc_endpoint = "http://43.201.150.10:8888/f37c12e8-4b56-417f-b53f-1b12ce634080"
web3 = Web3(Web3.HTTPProvider(rpc_endpoint))

# Check if connected
if web3.is_connected():
    print("Connected to the blockchain")
else:
    print("Failed to connect to the blockchain")
