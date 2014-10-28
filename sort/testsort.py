import sys

prev = 0

for line in sys.stdin:
    cur = int(line)
    if cur < prev:
        print("EVIL SORT VERY BAD")
        sys.exit(0)

    prev = cur

