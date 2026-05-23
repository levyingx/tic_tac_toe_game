Projeto da segunda unidade da disciplina DIM0320 - Algoritmo e Programação de Computadores.

## Jogo da Velha

Implementação do clássico jogo da velha em C.

### Compilação e Execução

```bash
bash run.sh
```

ou compile manualmente:

```bash
gcc -I./header -o ./bin/main ./src/main.c ./src/utils.c
./bin/main
```

### Estrutura

- `src/main.c` - Lógica principal do jogo
- `src/utils.c` - Funções utilitárias
- `header/utils.h` - Declarações das funções
- `bin/` - Executável compilado