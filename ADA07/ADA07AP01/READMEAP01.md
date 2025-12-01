# APLICACIÓN 

Para usar el programa, guarda el código como `main.cpp`, compílalo en la terminal con el comando `g++ main.cpp -o sistema` y ejecútalo escribiendo `sistema.exe` (Windows) o `./sistema` (Linux/Mac). El programa te pedirá definir el tamaño de la tabla y desplegará un menú para insertar, buscar y eliminar estudiantes utilizando sus matrículas. Internamente funciona como una **Tabla Hash de Direccionamiento Abierto**, resolviendo colisiones mediante **Sondeo Lineal** y utilizando estados (0=Vacío, 1=Ocupado, 2=Borrado) para mantener la integridad de los datos.
