
# Sistema de Banco

O objetivo do projeto é desenvolver um sistema de banco que permita realizar operações bancárias e fazer o registro em arquivos de formato CSV[^1].

- Instituição: Universidade Católica de Brasília
- Disciplina: Algoritmo e Programação Estruturada
- Professor: João Robson

## Desenvolvimento

O sistema será desenvolvido na `linguagem c` e o menu de ações deverá conter as seguintes opções:

| Número | Nome                                       | Autor              |
|--------|--------------------------------------------|--------------------|
| 1      | Criar nova conta                           | Giovanna           |
| 2      | Depositar e sacar dinheiro em uma conta    | -                  |
| 3      | Mostrar saldo de uma conta                 | Kamila             |
| 4      | Editar informações do titular de uma conta | -                  |
| 5      | Remover conta                              | -                  |
| 6      | Transferir valor de uma conta para outra   | Cássio             |

> [!NOTE]
> A função **Salvar informações de cada conta em um arquivo** será desenvolvida pelo Douglas e não aparecerá no menu de ações, pois o sistema executará de forma automática sempre que houver alguma modificação nos dados.

Dentre os principais conceitos aplicados na construção deste sistema estão: `funções`, `struct` e `ponteiro`.

[^1]: Optamos por arquivos de formato CSV, pois são mais fáceis de ler e modificar.
