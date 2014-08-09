//Controlador de motor de passo
//Autor: Otavio Carneiro dos Santos
//Licenca: MIT (faca o que quiser!)
//v1.1 = dois LED's para debug: um para cada direcao
//v1.0 = Explicitamente manda sinal LOW para todos os polos quando deve ficar parado
//v0.8 = Controla a direcao e velocidade a partir da leitura do potenciometro
//v0.7 = Controle de velocidade de acordo com a leitura do potenciometro
//v0.6 = Contem algoritmo para leitura do potenciometro e 
//        //exibicao em um led para debug

const int sinal1 = 8;
const int sinal2 = 9;
const int sinal3 = 10;
const int sinal4 = 11;

const int potenciometro = A0; //pino de entrada analogica
const int ledDebugIda = 5; //pino PWM com um resistor de 300R e um LED
const int ledDebugVolta = 6;

//delay entre os sinais
int pausa = 200; //min:2, max:20 (mais que isso trepida demais)

int valorPot = 0;
int valorDebug = 0;

void setup() {
  pinMode(sinal1, OUTPUT);
  pinMode(sinal2, OUTPUT);
  pinMode(sinal3, OUTPUT);
  pinMode(sinal4, OUTPUT);
  
  pinMode(ledDebugIda, OUTPUT);
  pinMode(ledDebugVolta, OUTPUT);  
}

void loop() {
  valorPot = analogRead(potenciometro);
  //se o potenciometro estiver abaixo da metade, vai para frente
  if (valorPot < 500) {
    valorDebug = map(valorPot,0,499,255,0);
    analogWrite(ledDebugIda,valorDebug); 
    analogWrite(ledDebugVolta,LOW); 

    //pausa = map(valorPot,0,499,2,20);
 
    frente(); //4-2-3-1
  //se estiver acima da metade, vai para tras
  } else if (valorPot > 524) {
    valorDebug = map(valorPot,525,1023,0,255);
    analogWrite(ledDebugIda,LOW); 
    analogWrite(ledDebugVolta,valorDebug); 

    //pausa = map(valorPot,525,1023,20,2);
    tras();  //1-3-2-4
  //no meio, ha uma faixa de leituras em que o motor fica parado
  } else {
    analogWrite(ledDebugIda,LOW); 
    analogWrite(ledDebugVolta,LOW); 
    parar();
  }
}
//1-3-2-4
void frente() {
  enviaSinal1();  //sinal1: +-oo
  enviaSinal3();  //sinal3: oo+-
  enviaSinal2();  //sinal2: -+oo  
  enviaSinal4();  //sinal4: oo-+
}

//4-2-3-1
void tras() {
  enviaSinal4();  //sinal4: oo-+
  enviaSinal2();  //sinal2: -+oo  
  enviaSinal3();  //sinal3: oo+-
  enviaSinal1();  //sinal1: +-oo
}

void enviaSinal1() {
  //sinal1: +-oo
  digitalWrite(sinal2, LOW);
  digitalWrite(sinal3, LOW);
  digitalWrite(sinal4, LOW);  
  digitalWrite(sinal1, HIGH);
  delay(pausa);
}

void enviaSinal2() {
  //sinal2: -+oo
  digitalWrite(sinal1, LOW);
  digitalWrite(sinal3, LOW);
  digitalWrite(sinal4, LOW);  
  digitalWrite(sinal2, HIGH);
  delay(pausa);
}

void enviaSinal3() {
  //sinal3: oo+-
  digitalWrite(sinal1, LOW);
  digitalWrite(sinal2, LOW);
  digitalWrite(sinal4, LOW);  
  digitalWrite(sinal3, HIGH);
  delay(pausa);
}

void enviaSinal4() {
  //sinal4: oo-+
  digitalWrite(sinal1, LOW);
  digitalWrite(sinal2, LOW);
  digitalWrite(sinal3, LOW);
  digitalWrite(sinal4, HIGH);  
  delay(pausa);
}

//envia LOW para todos os sinais
void parar() {
  digitalWrite(sinal1, LOW);
  digitalWrite(sinal2, LOW);
  digitalWrite(sinal3, LOW);
  digitalWrite(sinal4, LOW);  
}
