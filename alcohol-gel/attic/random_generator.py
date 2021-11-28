import sys
import random

random.seed(sys.argv[1])
lower, upper = int(sys.argv[2]), int(sys.argv[3])
positivity = int(sys.argv[4]) # 1-10 scale
n = random.randint(lower, upper+1)

inp = []
alcohol_amount = 0
up_values = 100
for i in range(n):
	amount_bought = random.randint(1, up_values)	
	alcohol_amount += amount_bought
	price_bought = random.randint(1, up_values)
	amount_sold = random.randint(1, alcohol_amount) 
	alcohol_amount -= amount_sold
	np = (positivity / 10)
	price_sold =  random.randint(int(price_bought*np), min(int(price_bought*(1 + np)), up_values))
	inp.append((amount_bought, price_bought, amount_sold, price_sold))

# print input
print(n)
for i in range(n):
	c, k, p, v = inp[i]
	print(f"{c} {k} {p} {v}")
	

