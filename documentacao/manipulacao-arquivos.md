# Manipulação de Arquivos 🗂️

### 🧾 Conceitos Básicos

- Abrir um **arquivo** retorna um **ponteiro** para uma estrutura `FILE` definida em `<stdio.h>`, que contém informações usadas para processar o arquivo. 
- Os arquivos são utilizados para a **conservação permanente de grandes volumes de dados**.
- O fim de um arquivo é indicado por um marcador de final de arquivo — *End-of-file* (EoF).
- Os padrões de entrada (`stdin`), saída (`stdout`) e erros (`stderr`) são manipulados por meio dos **ponteiros de arquivos**.

### Modos de Abertura de Arquivos 

### 📄 Modos Texto

| Modo | Operação principal | Se o arquivo NÃO existir... | Se o arquivo JÁ existir... |
|------|-------------------|----------------------------|----------------------------|
| `"r"` | Apenas **leitura**. | Erro (não cria o arquivo). | Abre normalmente para leitura, preservando o conteúdo. |
| `"w"` | Apenas **gravação**. | Cria um novo arquivo. | Destrói o conteúdo anterior (sobrescreve). |
| `"a"` | **Gravação no final (append)**. | Cria um novo arquivo. | Mantém o conteúdo e adiciona dados ao final. |
| `"r+"` | **Leitura e gravação**. | Erro (não cria). | Abre para modificação sem apagar o conteúdo. |
| `"w+"` | **Leitura e gravação**. | Cria um novo arquivo. | Apaga o conteúdo anterior e permite ler/escrever. |
| `"a+"` | **Leitura e gravação (append)**. | Cria um novo arquivo. | Mantém o conteúdo e sempre grava ao final. |


### 💾 Modos Binários (`b`)

A letra **`b`** indica que o arquivo será aberto em **modo binário**.  
Nesse modo, os dados são tratados exatamente como estão armazenados (byte a byte), sem qualquer conversão de caracteres especiais (como `\n`).

> 🔎 No Windows, por exemplo, o modo texto pode converter `\n` para `\r\n`.  
> No modo binário isso **não acontece**.

| Modo | Operação principal | Se NÃO existir | Se JÁ existir |
|------|-------------------|----------------|---------------|
| `"rb"` | Leitura binária | Erro | Lê o conteúdo binário |
| `"wb"` | Escrita binária | Cria novo | Sobrescreve tudo |
| `"ab"` | Escrita binária no final | Cria novo | Adiciona ao final |
| `"rb+"` ou `"r+b"` | Leitura e gravação binária | Erro | Modifica sem apagar |
| `"wb+"` ou `"w+b"` | Leitura e gravação binária | Cria novo | Apaga conteúdo anterior |
| `"ab+"` ou `"a+b"` | Leitura e gravação binária (append) | Cria novo | Mantém conteúdo e grava no final |


### 🧠 Importante

- **Modo texto** → Ideal para arquivos `.txt`, leitura de strings, arquivos de configuração.
- **Modo binário** → Ideal para imagens, PDFs, executáveis, structs salvas diretamente com `fwrite()`.

Se quiser, posso complementar com exemplos usando `fopen()`, `fread()` e `fwrite()` também.

---

### 💾 Manipulação de Blocos de Dados Binários

Essas funções são utilizadas para trabalhar com **grandes blocos de dados não formatados**, como:

- Structs inteiras
- Vetores
- Arquivos binários
- Imagens, executáveis, PDFs
- Qualquer dado salvo "byte a byte"

São ideais quando não queremos formatação (como acontece com `fprintf`/`fscanf`).

## 🔹 `fwrite`
Escreve blocos de dados da memória para o arquivo.

```c
size_t fwrite(const void *dados, size_t tamanho, size_t numero_itens, FILE *fluxo);
````

**Funcionamento:**
  - Escreve `tamanho * numero_itens` bytes no arquivo.
  - Retorna o número de itens efetivamente escritos.
  - Deve ser usado preferencialmente com arquivos abertos em modo binário (`"wb"`, `"ab"`, `"rb+"`, etc.).

*Exemplo (salvando uma Struct):*
````c
fwrite(&aluno, sizeof(struct Aluno), 1, fp);
````

## 🔹 `fread`
Lê blocos de dados do arquivo diretamente para a memória.
````c
size_t fread(void *dados, size_t tamanho, size_t numero_itens, FILE *fluxo);
````

**Funcionamento:**
- Tenta ler `tamanho * numero_itens` bytes do arquivo.
- Retorna o número de itens realmente lidos.
- Se o retorno for menor que `numero_itens`, pode ter ocorrido:
    - Fim de arquivo (EOF)
    - Erro de leitura

*Exemplo (lendo uma Struct):*
````c
fread(&aluno, sizeof(struct Aluno), 1, fp);
````

### ⚠️ Boas Práticas Importantes

- Sempre abra arquivos binários com `"rb"`, `"wb"`, `"ab"`, etc.
- Sempre verifique o valor retornado por `fread()` e `fwrite()`.
- Estruturas gravadas em binário devem ter o mesmo layout ao serem lidas (mesmo compilador, mesma arquitetura).
- Cuidado com *padding* da `struct` (pode alterar o tamanho real em bytes).

---

### 📚 Funções Essenciais

## 🔹 `fopen`
Abre um arquivo e retorna um ponteiro para a estrutura `FILE` associada.

```c
FILE *fopen(const char *nome_do_arquivo, const char *modo);
````
  - Retorna um ponteiro válido se conseguir abrir.
  - Retorna `NULL` em caso de erro.
  - O modo pode ser "r", "w", "a", "rb", etc.

## 🔹 `fclose`
Fecha o arquivo quando ele não é mais necessário.
````c
int fclose(FILE *fp);
````
  - Retorna `0` se fechar com sucesso.
  - Retorna `EOF` em caso de erro.
  - Sempre deve ser chamado para liberar recursos do sistema.

## 🔹 `feof`
Verifica se o fim do arquivo foi atingido (EOF – End Of File).
````c
int feof(FILE *fp);
````
  - Retorna valor diferente de zero se o EOF foi atingido.
  - Retorna `0` caso contrário.
  - Normalmente usado em estruturas de repetição.
**Atenção:** `feof()` só retorna verdadeiro após uma tentativa de leitura atingir o fim do arquivo.

## 🔹 `fscanf`
Lê dados formatados de um arquivo.
Funciona como scanf, mas lendo de um arquivo.
````c
fscanf(fp, "%d %s", &numero, nome);
````
  - Permite ler números, strings e outros formatos.
  - Deve-se verificar o valor de retorno para garantir que a leitura foi bem-sucedida.

## 🔹 `fprintf`
Escreve dados formatados em um arquivo.
Funciona como `printf`, mas envia a saída para o arquivo.
````c
fprintf(fp, "Idade: %d\n", idade);
````
  - Muito usado para gerar relatórios e arquivos `.txt`.

## 🔹 `fgetc`
Lê um único caractere do arquivo.
````c
int fgetc(FILE *fluxo);
````
  - Retorna o caractere lido (convertido para int).
  - Retorna EOF se atingir o final do arquivo.
  - Avança automaticamente para o próximo caractere.

## 🔹 `fgets`
Lê uma linha (string) de forma segura.
````c
char *fgets(char *str, int tamanho, FILE *fp);
````

**Para de ler quando:**
  - atingir `tamanho - 1` caracteres, encontrar `\n`, ou atingir o `EOF`.

✔️ Evita buffer overflow

✔️ É mais segura que `gets()` que é obsoleta

---

### 🧠 Observação Importante
Sempre verifique:
- Se `fopen()` retornou `NULL` (erro ao abrir o arquivo).
- Se as funções de leitura realmente leram dados com sucesso (verifique o valor de retorno).
- Se `fclose()` foi chamado ao final do programa para liberar recursos do sistema.

---

