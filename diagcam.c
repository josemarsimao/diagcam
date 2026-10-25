/*
 *  V4L2 video capture: My tests
 *
 *  Nome: Josemar Simão
 *  email: josemars@ifes.edu.br
 *
 *  This program can be used and distributed without restrictions.
 *
 *  This program is provided with the V4L2 API
 *  see http://linuxtv.org/docs.php for more information
 *
 *  ---------------------------------------------------------------------------
 *  diagcam.c - DIAGNÓSTICO DE CÂMERA
 *
 *  Escolhe um dispositivo V4L2 e lista suas capacidades, controles, formatos,
 *  tamanhos, intervalos, padrões de vídeo e entradas/saídas de áudio.
 *
 *  Etapa 4: o programa não captura imagens, então usa apenas v4l2enum (consulta)
 *  e v4l2core (abrir/fechar). Não precisa mais de v4l2misc, libjpeg nem do
 *  process_image() vazio que antes era exigido só para o link fechar.
 *  ---------------------------------------------------------------------------
 */

#include "v4l2enum.h"
#include "kbhit.h"

int main(int argc, char **argv){

    int fid = 0;
    struct v4l2_frmivalenum fl;

    (void)argc;
    (void)argv;

    CLEAR(fl);                                  /* a estrutura precisa começar zerada */

    choose_v4l2_device();                       /* lista os dispositivos e pergunta qual usar */

    fid = v4l2c_open(get_dev_name());           /* abre o escolhido (núcleo: sem exit, devolve -1) */

    if (fid < 0) {
        fprintf(stderr, "Cannot open '%s': %d, %s\n", get_dev_name(), errno, strerror(errno));
        return EXIT_FAILURE;
    }

    list_v4l2_capabilities(fid);                /* driver, placa, capacidades */

    list_video_io(fid);                         /* entradas e saídas de vídeo */

    enumerate_controls(fid);                    /* controles ajustáveis (brilho, contraste...) */

    printf("Available formats, sizes and intervals for %s:\n", get_dev_name());
    choose_or_enumerate_image_formats(fid, &fl, 1);     /* 1 = só lista, não pergunta */

    enumerate_video_standards(fid);             /* padrões de vídeo (NTSC, PAL...) */
    enumerate_audio_input(fid);                 /* entradas de áudio */
    enumerate_audio_output(fid);                /* saídas de áudio */

    v4l2c_close(fid);

    wait_key();                                 /* espera uma tecla antes de sair */

    return 0;
}
