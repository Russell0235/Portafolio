# ADA01 PILAS

**Descripción:** El objetivo de este programa es actuar como un analizador sintáctico (parser) para evaluar expresiones aritméticas complejas, como ((2+4)*7)+3*(9–5). Para lograr esto, implemento el algoritmo estándar de dos pasos que utilizan la mayoría de los lenguajes de programación:

Conversión: Transformo la expresión matemática normal (infija) a Notación Polaca Inversa (postfija). Por ejemplo, convertir 2*(3+4) a 2 3 4 + *.

Evaluación: Proceso esa notación postfija para obtener el resultado numérico.

El programa se ejecuta desde la línea de comandos (terminal). Toma un archivo de entrada con las operaciones separadas por punto y coma, y genera un archivo de salida que muestra la conversión postfija junto con el resultado final de cada expresión.
