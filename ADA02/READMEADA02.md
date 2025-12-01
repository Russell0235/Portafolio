# ADA02 COLAS
**Descripción:** El propósito de este programa es simular el sistema de atención de un banco que cuenta con tres cajas operativas. La lógica del sistema funciona de la siguiente manera:

Generación de Entorno: El programa crea clientes de forma aleatoria. A cada cliente se le asigna un número de transacciones (que determina cuánto tiempo tardará en ser atendido) y se le dirige aleatoriamente a una de las tres colas disponibles.

Procesamiento: El sistema gestiona el flujo, registrando exactamente cuándo entra un cliente a la cola, a cuál ingresó y en qué momento termina su trámite y sale.

Resultados y Métricas: Al finalizar, el programa calcula estadísticas clave de rendimiento, como el tiempo promedio de espera y la cantidad total de clientes atendidos por cada caja.

A nivel técnico, estoy implementando la solución en C, estructurando los datos de los clientes mediante structs, modularizando el código con funciones específicas y, lo más importante, aplicando correctamente la estructura de datos Queue (Cola) para manejar el orden de atención.
