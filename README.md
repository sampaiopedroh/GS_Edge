# Detalhamento do Projeto para Edge Computing:

-> Integrantes: Pedro Sampaio (555613)

-> Objetivo: Monitorar a saúde dos oceanos em áreas com alto descarte de lixo e poluentes, utilizando o Arduino Uno e sensores de temperatura, umidade, pH e proximidade.

-> Componentes:
- Arduino Uno: Microcontrolador responsável por coletar os dados dos sensores e transmitir para a nuvem.
- Sensor de Temperatura e Umidade: DHT11 ou DHT22, mede a temperatura e umidade do ar, fornecendo informações sobre as condições climáticas na área.
- Sensor de pH: Sensor de pH analógico, ideal para medir o pH da água do mar.
- Sensor de Proximidade: Sensor HC-SR04, mede a distância entre o sensor e objetos próximos, detectando a presença de materiais sólidos na água.
- Módulo Wi-Fi: ESP8266 ou ESP32, para conectar o Arduino à internet e enviar os dados para a nuvem.
- Display LCD:  Um display LCD 16x2 (ou maior) é suficiente para exibir os dados dos sensores.
- Fonte de Alimentação: Bateria de lítio ou fonte de alimentação externa.
- Caixa à Prova d'Água: Para proteger os componentes eletrônicos da água e do sal.

-> Funcionamento:
- Coleta de Dados: Os sensores de temperatura, umidade, pH e proximidade coletam os dados em tempo real.
- Processamento dos Dados: O Arduino Uno recebe os dados dos sensores, realiza conversões e processamentos necessários, como leitura analógica do sensor de pH e cálculo da distância do sensor de proximidade.
- Transmissão dos Dados: O módulo Wi-Fi envia os dados processados para um servidor online (ex: ThingSpeak, AWS IoT, Google Cloud).
- Armazenamento e Visualização: Os dados são armazenados na nuvem e podem ser visualizados em um dashboard online ou aplicativo móvel.
- Alertas: O sistema pode gerar alertas para os usuários quando os dados excedem os limites predefinidos, como um pH baixo ou a presença de objetos próximos ao sensor de proximidade.

-> Detalhes do Projeto:
- Sensor de Temperatura e Umidade: O DHT11 ou DHT22 pode ser utilizado para medir a temperatura e umidade do ar. Apesar de não medir diretamente a temperatura e umidade da água, esses dados podem ser utilizados como indicadores para análise das condições climáticas na área.
- Sensor de pH: O sensor de pH analógico é conectado ao Arduino através de um conversor analógico-digital (ADC). É importante calibrar o sensor antes de usá-lo para obter leituras precisas.
- Sensor de Proximidade: O sensor HC-SR04 funciona emitindo ondas sonoras e medindo o tempo que elas levam para retornar, calculando a distância até um objeto. A detecção de materiais sólidos na água pode indicar a presença de lixo ou outros resíduos.
- Display LCD: O display LCD apresentará os dados coletados pelos sensores 
- Caixa à Prova d'Água: É fundamental proteger os componentes eletrônicos da água e do sal, utilizando uma caixa à prova d'água e selando cuidadosamente todas as conexões.
- Fonte de Alimentação: A escolha da fonte de alimentação dependerá da autonomia e da localização da estação de monitoramento. Uma bateria de lítio pode ser utilizada para alimentar o sistema por um período mais longo, enquanto uma fonte de alimentação externa pode ser utilizada se o sistema estiver próximo a uma fonte de energia.

-> Software:
- O código do Arduino deve ser escrito em linguagem C++.
- Bibliotecas como DHT library (para o DHT11/22), NewPing (para o HC-SR04) e ESP8266WiFi.h (para o módulo Wi-Fi) podem ser utilizadas.
- O código deve incluir funções para:
  - Ler os dados dos sensores.
  - Processar os dados e convertê-los para os formatos adequados.
  - Enviar os dados para a nuvem.
  - Implementar os alertas.
- Benefícios:
  - Monitoramento em tempo real da saúde dos oceanos em áreas com alto descarte de lixo e poluentes.
  - Detecção precoce de problemas de poluição e contaminação.
  - Coleta de dados científicos para análise e estudos sobre o impacto da poluição.
  - Auxílio na tomada de decisões para a gestão ambiental.

-> Próximos Passos:
- Escolher os sensores adequados para cada parâmetro.
- Elaborar o circuito eletrônico e a caixa à prova d'água.
- Escrever o código do Arduino para a coleta, processamento e transmissão dos dados.
- Implementar um sistema de armazenamento e visualização na nuvem.
- Testar a estação de monitoramento em condições reais.

-> Observações:
- É importante considerar os custos dos componentes e a viabilidade da solução.
- A estação de monitoramento deve ser instalada em locais estratégicos com alto impacto de poluição.
- A coleta e o uso dos dados devem ser realizados de forma ética e responsável, seguindo as legislações de proteção de dados.
