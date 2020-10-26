def findVertices(filename):
    with open(filename) as file:
        graph = []
        node = []
        for i in range(5):
            file.readline()
        index = 0
        while True:
            source, target = list(map(int, file.readline().split()))
            node += [target]
            
            if index != source:
                if index > 0:
                    for i, vertices in enumerate(graph):
                        if source in vertices and len(vertices) * len(node) >= 100:
                            print("Vertices {} and {} are weakly connected".format(i, source))
                            return
                graph.append(node)
                node = []
                source += 1
                index += 1
        print("No weakly connected vertices")


print("File:\tas20000102.txt")
findVertices("as20000102.txt")
