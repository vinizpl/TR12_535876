## Pré-requisito
Para compilar e executar o código é necessario que tenha instalado o GCC ou G++. Com algum deles instalados, resta a você baixar o código, para fazer isso:

baixe o projeto [aqui](https://github.com/Gabriel-Sao-Pedro/TR12_537643/archive/refs/heads/main.zip)

## Instalação
É necessario que os arquivos estejam na mesma pasta para que a compilação ococrra.

### Gerando a biblioteca
Como gerar a biblioteca para usar no seu código

Execute:

```
gcc -c heap.c 
```

Será gerado um arquivo chamado heap.o

Exemplo de como compilar junto com seu código:

```
gcc main.c heap.o -o nome_do_programa
```
