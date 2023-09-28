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
Primeiramente, você precisa das seguintes dependências: `gcc`, `make`. Eu ensino como fazer as instalações dessas ferramentas no [desafio](#desafio) que eu propus. Lá tem exemplos de como instalar.

Em seguida, compile o código-fonte, por exemplo: `gcc -o LinkedList/Singly/test LinkedList/Singly/singly.c LinkedList/Singly/main.c` e execute com `./LinkedList/Singly/test`. O sinalizador -o indica onde a saída executável da compilação será gerada, `test` é o nome do arquivo executável. Nomeie como quiser.
  
## Como instalar?
Se você está aqui, vou supor que está cursando Ciências da Computação, Engenharia da Computação ou algo relacionado. Se não estiver, não tem problema. No entanto, é importante que você tenha a habilidade de pesquisar e aprender por si mesmo. Programadores devem ser capazes de buscar soluções e resolver problemas de forma autônoma. É natural buscar uma ajudinha ocasional, mas não se torne aquela pessoa que pergunta tudo sem tentar resolver nada sozinho. Já vi pessoas perguntando coisas que poderiam facilmente ser resolvidas com uma simples pesquisa.

É essencial que você saiba como pesquisar e instalar as ferramentas específicas da sua área, como as citadas anteriormente. Isso pode ser feito facilmente abrindo uma nova aba no navegador e buscando por tutoriais e guias de instalação.

Mas para ajudar você a começar, abordarei superficialmente o mínimo que você precisa entender para utilizar o seu computador de forma mais eficiente como programador:

- **Variáveis de ambiente**: Permite "dizer" para o sistema operacional ou programas, o local onde reside ferramentas, arquivos de configuração, etc. Também permite que os mesmos sejam acessados em todo o sistema operacional ou um usuário específico. Há programas que precisam dessas variáveis de ambiente configuradas para que eles localizem ou saibam o que usar no seu ambiente.

- **Emuladores de terminal, shells**: Lembra quando você era adolescente e executava o comando `ipconfig` no **Prompt de Comando/CMD** e se sentia um hacker/cracker? Caso você tenha feito isso, você interagiu com um **emulador de terminal** e o comando `ipconfig` foi interpretado (entenda como "entendido") por um **shell** que executou o comando.

  As tarefas que você realiza utilizando clique de mouse, arrastar de janela, dentro outros, são apenas facilitadores para que você não tenha que ficar executando comandos e passando argumentos diretamente na linha de comando. Mas como programador você deve aprender pelo menos uma dúzia ou mais de comandos para resolver problemas, conseguir informações como: **"Qual programa/processo está executando na porta 8080, que está atrapalhando a inicialização do meu servidor web?"**.

- **Sintaxe de comandos de shell**: Todo comando em shell tem mais ou menos a seguinte estrutura: `comando [ação] [parâmetros] [argumentos]`. Os comandos podem ter uma **ação**, que especifica o que aquele **comando** vai realizar, porém existem comandos que não tem **ação**, porque o **comando** em si já é uma **ação**. Os **parâmetros** podem ser **obrigatórios** ou **opcionais**, assumindo **valores** ou **comportamentos padrões**, caso você não os defina **explicitamente**. O número de **argumentos** pode variar e existem comandos que não recebem **argumentos** explicitamente.

  Vou utilizar dois exemplos para ilustrar, com um comando abstrato chamado `cortarfruta` e também usarei alguns exemplos reais de comando que você provavelmente vai ver e usar.

  - `cortarfruta --corte=fatiar --pedaços 8 -f maça --descascar=true maça outramaçã`: Executa o comando `cortarfruta`, com as opções de: corte fatiado, em 8 pedaços, a fruta a ser cortada será maçã e descascar antes de cortar, por fim passo como argumento duas maçãs para o corte.
  
  - `cortarfruta --corte=cubos --pedaços 12 maça laranja`: Executa o mesmo comando acima, mas especificando apenas o corte e o número de pedaços e por fim passo uma laranja e uma maça para o corte. Vamos supor que se eu não especificar a fruta, ele vai cortar qualquer fruta que eu passar e não vai descascar para o corte. Esses são as opções padrões do comando.
  
  - `winget search "Visual Studio Code"`: Usando o gerenciador de pacotes do windows, `winget`, faço uma busca com a ação `search` por pacotes que contenham o nome "Visual Studio Code". Como o argumento contém espaços, preciso colocar entre aspas duplas.
  
  - `winget install -e --id Microsoft.VisualStudioCode`: Com o mesmo comando do exemplo acima, instalo com a ação `install` o pacote que eu possivelmente encontrei na busca. Utilizo os parâmetros `-e` e `--id` para dizer que eu quero instalar **exatamente** com o **id** *Microsoft.VisualStudioCode* para que não ocorra a chance de instalar o pacote errado, já que *id's* costumam ser únicos.
  
  - `scoop install gcc sudo`: Com o gerenciador de pacotes `scoop`, instalo os pacotes `gcc`, que é o compilador que você precisa para executar códigos em C e o `sudo` que eu posso usar como prefixo de comandos que precisam de permissão elevada, assim eu não preciso abrir uma nova instância de um shell como administrador.
  
  - `sudo rm -Recurse -Force diretorio-de-estudo`: Executo um comando para exclusão de um diretório, com `sudo`, porque esse comando precisa de permissão elevada e preciso passar **obrigatoriamente** os parâmetros `-Recurse` e `-Force` porque se trata de um diretório e não um arquivo.

    Com isso, eu espero que você tenha entendido como funciona basicamente os comandos de shells, seja no Prompt de Comando, PowerShell, Zsh, Bash, dentre outros.


- **Permissões elevadas**: Provavelmente você já viu em algum tutorial que você precisa "executar como administrador" algum programa que você precisa executar. Isso é uma forma de proteger o usuário de executar comandos potencialmente danosos para o sistema operacional. Quando eu falo "danoso", não estou me refererindo a danificar fisicamente, mas sim danificar sua instalação do Windows por exemplo, ou prejudicar o funcionamento de algum programa.
&nbsp;
Em um sistema operacional, existe o usuário comum, com um conjunto limitado de funções que ele pode executar e existe o usuário *root* ou superusuário, ou administrador, que consegue executar praticamente qualquer função. É importante você entender isso porque sempre tem gente batendo cabeça tentando executar comandos que não estão no seu nível de permissão. Não se preocupe, a saída do comando na linha de comando ou um popup vai avisar que você precisa elevar a permissão pra executar um comando, provavelmente em inglês, então preste atenção.
&nbsp;

- **Gerenciadores de pacotes**: Até agora, tudo o que você instalou de programas, seja um Google Chrome, um Microsoft Office ou um leitor de PDF, foi abrindo o navegador, entrando no site, baixando o executável e seguindo o passo a passo de instalação, certo? Mas saiba que não existe somente essa forma de instalar programas.
&nbsp;
É possível instalar programas através da linha de comando e você precisa saber como fazer isso, pois uma hora você vai precisar, acredite, seja pra instalar um programa, ou talvez uma biblioteca que uma linguagem de programação precise.
&nbsp;
As ferramentas responsáveis por fazer o processo de instalação dessa forma são chamadas de **gerenciadores de pacotes**, onde programas, bibliotecas de dependência, etc, são chamados de **pacote**, então o Google Chrome por exemplo, pode ser chamado de pacote. Cada sistema operacional possui seu(s) gerenciador(es) de pacote(s) como o `apt` do Debian, `pacman` do Arch Linux ou o `yum` do Fedora. O Windows tem, mas nem sempre teve, algo decente que pudesse ser chamado de gerenciador de pacote, mas desenvolvedores, criaram gerenciadores de pacote para o  Windows, como o chocolatey (`choco`), o `scoop` e por fim, a Microsoft finalmente decidiu criar o seu, o `winget`.

## Desafio
Dito isso, eu lanço pra você o seguinte desafio (vou usar como exemplo o Windows 10/11, já que grande parte de vocês devem estar usando-o agora mesmo): Configure um ambiente com os seguintes programas / ferramentas:

- **Winget**: Por padrão nos Windows 11 e em algumas builds do Windows 10, o `winget` já está disponível. Para saber se está instalado, abra o **Windows PowerShell** ou **Prompt de Comando** e execute o comando `winget`, sem ação, parâmetros ou argumentos. Se você ver uma mensagem que não seja um erro em vermelho ou algo que seja a descrição de um erro, então provavelmente está instalado. Caso não esteja, você pode instalar pela loja do Windows, pesquisando por **"Instalador de Aplicativo"**.
&nbsp;
- **PowerShell 7**: Prompt de Comando (CMD) já é ultrapassado e a Microsoft já tem melhores alternativas. Por padrão o Windows vem com o Windows PowerShell 5.1, mas eu fortemente recomendo que você use o 7. Você pode instalar pela loja do Windows ou pelo `winget`.
&nbsp;
- **Windows Terminal**: Emulador de terminal que permite agrupar diversos shells (CMD, Powershell, Distros WSL, etc). Você pode instalar pela loja do Windows ou pelo `winget`.
&nbsp;
- **Scoop**: Gerenciador de pacotes que vai permitir você instalar via linha de comando diversas ferramentas como o compilador `gcc`. Acesse [scoop.sh](https://scoop.sh) e siga as instruções.
&nbsp;
- **GCC**: Compilador para a linguagem C. Com o `scoop`, instale o pacote `gcc`
&nbsp;
- **Visual Studio Code**: com o `winget`, instale o pacote Visual Studio Code

A partir desse ponto eu creio que você já consiga caminhar sozinho. Pratique operações como criar diretórios, excluir, renomear, criar arquivos, instalar pacotes que você gosta de usar e eu garanto que você vai aprender. Você também pode personalizar seu ambiente de shell e emulador de terminal e torná-lo mais agradável aos seus olhos do que ter só uma tela preta simples.

Não tenha medo dos erros, pare e tente ler aquela mensagem vermelha que pulou na sua tela do nada, se necessário, copie e jogue no google para ver se alguém tem a solução e acredite, grande parte dos seus erros já foi solucionada por alguém que já teve o mesmo erro que você. Os erros e acertos nos levam ao domínio de muitos assuntos.

**Nota Final**: Você pode e deve ter a capacidade de discordar de tudo o que eu acho que é necessário. O que eu julgo necessário pode não ser necessário para você, é apenas o que eu segui. Parece desnecessário falar isso mas eu conheço pessoas que falam que não é necessário aprender **x** porque já tem **y** para facilitar e realmente essa pessoa "pode" ter razão. Mas acredite, as vezes e em boa parte nessa área, entender **x** ajuda demais a entender **y**. Dito isso, aprenda a julgar você mesmo o que você precisa aprender, não terceirize suas decisões. Boa sorte!! 