with open("as20000102.txt") as file:
    AS, nodes = [], []
    
    string = file.readline()
    string = file.readline()
    string = file.readline()
    string = int(string.split()[2])
    for i in range(string):
        AS += [0]
        nodes += [i]
        
    string = file.readline()
    string = file.readline()

    while True:
        string = list(map(int, file.readline().split()))
        if not string: break
        AS[string[0]] += 1
        AS[string[1]] += 1
        string = file.readline()

    AS = list(zip(AS, nodes))
    AS = sorted(AS)[::-1]

    print("TOP 10")
    for item in AS[:10]:
        print("AS #", item[1], "has", item[0], "links" if item[0] > 1 else "link")
        
        
