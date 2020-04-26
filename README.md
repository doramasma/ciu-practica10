# Ciu práctica 10
Introducción a la programación con Arduino

## Autor 
**Doramas Báez Bernal** <br/>
**Marcos Jesús Santana Pérez** <br/>
**Hector Henriquez Cabrera** <br/>

## Sistema arduino
<div align="center">
  <img src="/arduino_uno.png" alt="arduino uno ">
  <p align="center">
    Figura 1: Esquema utilizado en la práctica
  </p>
</div>

## Índice
* [Introducción](#introducción)
* [Desarrollo](#desarrollo)
    * [Herramientas utilizadas](#Herramientasutilizadas)
    * [Decisiones codigo](#Decisionescodigo)
* [Referencias](#referencias)

## Introducción
Esta práctica tiene como objetivo realizar una pequeña introducción a arduino, para ello,  se va a realizar un pequeño proyecto utilizando una placa arduino uno y un led. Debido a las condiciones en las que nos encontramos, se hará uso de un simulador, llamado Tinkercad, para disponer de dicha placa. Con el fin de realizar un pulso sobre dicho led, este pulso vendrá influenciado por una señal senoidal. Es decir, dependiendo de los valores que obtenemos de la función sin(), se verá afectado el comportamiento del sistema. De forma que cuando dicha señal alcance su valor máximo, el LED parpadeará a una cierta frecuencia, especificada como freqMax, mientras que cuando alcance el valor mínimo parpadeará a una frecuencia mínima, especificada como freqMin. Podremos encontrar más información en el guión [1].


## Desarrollo

### Herramientas utilizadas <a id="Herramientasutilizadas"></a>

En principio para esta práctica ibamos a contar con una placa arduino uno, además de ciertos componentes como serían la resistencia y el led. Sin embargo, como se comentó anteriormente debido a las circunstancias actuales hemos tenido que optar por utilizar un simulador. Tinkercad [2] es un simulador online, que nos permitirá seleccionar entre distintos tipos de arduinos (modelos predefinidos) o también partir de un modelo base e ir añadiendo distintos componentes. En este caso, solo necesitamos el modelo básico que viene con un led. Con lo que hemos optado por usar el siguiente esquema: 

## Sistema arduino
<div align="center">
  <img src="/componentes_arduino.png" alt="componentes arduino ">
  <p align="center">
    Figura 2: Componentes utilizados en la práctrica
  </p>
</div>
 

### Decisiones codigo<a id="Decisionescodigo"></a>
La estrategia que se ha seguido para generar el efecto solicitado, consiste en calcular el seno de un valor que se irá incrementando cada vez que suceda un parpadeo. A el resultado de esta operación se le calcula un mapeo siguiendo la siguiente fórmula:

double slope = 1.0 * (freqMin - freqMax) / (sinMax - sinMin);
double output = freqMax + slope * (input - sinMin);

Donde freqMin y freqMax son las frecuencias mínimas/máximas a las que queremos realizar el mapeo. sinMin y sinMax, son -1 y 1, o lo que es lo mismo los valores mínimos y máximos que nos retornará la operación del seno. Y input es el resultado de la operación seno.
Una vez calculado el mapeo (que nos da una frecuencia entre freqMin y freqMax) calculamos el tiempo que pasará entre el encendido y apagado del LED, basándonos en la ecuación T=1F, donde T es el tiempo en segundos y F es la frecuencia.

El proyecto se encuentra en github [3], donde se puede ver y replicar.




## Referencias

* [Guion de prácticas](https://cv-aep.ulpgc.es/cv/ulpgctp20/pluginfile.php/126724/mod_resource/content/36/CIU_Pr_cticas%20-1920.pdf)
* [Tinkercad](https://www.tinkercad.com/)
