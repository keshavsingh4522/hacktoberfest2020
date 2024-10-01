# coding: iso-8859-1 -*-
def main():
    def a_Dijkstra(grafo,inicio,fim):
 
        antecessor = {}
        distanciaAtual = {}
        vNaoVisitados = grafo.copy()
        infinito = float("inf")
        caminho = []
        contadorF = -1

        for vertice in vNaoVisitados:
            distanciaAtual[vertice] = infinito
        distanciaAtual[inicio] = 0
        while len(vNaoVisitados)!=0:
            verticeMinimo = None
            for vertice in vNaoVisitados: 
                if verticeMinimo == None:
                    verticeMinimo = vertice
                elif distanciaAtual[vertice] < distanciaAtual[verticeMinimo]:
                    verticeMinimo = vertice
            for adjacente,distancia in grafo[verticeMinimo].items():
 
                if distancia + distanciaAtual[verticeMinimo] < distanciaAtual[adjacente]:
 
                    distanciaAtual[adjacente] = distancia + distanciaAtual[verticeMinimo]
 
                    antecessor[adjacente] = verticeMinimo
 
            vNaoVisitados.pop(verticeMinimo)
        verticeAtual = fim
        while verticeAtual != inicio:
            try:
                caminho.insert(0,verticeAtual)
                verticeAtual = antecessor[verticeAtual]
            except KeyError:
                break
        caminho.insert(0,inicio)
        if distanciaAtual[fim] == float("inf"):
            print(distanciaAtual[fim])
        else:
            print(", ".join(caminho)+", {}".format(int(distanciaAtual[fim])))
    grafo = {}
    aresta = input().split(', ')
 
    while len(aresta) == 3:
        flag = 0
        flag_1 = 0
        for i in grafo:
            if i == aresta[0]:
                flag = 1
                grafo[i].update({aresta[1]:float(aresta[2])})
            if i == aresta[1]:
                flag_1 = 2
 
        if flag != 1:     
            grafo[aresta[0]] = {aresta[1]:float(aresta[2])}
        if flag_1 != 2:    
            grafo[aresta[1]] = {}

 
        aresta = input().split(', ')
    a_Dijkstra(grafo,aresta[0],aresta[1])
if __name__ == '__main__':
    main()