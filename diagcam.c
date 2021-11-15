
#include "v4l2misc.h"
#include "kbhit.h"


void process_image(const void *p, int isize){
}

int main(int argc, char **argv){

    int fid = 0;
    struct v4l2_frmivalenum fl;

    CLEAR(fl);

    choose_v4l2_device();

    fid = open_v4l2_device(0);

        list_v4l2_capabilities(fid);

        list_video_io(fid);

        enumerate_controls(fid);

        printf("Available formats, sizes and intervals for %s:\n", dev_name);
        choose_or_enumerate_image_formats(fid, &fl, 1);

            enumerate_video_standards(fid);
            enumerate_audio_input(fid);
            enumerate_audio_output(fid);


    close_v4l2_device(fid);

    wait_key();

    return 0;
}
