import sys
import random

random.seed(sys.argv[1])
lower, upper = int(sys.argv[2]), int(sys.argv[3])
n = random.randint(lower, upper+1)
positivity = int(sys.argv[4]) # 1-20 scale
np = (positivity / 10) # normalized

inp = []
acc_amount = 0
up_values = 10 # this generates more intervals with the same value
for i in range(n):
	amount_bought = random.randint(up_values//3, up_values)	
	acc_amount += amount_bought
	price_bought = random.randint(1, up_values)
	amount_sold = random.randint(1, min(up_values,int((1.1+np)*amount_bought), acc_amount, int((0.7 + np)*acc_amount)))
	acc_amount -= amount_sold
	price_sold =  random.randint(min(int(price_bought*np), up_values), min(int(price_bought*(0.7 + np)), up_values))
	inp.append((amount_bought, price_bought, amount_sold, price_sold))

# print input
print(n)
for i in range(n):
	c, k, p, v = inp[i]
	print(f"{c} {k} {p} {v}")
	

