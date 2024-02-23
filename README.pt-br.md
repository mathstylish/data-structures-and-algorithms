[![en](https://img.shields.io/badge/lang-en-red.svg)](https://github.com/mathstylish/data-structures-and-algorithms/blob/main/README.md)
# Estrutura de dados e algoritmos

O objetivo deste repositório é guardar como referência de estudo, a implementação das estruturas e algoritmos que geralmente você aprende nesta disciplina. A linguagem que irei utilizar é C, devido a pelo menos dois pontos que **EU** acho didaticamente interessante:

- **Simplicidade e clareza**: A sintaxe da linguagem C é relativamente simples,  o que facilita a compreensão. Apenas pela leitura do código, você consegue ter uma noção do que está sendo feito e isso fará com que você foque mais nos conceitos da disciplina do que nos detalhes da linguagem em si.

- **Controle de memória**: A linguagem C requer que os programadores gerenciem explicitamente a memória, usando funções como `malloc()` e `free()`. Isso possibilita entender como a memória é **alocada** e **liberada** para diferentes estruturas de dados.

**Nota**: Embora a linguagem C tenha suas vantagens ao aprender estruturas de dados e algoritmos, é importante ressaltar que você consegue aprender estes conceitos em qualquer linguagem. O que irá mudar é somente a linguagem e como é feita as operações na mesma.

## Estrutura do repositório
 - Diretório de código-fonte e testes, por ex: `LinkedList/`
 - Nos diretórios do código-fonte, há um arquivo `.h` e um arquivo `.c`, por exemplo, `LinkedList/Singly/singly.h` e `LinkedList/Singly/singly.c`. `.h` é um arquivo de cabeçalho contendo macros, estruturas e declarações de funções que implementaremos no arquivo `.c`.

## Como executar os exemplos?
Primeiramente, você precisa das seguintes dependências: `gcc`, `make`. Em seguida, compile o código-fonte, por exemplo: `gcc -o LinkedList/Singly/test LinkedList/Singly/singly.c LinkedList/Singly/main.c` e execute com `./LinkedList/Singly/test`. O sinalizador -o indica onde a saída executável da compilação será gerada, `test` é o nome do arquivo executável. Nomeie como quiser.
 
