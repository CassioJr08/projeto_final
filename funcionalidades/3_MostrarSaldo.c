void mostrarSaldo(criarConta contas[], int numContas) {
    int numeroConta;

    printf("Digite o numero da conta: ");
    scanf("%d", &numeroConta);

    int indiceConta = -1;
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numeroConta == numeroConta) {
            indiceConta = i;
            break;
        }
    }

    if (indiceConta != -1) {
        printf("Saldo da conta de %s (CPF: %s), numero da conta: %d: %.2f\n",
               contas[indiceConta].titular, contas[indiceConta].cpf,
               contas[indiceConta].numeroConta, contas[indiceConta].saldo);
    } else {
        printf("Conta nao encontrada.\n");
    }
}