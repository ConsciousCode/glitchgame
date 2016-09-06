import sys

w = int(sys.argv[1])
h = int(sys.argv[2])

f = open("test.map", "wb")

f.write(b''.join(
	b''.join(b'\1' if x%2 else b'\0' for x in range(w)) if y%2 else
	b''.join(b'\0' if x%2 else b'\1' for x in range(w))
	
	for y in range(h)
))

f.close()
