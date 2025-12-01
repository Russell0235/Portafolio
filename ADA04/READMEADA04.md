# ADA04 ARBOLES

**Descripción:** El objetivo de este proyecto es implementar un Sistema de Gestión de Estudiantes fundamentado en la estructura de datos de Árbol Binario de Búsqueda (ABB). La lógica de ordenamiento del árbol se basa en la matrícula (valor numérico único) de cada alumno.
La implementación en C contempla los siguientes aspectos técnicos:

* Estructura de Datos: Cada nodo contiene un struct con los datos del estudiante. Un punto crítico es que el arreglo de calificaciones es dinámico, permitiendo que cada alumno tenga una cantidad distinta de materias cursadas.

* Operaciones CRUD: El sistema permite la inserción y eliminación de nodos por matrícula, así como la actualización puntual de calificaciones específicas.

* Consultas y Reportes:
Recorridos: Se generan reportes ordenados por matrícula (In-Order) y filtrados por promedio (menor o mayor a 70).

* Algoritmos de Búsqueda: Incluye funciones avanzadas como contar nodos con valor menor a una matrícula dada (cálculo de rango) y la impresión de niveles específicos del árbol.

* Visualización: Se implementa una representación gráfica del árbol en formato ASCII para la consola.
