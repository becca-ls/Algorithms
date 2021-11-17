//busca em profundidade
//funcao basica que procura o maior caminho no grafo

void dfs(int i) {
  count++;
  visitei[i] = 1;
  for (auto next : vizinhos[i]) {
     if (!visitei[next]) {
        dfs(next, count);
     }
  }
  maior_caminho = max(maior_caminho,count);
  count--;
  visitei[i] = 0;
}
