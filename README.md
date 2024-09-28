# Caso da Vinheria Agnello - Data Logger - Checkpoint 1 - 1ESPA - 09-10/2024

> [!CAUTION]
> **PUBLICAR O REPOSITORIO QUANDO FOR ENVIAR O TRABALHO**

## Mestre: 
- Professor Fábio Cabrini
## Alunos:
- [**Gabriel Kato**](https://github.com/kato8088) - RM560000
- [**Francisco Vargas**](https://github.com/Franciscov25) - RM560322
- [**Gabriel Couto**](https://github.com/rouri404) - RM559579
- [**João Vitor**](https://github.com/joaomatosq) - RM559246

## Descrição do Projeto:
Essa é a primeira parte do projeto de Data Logger do primeiro semestre de Edge Computing. O sistema até o momento consiste em um fotoresistor, três LEDs, um Buzzer e um microcontrolador Atmel ATMega 328P sob uma placa Arduino Uno R3.

## Componentes Utilizados:
- **Arduino Uno R3**
- **Sensor LDR**
- **LEDs**: Vermelho, Amarelo e Verde
- **Buzzer**
- **Resistores**: 1k e 10k
- **Jumpers**
- **Protoboard**

## Pinagem:
- **LED Vermelho:** Digital 2 (D2)
- **LED Amarelo:** Digital 3 (D3)
- **LED Verde:** Digital 4 (D4)
- **Buzzer:** Digital 5 (D5)
- **LDR:** Analógico 5 (A5)

## Funcionamento:
O código verifica a medição da entrada analógica *A5* pela função *luxTick()* e dependendo da voltagem lida pelo Arduino, define a situação do ambiente da Vinheria como:
1. **Normal** (Nível 0 a 33): O ambiente está adequadamente iluminado, portanto somente o LED Verde é aceso.
2. **Atenção** (Nível 34 a 66): O ambiente está em um nível de iluminação inadequado, entre o normal e o crítico, portanto, o LED Amarelo é ligado e o buzzer apita brevemente (XXX milisegundos).
3. **Alerta** (Nível 67 a 100): O ambiente está em uma condição inadequada para o armazenamento de vinhos, comprometendo sua qualidade, portanto, o LED Vermelho se acende e o buzzer apita longamente (3 segundos).

A situação do ambiente e o nível da intensidade da luz são enviadas pela porta Serial do Arduino em uma Baud Rate de 9.6kbps.

## Como instalar e rodar o projeto?
1. Conecte os fios e componentes conforme o esquema elétrico providenciado com a placa desconectada.
2. Conecte a placa ao PC.
3. Usando uma IDE compatível com a linguagem C++ e as bibliotecas do Arduino (como o Arduino IDE), cole o código-fonte do projeto no IDE, compile e faça o *upload* para a placa.
4. A instalação está completa! Caso queira monitorar os valores, use um monitor Serial como o PuTTY ou o monitor embutido no Arduino IDE, não se esqueça de configurar a Baud Rate corretamente (9600 baud)!

## Entrega do Projeto (cópia dos slides):
<details open>
  <summary>Entregas do Projeto (GitHub)</summary>
  - Projeto e simulação no Tinkercad <br>
  - Código comentado <br>
  - Arquivo README contendo a descrição do projeto, suas dependências e como reproduzi-lo <br>
  - Link público do vídeo de no máximo 3 minutos explicando como o projeto foi  implementado, quais foram as dificuldades encontradas e como foram resolvidas <br>
</details>
<details open>
  <summary>Avaliação</summary>
  - Serão um total de 10 Pontos:<br>
  - Simulação – 5 pontos:<br>
  - Projeto no Tinkercad;<br>
  - Código fonte comentado;<br>
  - 2 pontos pela clareza do video explicativo (Simulação);<br>
  - 1 ponto pela clareza do README;<br>
  - Hands-ON – 5 pontos: <br>
  - 5 pontos pela demonstração do projeto funcionando e pela explicação da implementação; <br>
</details>
<details open>
  <summary>E como faremos isso?</summary>
  - Entrega via formulário:  https://forms.office.com/r/AJPCEuwzQf <br>
  - Data do Hands-ON: 1ESPA - 07/10/2024 <br>
</details>

## O que falta fazer:
- [ ] Video do YouTube
- [x] Documentação (provavelmente só no README.md mesmo "Arquivo README contendo a descrição do projeto, suas dependências e como reproduzi-lo")
- [x] Comentar o código
- [x] Colocar nossos nomes no projeto do GitHub
- [x] Código
- [x] Projeto eletrônico