import random

# 10,000 orders generate karenge
num_orders = 10000
sides = ['B', 'S']

with open('orders.csv', 'w') as f:
    for i in range(1, num_orders + 1):
        side = random.choice(sides)
        price = random.randint(100, 200) # Price 100 se 200 ke beech
        qty = random.randint(1, 50) * 10  # Quantity 10 ke multiples mein
        f.write(f"{i},{side},{price},{qty}\n")

print(f"Done! 10,000 orders generated in orders.csv")