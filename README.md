# Avaliação 3 de Sistemas Embarcados
## Tarefa:
*Montar o circuito abaixo* **[Mostrador - Arduino - Sensor]** *para simular um mostrador de sensor (temperatura, ultrassônico, LDR, etc.) digital/analógico. A informação deve ser lida pelo ATmega328P (Arduino), usando o sensor escolhido. A informação do sensor deverá ser exibida no mostrador analógico, através da movimentação do eixo do servo. O mostrador analógico empregará um servo SG90 para definir o posicionamento do ponteiro, de acordo com a informação obtida pelo sensor. Pode ser usada a biblioteca do Arduino para manuseio do servo e leitura do sensor.*
## Metologia:
### Sensor:
O sensor escolhido foi o sensor de temperatura TMP36 com as seguintes especificações:
- Voltagem de operação (2.7 V to 5.5 V)
- Fator de Escala 10 mV/°C 
- Faixa de Voltagem de Saída (100 to 2000mV)
- Faixa de Temperatura (-40° to 125°C)
  
_Datasheet: https://www.analog.com/media/en/technical-documentation/data-sheets/tmp35_36_37.pdf_

A conexão com o arduino foi feita por meio da porta analógica A0, a qual possui o conversor A/D de 10 bits (0 a 1023).

O valor de tensão lido pelo arduino é:

$$V_{lida} = \frac{5 * \text{Valor Digital Lido} }{1023}$$

Então, a temperatura no sensor é calculada como:

$$Temp=\frac{V_lida-0.5}{0.01}$$

onde 0.01 corresponde ao fator de escala do sensor
e 0.5 corresponde ao valor em volts do sensor quando este está em 0°C (observado com multímetro)

### Servo:
O servo utlizado foi o servo motor SG90 com as seguintes especificações:
- Rotational Range: 180° 
- OPERATING VOLTAGE: 4.8V~6.0V

_Datasheet: https://www.friendlywire.com/projects/ne555-servo-safe/SG90-datasheet.pdf_

Para controlá-lo foi necessário o uso da biblioteca **Servo.h**

Para a faixa de temperatura lida pelo sensor (-40°C a +125°C) temos uma variação de 1,0909° por 1°C de variação:

$$\frac{180°}{165°C}=1.0909... °/°C$$

Pelo posicionamento do servo no circuito, 180° representa o ponteiro apontando para -40°C na escala e 0° representa o ponteiro apontando para +125°C, logo:

$$\text{Ângulo do servo = 180 - ((Temp + 40) * 1,0909) )}$$

onde (Temp + 40) serve para ajustar a escala, já que a temperatura mínima não é 0°C, mas sim em -40°C

## Alimentação:
O sensor foi alimentado com 5V vindos do Arduino, enquanto o servo foi alimentado com 6V provenientes de um conjunto de 4 baterias de 1,5V (somando 6V).

## Extra:
Foi adicionado um multímetro para análise da tensão de saída do sensor.
