# Trabalho 2 - Paralegrep

## Participante: Cassio dos Santos Rodrigues e Ryan Micael Benício dos Santos

## Instruções de como compilar e executar:

1. Usando G++: Basta acessar o terminal no diretório do projeto e utilizar o seguinte comando: ```g++ -Wall -pthread -Iinclude operarias.cpp despachante.cpp ranking.cpp -o paralegrep```. Após compilar abra o arquivo gerado.

## Organização do código:

O código está organizado em três módulos principais:

1. Thread_despachante: Responsável por gerenciar as threads operárias e a fila de arquivos. Ele cria as threads operárias, atualiza a lista de arquivos e distribui os arquivos para as threads operárias processarem.

2. Thread_operaria: Cada instância dessa classe representa uma thread que processa um arquivo, contando as ocorrências do termo especificado.

3. Thread_ranking: Responsável por manter e exibir o ranking dos arquivos com mais ocorrências do termo.

## Funcionamento do código:

- Inicialização: O programa começa criando uma instância da classe Thread_despachante e chamando o método administra com o termo de busca.

- Criação de Threads e Arquivos: O método administra chama criaOperarias para criar as threads operárias e criaArquivos para listar os arquivos no diretório fileset.

- Execução das Operárias: O método executaOperaria distribui os arquivos para as threads operárias, que contam as ocorrências do termo em cada arquivo.

- Atualização do Ranking: Os resultados são enviados para a instância de Thread_ranking, que atualiza o ranking e exibe os resultados.

- Loop de Atualização: O programa continua atualizando a lista de arquivos e executando as threads operárias em um loop infinito, exibindo o ranking atualizado a cada iteração.

## Estrutura dos Arquivos
- despachante.cpp: Implementa a classe Thread_despachante.
- operarias.cpp: Implementa a classe Thread_operaria.
- ranking.cpp: Implementa a classe Thread_ranking.
- operarias.h: Declara a classe Thread_operaria.
- ranking.h: Declara a classe Thread_ranking.
- fileset/: Diretório contendo os arquivos de texto a serem processados.

## Exemplo de Uso

Para buscar o termo `sistemas` nos arquivos do diretório fileset, basta compilar e executar o programa conforme descrito acima. O programa exibirá um ranking dos arquivos com mais ocorrências do termo `sistemas`.