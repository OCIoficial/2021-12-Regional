n = int(input())
s = 0
ta, tb = 0, 0

cs = 0
ca = 0
for i in range(n):
	c, p, k, v = map(int, input().split(" "))
	daily_diff = k*v - c*p
	if cs + daily_diff > 0:
		cs += daily_diff
	else:
		cs = 0
		ca = i+1
	if cs > s or (cs == s and i-ca > tb-ta):
		s = cs
		ta = ca
		tb = i
		
if s == 0:
	print("IMPOSIBLE")
else:
	print(f"{ta+1} {tb+1} {s}")
