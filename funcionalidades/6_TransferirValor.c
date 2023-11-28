void TransferirValor(){


    // Estrutura para armazenar informações da conta
    typedef struct {
        int numeroConta;
        char *titular;
        float saldo;
    } Conta;

    // Função para transferir valor de uma conta para outra
    void transferirValor(Conta *contas, int numContas) {
        int contaOrigem, contaDestino;
        float valor;

        // Solicitar informações da transferência ao usuário
        printf("Digite o número da conta de origem: ");
        scanf("%d", &contaOrigem);

        printf("Digite o número da conta de destino: ");
        scanf("%d", &contaDestino);

        printf("Digite o valor a ser transferido: ");
        scanf("%f", &valor);

        // Verificar se as contas existem e se há saldo suficiente na conta de origem
        if (contaOrigem >= 0 && contaOrigem < numContas && contaDestino >= 0 && contaDestino < numContas
            && contas[contaOrigem].saldo >= valor) {

            // Realizar a transferência
            contas[contaOrigem].saldo -= valor;
            contas[contaDestino].saldo += valor;

            printf("Transferência concluída com sucesso!\n");
            printf("Saldo atual da conta %d: %.2f\n", contaOrigem, contas[contaOrigem].saldo);
            printf("Saldo atual da conta %d: %.2f\n", contaDestino, contas[contaDestino].saldo);
        } else {
            printf("Erro ao transferir valor. Verifique as informações das contas.\n");
        }
    }

        // Defina o número inicial de contas
        int numContas = 0;

        // Alocar dinamicamente espaço para um array de contas
        Conta *contas = NULL;

        // Solicitar ao usuário o número de contas
        printf("Digite o número de contas: ");
        scanf("%d", &numContas);

        // Alocar dinamicamente espaço para as contas
        contas = (Conta *)malloc(numContas * sizeof(Conta));

        // Inicializar contas
        for (int i = 0; i < numContas; i++) {
            // Solicitar informações da conta ao usuário
            printf("Digite o número da conta %d: ", i);
            scanf("%d", &contas[i].numeroConta);

            // Alocar dinamicamente espaço para o titular
            printf("Digite o nome do titular da conta %d: ", i);
            char titularBuffer[50];
            scanf("%s", titularBuffer);
            contas[i].titular = strdup(titularBuffer);

            printf("Digite o saldo da conta %d: ", i);
            scanf("%f", &contas[i].saldo);
        }

        // Chame a função para transferir valor
        transferirValor(contas, numContas);

        // Liberar a memória alocada dinamicamente para os titulares
        for (int i = 0; i < numContas; i++) {
            free(contas[i].titular);
        }

        // Liberar a memória alocada dinamicamente para o array de contas
        free(contas);

        return 0;
}

