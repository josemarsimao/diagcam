# diagcam

Diagnóstico de câmeras V4L2 no Linux. Lista os dispositivos de vídeo, pergunta qual usar e mostra:

- driver, placa e capacidades;
- entradas e saídas de vídeo;
- controles ajustáveis (brilho, contraste, exposição...);
- formatos de pixel, tamanhos e intervalos de quadro suportados;
- padrões de vídeo (NTSC, PAL...) e entradas/saídas de áudio.

Não captura imagens.

## Dependências

Precisa dos repositórios irmãos [v4l2misc](https://github.com/josemarsimao/v4l2misc) (só os módulos `v4l2enum`, `v4l2core` e `v4l2ctl`) e [kbhit](https://github.com/josemarsimao/kbhit), na mesma pasta-mãe:

```
projetos/
├── diagcam/
├── v4l2misc/
└── kbhit/
```

Não usa OpenCV nem libjpeg.

## Compilação e uso

Abra `diagcam.cbp` no Code::Blocks e compile. Depois:

```bash
./bin/Debug/diagcam
```

## Autor

Josemar Simão (josemars@ifes.edu.br)
