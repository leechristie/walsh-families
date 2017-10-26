def rank(f):
    r = [0, 0, 0, 0, 0, 0, 0, 0]
    for x in range(8):
        for y in range(8):
            if y != x:
                if f[y] > f[x]:
                    r[x] = r[x] + 1
    return tuple(r)

def output(r):
    print(str(r).replace(",", "").replace("(", "").replace(")", ""))

if __name__ == "__main__":
    seen = set()
    for a in range(8):
        for b in range(8):
            for c in range(8):
                for d in range(8):
                    for e in range(8):
                        for f in range(8):
                            for g in range(8):
                                for h in range(8):
                                    r = rank([h, g, f, e, d, c, b, a])
                                    if not r in seen:
                                        seen.add(r)
                                        output(r)
    print("END")
