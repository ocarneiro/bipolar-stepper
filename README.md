bipolar-stepper
===============

Solução para controle de um motor de passo bipolar.

A proposta inicial era baseada em transistores NPN e um Darlington Array ULN2003A com pretensões de ser controlada por um microcontrolador ATTINY85.

Acabei optando por uma saída mais fácil, controlando com um Arduino UNO R3 e fazendo a ponte H com um IC L298N. O código, no entanto, permanece o mesmo.
