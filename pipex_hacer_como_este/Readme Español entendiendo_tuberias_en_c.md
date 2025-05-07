
<div align="center">

<img src="./pictures/pipe.png" alt="pipe" width="100" align="right">

# Entendiendo las Tuberías en C
</div>

Las tuberías son una piedra angular en los sistemas operativos similares a Unix, ya que permiten una comunicación fluida entre procesos al permitir que la salida de un proceso se convierta en la entrada de otro. En la programación en C, la función `pipe()` juega un papel fundamental en el establecimiento de canales de comunicación entre procesos mediante tuberías unidireccionales. Vamos a profundizar en el funcionamiento de las tuberías y su implementación en C.

## Tuberías en sistemas similares a Unix:

En los shells similares a Unix, como Bash, las tuberías facilitan la concatenación de múltiples comandos, donde la salida de un comando fluye sin esfuerzo hacia la entrada del siguiente. Esta orquestación se logra fácilmente utilizando el operador de tubería `|`. Por ejemplo:

```bash
command1 | command2
```

Aquí, la salida generada por `command1` sirve como entrada para `command2`, creando efectivamente una tubería para el flujo de datos.

## La función `pipe()` en C:

En su núcleo, las tuberías son flujos de búfer estrechamente vinculados a dos descriptores de archivo, configurados meticulosamente para permitir la transferencia de datos de un extremo a otro. En el ámbito de la programación en C, la función `pipe()` emerge como el conducto para construir tuberías unidireccionales. Su firma de función es la siguiente:

```c
int pipe(int pipefd[2]);
```

El arreglo `pipefd` encapsula dos enteros, donde `pipefd[0]` representa el extremo de lectura de la tubería, mientras que `pipefd[1]` representa el extremo de escritura. Los datos escritos en `pipefd[1]` pueden ser posteriormente recuperados de `pipefd[0]`, fomentando la comunicación entre los procesos emparejados.

## Explicación visual de las Tuberías:

```
              [Proceso A]             [Proceso B]
                 |                        |
           (pd[0])<----- pipe -------(pd[1])
                 |                        |
           Extremo de lectura       Extremo de escritura
```

Este esquema visual ilustra la esencia de las tuberías, mostrando que `pd[0]` es el extremo de lectura, donde los datos escritos por el Proceso B esperan ser consumidos por el Proceso A. Por otro lado, `pd[1]` es el extremo de escritura, canalizando los datos escritos por el Proceso A hacia el ansioso abrazo del Proceso B.

## Gestión de Procesos en C:

En la programación en C, gestionar procesos al usar tuberías requiere utilizar un conjunto de funciones como `fork()`, `execve()`, `dup2()` y `close()`.

- **`fork()`:** Esta función crea un nuevo proceso al hacer una copia del proceso actual. Cuando se llama a `fork()`, se crean dos procesos: el padre y el hijo. El proceso padre continúa su ejecución desde el punto donde se llamó a `fork()`, mientras que el proceso hijo comienza desde el mismo punto pero con un PID (Identificador de Proceso) diferente. Además, si se ha creado una tubería previamente usando `pipe()`, los descriptores de archivo obtenidos de la tubería se comparten entre los procesos padre e hijo. Esto significa que los datos escritos en un descriptor pueden ser leídos desde el otro. `fork()` esencialmente duplica la memoria y los descriptores de archivo del proceso padre para el hijo, permitiéndoles compartir información y trabajar juntos.

## Integración con `fork()` para la Comunicación entre Procesos:

Combinar `fork()` con `pipe()` abre oportunidades para la comunicación entre procesos. Después de que se crean los procesos padre e hijo, ambos tienen acceso a los mismos descriptores de archivo, que son proporcionados por la tubería. Esta conexión compartida les permite intercambiar datos fácilmente a través de la tubería. Esta comunicación no solo se trata de transferir datos; también permite la sincronización y colaboración entre los procesos. Esta colaboración es esencial para tareas como la programación de scripts en shells y la programación concurrente, permitiendo operaciones más complejas y eficientes.

![sharing-pipe](./pictures/sharing-pipe.jpg)

- **`execve()`:** Esta función es como el director de una orquesta. Ayuda a iniciar un nuevo proceso reemplazando el proceso actual con uno nuevo basado en un archivo específico. Imagina que tienes una nueva pieza de música (el nuevo proceso), y `execve()` es el director que empieza a tocarla, reemplazando la pieza anterior.

- **`dup2()`:** Piensa en `dup2()` como un hechizo mágico que hace una copia exacta de una varita mágica (descriptor de archivo) y la pone en otra varita. Esto se usa a menudo para redirigir dónde van las entradas y salidas de un proceso. Por ejemplo, si quieres que la salida vaya a otro lugar distinto al habitual, `dup2()` puede hacerlo al copiar la varita de salida a una nueva ubicación.

- **`close()`:** Cuando un archivo ya no se necesita, `close()` es como cerrar un libro después de terminar de leerlo. Es una forma de informar al sistema que un archivo o recurso ya no se usa, liberando espacio y recursos para otras tareas.

En términos más sencillos, `execve()` inicia una nueva tarea, `dup2()` puede cambiar dónde van las entradas y salidas de la tarea, y `close()` finaliza y limpia todo cuando la tarea ha terminado.

### Explicación visual de la función `pipex`:

```
              [Proceso Padre]
                  /          [Proceso Hijo 1]       [Proceso Hijo 2]
    (cmd1, entrada)         (cmd2, salida)
         |                       |
         |                       |
    [Entrada de la Tubería]  [Salida de la Tubería]
```

![pipex](./pictures/pipex_digram.png)

Cuando usamos `fork()` junto con `pipe()` para la comunicación entre procesos, es como si un padre creara dos hijos. Un hijo, al que llamaremos Proceso Hijo 1, se encarga de tomar la entrada de `cmd1`. El otro hijo, Proceso Hijo 2, está listo para dar los resultados a `cmd2`. La tubería actúa como un puente entre estos hijos, facilitando el intercambio de información. Es como un pasaje secreto que permite que los datos fluyan sin problemas de entrada a salida, haciendo que la comunicación entre los procesos sea fácil.

### Flujo de Datos:

- Los datos de entrada provienen del archivo de entrada designado. Luego viajan a través del primer proceso (`cmd1`), que los manipula según sus instrucciones.
- Los datos procesados se envían al extremo de escritura (`pd[1]`) de la tubería, donde esperan ser consumidos por el segundo proceso (Proceso Hijo 2). Estos datos pueden ser leídos por el Proceso Hijo 2 a través de su entrada estándar (`stdin`).

Esta explicación revela el intrincado funcionamiento de las tuberías y la comunicación entre procesos en C, invitando a la exploración y la innovación en el ámbito de la programación.
