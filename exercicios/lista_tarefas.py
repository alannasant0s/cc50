import json # Para salvar e carregar tarefas em formato JSON

ARQUIVO_TAREFAS = "tarefas.json"

def carregar_tarefas():
    """Carrega tarefas do arquivo JSON."""
    try:
        with open(ARQUIVO_TAREFAS, 'r', encoding='utf-8') as f:
            tarefas = json.load(f)
    except FileNotFoundError:
        tarefas = [] # Se o arquivo não existe, começa com lista vazia
    except json.JSONDecodeError:
        tarefas = [] # Se o arquivo estiver corrompido ou vazio
    return tarefas

def salvar_tarefas(tarefas):
    """Salva a lista de tarefas no arquivo JSON."""
    with open(ARQUIVO_TAREFAS, 'w', encoding='utf-8') as f:
        json.dump(tarefas, f, indent=4, ensure_ascii=False)

def adicionar_tarefa(tarefas, descricao_tarefa):
    """Adiciona uma nova tarefa à lista."""
    if not descricao_tarefa.strip(): # Verifica se a descrição não está vazia
        print("Erro: A descrição da tarefa não pode estar vazia.")
        return
    tarefa = {"descricao": descricao_tarefa, "concluida": False}
    tarefas.append(tarefa)
    salvar_tarefas(tarefas)
    print(f"Tarefa '{descricao_tarefa}' adicionada com sucesso!")

def listar_tarefas(tarefas):
    """Lista todas as tarefas com seu status."""
    if not tarefas:
        print("Nenhuma tarefa na lista.")
        return

    print("\n--- Sua Lista de Tarefas ---")
    for indice, tarefa in enumerate(tarefas):
        status = "[X]" if tarefa["concluida"] else "[ ]"
        print(f"{indice + 1}. {status} {tarefa['descricao']}")
    print("---------------------------\n")

def marcar_como_concluida(tarefas, indice_tarefa):
    """Marca uma tarefa como concluída."""
    try:
        indice = int(indice_tarefa) - 1 # Ajusta para o índice da lista (começa em 0)
        if 0 <= indice < len(tarefas):
            if tarefas[indice]["concluida"]:
                print(f"Tarefa '{tarefas[indice]['descricao']}' já estava marcada como concluída.")
            else:
                tarefas[indice]["concluida"] = True
                salvar_tarefas(tarefas)
                print(f"Tarefa '{tarefas[indice]['descricao']}' marcada como concluída!")
        else:
            print("Erro: Número da tarefa inválido.")
    except ValueError:
        print("Erro: Entrada inválida. Por favor, insira um número.")

def remover_tarefa(tarefas, indice_tarefa):
    """Remove uma tarefa da lista."""
    try:
        indice = int(indice_tarefa) - 1 # Ajusta para o índice da lista
        if 0 <= indice < len(tarefas):
            tarefa_removida = tarefas.pop(indice)
            salvar_tarefas(tarefas)
            print(f"Tarefa '{tarefa_removida['descricao']}' removida com sucesso!")
        else:
            print("Erro: Número da tarefa inválido.")
    except ValueError:
        print("Erro: Entrada inválida. Por favor, insira um número.")

def menu():
    """Exibe o menu e gerencia a interação com o usuário."""
    tarefas = carregar_tarefas()

    while True:
        print("\nEscolha uma ação:")
        print("1. Adicionar Tarefa")
        print("2. Listar Tarefas")
        print("3. Marcar Tarefa como Concluída")
        print("4. Remover Tarefa")
        print("5. Sair")

        escolha = input("Digite o número da sua escolha: ")

        if escolha == '1':
            descricao = input("Digite a descrição da nova tarefa: ")
            adicionar_tarefa(tarefas, descricao)
        elif escolha == '2':
            listar_tarefas(tarefas)
        elif escolha == '3':
            listar_tarefas(tarefas)
            if tarefas:
                num_tarefa = input("Digite o número da tarefa para marcar como concluída: ")
                marcar_como_concluida(tarefas, num_tarefa)
        elif escolha == '4':
            listar_tarefas(tarefas)
            if tarefas:
                num_tarefa = input("Digite o número da tarefa para remover: ")
                remover_tarefa(tarefas, num_tarefa)
        elif escolha == '5':
            print("Obrigado por usar a Lista de Tarefas! Salvando e saindo...")
            salvar_tarefas(tarefas) # Garante que as últimas alterações sejam salvas
            break
        else:
            print("Opção inválida. Por favor, tente novamente.")
# Ponto de entrada do programa
if __name__ == "__main__":
    menu()